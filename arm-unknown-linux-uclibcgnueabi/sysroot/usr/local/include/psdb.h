#ifndef PSDB_H
#define PSDB_H

#include "sqlite3.h"
#include <time.h>

#ifdef ARM
   //#define DB_NAME (const char*)"/sdcard/CubeSatDB.sqlite"
   #define DB_NAME (const char*)"/data/CubeSatDB.sqlite"
   //#define DB_NAME (const char*)"/data/tvac/CubeSatDB.sqlite"
#else
   #define DB_NAME (const char*)"./CubeSatDB.sqlite"
#endif

#define BIG_TABLE "sensortable"
#define LOC_NAMES "locnames"
#define SENSOR_NAMES "sensors"
#define GROUP_NAMES "groupnames"
#define GROUPS "groups"
#define LOCATIONS "locations"
#define EVENTS_TABLE "events"
#define TABLE_WIDTH 5
#define TIMESTAMP_LENGTH 20
#define LOCATION 1
#define GROUP 2
#define SENSOR 3
// Maximum number of integers to be used for db version
#define EXTENSION ".sqlite"
#define ATTEMPT_CREATE 2

/* error codes for PolySat database */
#define ERR_NONE 0x00
#define EMPTY_SET 0x01
#define UNEXPECTED_RESULT 0x02
#define BAD_INPUT 0x03
#define SQL_ERR_STEP 0x04
#define SQL_ERR_BIND 0x05
#define SQL_ERR_PREP 0x06
#define SQL_ERR_OPEN 0x07
#define SQL_ERR_CLOSE 0x0C
#define SQL_ERR_RESET 0x08
#define DUP_ENTRY 0x09
#define ADD_LOC_ERR 0x0A
#define ADD_GROUP_ERR 0x0B
#define USAGE_ERR 0x0C

/*Indexing for statements/character strings*/
#define createSensorTable 0
#define createSensorNames 1
#define createLocationNames 2
#define createGroupNames 3
#define createGroups 4
#define createLocations 5
#define dropSensorTable 6
#define dropSensorNames 7
#define dropLocationNames 8
#define dropGroupNames 9
#define dropGroups 10
#define dropLocations 11
#define getRecGroup 12
#define getGWindow 13
#define getRecentGroupValues 14
#define getRecLocation 15
#define getLWindow 16
#define getRecentLocationValues 17
#define getRecSensor 18
#define getSWindow 19
#define getRecentSensorValues 20
#define findHighGroupID 21
#define findHighSensorID 22
#define findHighLocationID 23
#define findGroupName 24
#define findSensorName 25
#define findLocationName 26
#define findLocationID 27
#define findGroupID 28
#define storeValue 29
#define storeGroup 30
#define storeLocation 31
#define storeSensor 32
#define storeGroupKey 33
#define storeLocationKey 34
#define countRecGroup 35
#define countGWindow 36
#define countRecentGroupValues 37
#define countRecLocation 38
#define countLWindow 39
#define countRecentLocationValues 40
#define countRecSensor 41
#define countSWindow 42
#define countRecentSensorValues 43
#define beginStatement 44
#define commitStatement 45
#define rollbackStatement 46
#define dummyWriteStatement 47
#define oldestDatapointStatement 48
#define deleteDatapointsStatement 49
#define pageCountPragma 50
#define pageSizePragma 51
#define freeListCountPragma 52
#define integrityCheckPragma 53
#define createEventsTable 54
#define dropEventsTable 55
#define storeEventSQL 56
#define numSQLStrings 57

#define DBConnection sqlite3*

/**
 * \struct DBName_id
 * this struct is used to house a key for either a sensor, group, or location
 * entry in the database
 */
typedef struct s_id{
  int id;
} DBName_id;

/**
 * \struct DBCommands
 * this struct holds an array of sql statements that the API will maintain
 * based on what functions are called.  Before termination, the process should
 * make a call to free_db() which finalizes all compiled statements within
 * this struct
 */
typedef struct s_commands{
 
  sqlite3_stmt *preparedStatements[numSQLStrings];
  
} DBCommands;

/**
 * \struct DBResult
 * this struct will hold a single member of the result set from any of this
 * APIs queries.  Arrays of these structs should be provided in the parameters
 * for the quries.  The query will populate its array with all it's results.
 * The caller is responsible for freeing that array's contents with a call to 
 * free()
 **/
typedef struct s_result{
  
  int sensKey;                       /* sensor ID */
  double value;                      /* the reading */
  unsigned char timestamp[TIMESTAMP_LENGTH];          /* the timestamp */
  
} DBResult;

/**
 * \struct DBResults
 * this struct holds an array of DBResult structures, and the count indicating
 * how many results are present
 **/
typedef struct s_results{
  int count;
  DBResult *results;
} DBResults;

/**
 * open_psdb opens a connection to an sqlite3 database.  This function
 * must be called before this API's other functions can be used.
 **/
char open_psdb(void);

/**
 * close_psdb closes the current connection to the sqlite3 database.
 * This should be called by a process which no longer requires the
 * database, and in almost all cases should be preceded with a call
 * to free_db()
 **/
char close_psdb(void);

