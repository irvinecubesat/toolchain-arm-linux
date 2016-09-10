#ifndef GPS_H
#define GPS_H

#include <stdint.h>
#include "../driverdb.h"

#define MAX_DATA 500

#define GPS_NO_LOCK 1
#define GPS_2D_LOCK 2
#define GPS_3D_LOCK 3

#define GPS_DATA_INVALID 0
#define GPS_DATA_VALID 1

#define GPS_NOT_BOOTED 0
#define GPS_BOOTED 1

#define gps_set_logfile_fd(gps, fd) gps->log_file_fd = fd;

struct VirtualGPSConfig {
   char *test_data_path;
};

typedef struct GPSData {
   unsigned int day, mon, year;
   unsigned char hours, mins, secs, m_secs;
   int num_sats, lock_type, data_valid;
   double lat, log;
   double hdop, vdop, pdop, alt;
} GPSData;

typedef void (*gpsCB)(GPSData *data);

struct GPSSensor {
   struct Sensor sensor;
   GPSData gpsCache;

   /**
    * Stores the state of the boot GPS sensor,
    * booted or unbooted. Used for determining if
    * we can send commands to the GPS.
    */
   int boot_state;

   /**
    * Used for testing GPS.
    * If set, raw GPS data will be written
    * to the specified file descriptor.
    */
   int log_file_fd;

   gpsCB callbackUser;
   int (*event_gps_add)(struct GPSSensor *sensor, struct EventState *evt, gpsCB gpsCallback);
   int (*event_gps_remove)(struct GPSSensor *sensor);
};

struct GPSSensor *create_gps_device(struct DeviceInfo *dev, struct GPIOSensor *enable_gpio);

#endif