/**
 * free_db finalizes all statements which have been compiled as a result
 * of function calls from this API.  This function should be called before
 * the calling process terminates, in order to free memory
 */
char free_db(void);

/**
 * construct creates all database tables required to support this API,
 * and is likely to be called by only one process
 **/
char construct(void);

/**
 * destruct will remove all tables (and their data) from the database.
 **/
char destruct(void);

/**
 * getRecent will obtain all results with the most current timestamp.  This query
 * can be performed for a particular sensor, group or location
 * @param selection tells us what sensor/group/location we're querying for
 * @param results double pointer to a DBResults struct
 * @param gls either SENSOR, GROUP, or LOCATION
 **/
char getRecent(DBName_id *selection, DBResults **results, int gls);

/**
 * getWindow will obtain all results within a time-window spanning from lowerbound to upperbound.
 * This query is performed on a particular sensor/group/location.
 * @param lowerbound timestamp 'YYYY-MM-DD HH:MM:SS' designating beginning of time window.
 * @param upperbound timestamp 'YYYY-MM-DD HH:MM:SS' designating end of time window.
 * @param selection tells us what sensor/group/location we're querying for
 * @param results double pointer to a DBResults struct to populate with results
 * @param gls either SENSOR, GROUP, or LOCATION
 **/
char getWindow(char *lowerbound, char *upperbound, DBName_id *selection, DBResults **results, int gls);

/**
 * getNumRecent will obtain the n most recent results.  This query is performed on a particular group,
 * sensor, or location
 * @param selection designates what sensor/group/location we're querying for
 * @param num how many results to obtain
 * @param results double pointer to a DBResults struct to populate
 * @param gls either GROUP, LOCATION or SENSOR
 **/
char getNumRecent(DBName_id *selection, int num, DBResults **results, int gls);

char cleanupResults(DBResults **results);


/**
 * storeSensorValues will store multiple values from a sensor
 * @param sensor array of sensor pointers who's values are to be stored
 * @param val the collection of values to store
 * @param timestamp the timestamp which corresponds to these readings
 * @param num how many readings there are to store
 **/
char storeSensorValues(DBName_id **sensor, double* val, char timestamp[TIMESTAMP_LENGTH], int num);

/**
 * storeSensorValue stores a single value for a sensor
 * @param sensor pointer to the sensor who's value will be stored
 * @param val the value to store
 * @param timestamp the timestamp which corresponds to this reading
 **/
char storeSensorValue(DBName_id *sensor, double val, char timestamp[TIMESTAMP_LENGTH]);

/**
 * storeIntSensorValue stores a single integer value for a sensor
 * @param sensor pointer to the sensor who's value will be stored
 * @param val the value to store
 * @param timestamp the timestamp which corresponds to this reading
 **/
char storeIntSensorValue(DBName_id *sensor, int val, char timestamp[TIMESTAMP_LENGTH]);

/**
 * storeEvent stores a event, including event_num and description, into the db
 * @param proc_num The ID of the process that generated the event
 * @param event_num The enumerated number of the event that occured
 * @param description An ASCII description of the event
 * @param timestamp the timestamp which corresponds to this event
 **/
char storeEvent(int proc_num, int event_num, const char *description,
      char timestamp[TIMESTAMP_LENGTH]);

/**
 * create instantiates a new group or location classification in the database.
 * @param name what the name of this group or location will be
 * @param group the DBName_id in which to store this group or location's key
 * @param type should be either GROUP or LOCATION
 **/
char create(char *name, DBName_id *group, int type);

/**
 * create_sensor instantiates a new sensor in the database
 * @param name the name of this sensor
 * @param location the location of this sensor
 * @param groups an array of pointers to DBName_ids of groups this sensor belongs to
 * @param sensor the DBName_id in which to store this sensor's key
 **/
char create_sensor(char *name, DBName_id *location, DBName_id **groups, int numGroups, DBName_id *sensor);

/**
 * begin_transaction Explicitly start a new transaction.  Previous transaction must be committed or rolled back before calling begin.
 **/
char begin_transaction();

/**
 * commit_transaction Explicitly commit a transaction.
 **/
char commit_transaction();

/**
 * rollback_transaction Explicitly abort a transaction.
 **/
char rollback_transaction();

/**
  * opens db with specified name
  */
char open_psdb_with_name(const char *dbName);

/**
 * does a dummy write on the database
 */
char dummyWrite();

/**
 * Returns the full path name for the open database
 */
const char *psdb_db_path();

/**
 * Returns unix epoch time, via an out parameter, of the oldest data record
 *  in the database
 */
char oldest_datapoint(time_t *resultOut);

/**
 * Deletes telemetry points from the database that are older than the parameter
 *  passed in
 */
char remove_data_points(time_t older_than);

/**
 * Returns total database page count.
 */
char psdb_page_count(int *resultOut);

/**
 * Returns database page size.
 */
char psdb_page_size(int *resultOut);

/**
 * Returns number of pages on the free list.
 */
char psdb_free_list_count(int *resultOut);

/**
 * Returns "ok" if the database passed structural integrity test
 */
char psdb_integrity_check();

#endif
