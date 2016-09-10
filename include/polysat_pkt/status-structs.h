#ifndef STATUS_STRUCTS_H
#define STATUS_STRUCTS_H

/**
 * @file status-structs.h Header file for status structures for processes.
 *
 * @author Greg Manyak
 */

#include <stdint.h>
#include <time.h>
#include "sys_manager_structs.h"


/****************************************************************************//*
      Status structure versions 
*******************************************************************************/
///System Manager
#define SYS_STATUS_V1 1
#define SYS_STATUS_V2 2
#define SYS_STATUS_V3 3
#define SYS_STATUS_V4 4
#define SYS_STATUS_V5 5

/// Software Watchdog Timer Structure
struct WDTStatus {
   uint8_t staticWatches;
   uint8_t tempWatchesCurrent;
   uint32_t tempWatchesTotal;
   uint32_t tempWatchKills;
   uint32_t staticWatchKills;
   uint32_t reregisters;
   uint8_t swStateGood;
   int8_t nandState;
} __attribute__((packed));

/// Beacon Structure
struct BeaconStatus {
   uint16_t idleBeaconRate;
   uint16_t activeBeaconRate;
   uint32_t beaconCnt;
} __attribute__((packed));

/// Beacon Structure
struct TelemetryStatus {
   uint32_t snapCnt;
} __attribute__((packed));

//Real time struct 
struct RtcTime{
   uint8_t sec;
   uint8_t min;
   uint8_t hr;
   uint8_t day;
   uint8_t month;
   uint16_t year;
} __attribute__((packed));


//System Manager Structure
struct SMStatus{
   uint8_t version;
   //Temperatures from the various temp sensors
   uint16_t daughter_aTmp;
   uint16_t daughter_bTmp;
   uint16_t threeV_plTmp;
   uint16_t rf_ampTmp;

   //readings from the various ina power sensors
   int32_t atmelPwrCurr;
   uint32_t atmelPwrShuntV;
   uint16_t atmelPwrBusV;
   uint32_t atmelPwrPwr;
   int32_t threeV_PwrCurr;
   uint32_t threeV_PwrShuntV;
   uint16_t threeV_PwrBusV;
   uint32_t threeV_PwrPwr;
   int32_t threeV_plPwrCurr;
   uint32_t threeV_plPwrShuntV;
   uint16_t threeV_plPwrBusV;
   uint32_t threeV_plPwrPwr;
   int32_t fiveV_plPwrCurr;
   uint32_t fiveV_plPwrShuntV;
   uint16_t fiveV_plPwrBusV;
   uint32_t fiveV_plPwrPwr;
   int32_t daughter_aPwrCurr;
   uint32_t daughter_aPwrShuntV;
   uint16_t daughter_aPwrBusV;
   uint32_t daughter_aPwrPwr;
   int32_t daughter_bPwrCurr;
   uint32_t daughter_bPwrShuntV;
   uint16_t daughter_bPwrBusV;
   uint32_t daughter_bPwrPwr;

   //Barometer readings
   uint16_t pressure;
   
   //Battery monitor readings - for LS only
   int32_t batMonOneCurr;
   uint32_t batMonOneCurrAcc;
   uint16_t batMonOneVolt;
   uint16_t batMonOneTmp;
   int32_t batMonTwoCurr;
   uint32_t batMonTwoCurrAcc;
   uint16_t batMonTwoVolt;
   uint16_t batMonTwoTmp;
   int32_t batMonThreeCurr;
   uint32_t batMonThreeCurrAcc;
   uint16_t batMonThreeVolt;
   uint16_t batMonThreeTmp;
   int32_t batMonFourCurr;
   uint32_t batMonFourCurrAcc;
   uint16_t batMonFourVolt;
   uint16_t batMonFourTmp;
   int32_t batMonFiveCurr;
   uint32_t batMonFiveCurrAcc;
   uint16_t batMonFiveVolt;
   uint16_t batMonFiveTmp;
   int32_t batMonSixCurr;
   uint32_t batMonSixCurrAcc;
   uint16_t batMonSixVolt;
   uint16_t batMonSixTmp;
   int32_t batMonSevenCurr;
   uint32_t batMonSevenCurrAcc;
   uint16_t batMonSevenVolt;
   uint16_t batMonSevenTmp;
   int32_t batMonEightCurr;
   uint32_t batMonEightCurrAcc;
   uint16_t batMonEightVolt;
   uint16_t batMonEightTmp;

   // New System Board Fuel Gauge Sensors
   // Battery board currently supports up to 4 cells
   int32_t fuelGaugeOneVolt;
   int32_t fuelGaugeOneCurr;

   int32_t fuelGaugeTwoVolt;
   int32_t fuelGaugeTwoCurr;

   int32_t fuelGaugeThreeVolt;
   int32_t fuelGaugeThreeCurr;

   int32_t fuelGaugeFourVolt;
   int32_t fuelGaugeFourCurr;

   //System management readings
   uint32_t dString;
   uint32_t dUInt;
   uint32_t userTime;
   uint32_t lpUserTime;
   uint32_t sysTime;
   uint32_t idleTime;
   uint32_t pageIn;
   uint32_t pageOut;
   uint32_t swapIn;
   uint32_t swapOut;
   uint32_t intr;
   uint32_t ctxt;
   uint32_t btime;
   uint32_t processes;
   uint32_t procs_running;
   uint32_t procs_blocked;

   //RTC struct
   struct RtcTime rtc_time;

} __attribute__((packed));

struct SMStatus_v2{
   uint8_t version;
   //Temperatures from the various temp sensors
   struct TempData daughter_aTmpSensor;
   struct TempData daughter_bTmpSensor;
   struct TempData threeV_plTmpSensor;
   struct TempData rf_ampTmpSensor;

   //readings from the various ina power sensors
   struct PowerData atmelPwrSensor;
   struct PowerData threeVPwrSensor;
   struct PowerData threeV_plPwrSensor;
   struct PowerData fiveV_plPwrSensor;
   struct PowerData daughter_aPwrSensor;
   struct PowerData daughter_bPwrSensor;

   struct PowerData bat_mon_1;
   struct PowerData bat_mon_2;
   struct PowerData bat_mon_3;
   struct PowerData bat_mon_4;
   struct PowerData bat_mon_5;
   struct PowerData bat_mon_6;
   struct PowerData bat_mon_7;
   struct PowerData bat_mon_8;

   struct ChargeData fuelGaugeOne;
   struct ChargeData fuelGaugeTwo;
   struct ChargeData fuelGaugeThree;
   struct ChargeData fuelGaugeFour;

   struct BarometerData barometer;

   //System management readings
   struct UsageData usage;

   //RTC struct
   struct RtcTime rtc_time;

} __attribute__((packed));

/**
* system manager status structure v3:
*  - Removed bat_mon fields
*  - Include voltage, current, and current acculm values for all
*    fuel gauge sensors
*  - Include a SOC summary. This is both absolute sum of current
*    across all batteries and percentage of total capacity*/
struct SMStatus_v3{
   uint8_t version;
   //Temperatures from the various temp sensors
   struct TempData daughter_aTmpSensor;
   struct TempData daughter_bTmpSensor;
   struct TempData threeV_plTmpSensor;
   struct TempData rf_ampTmpSensor;
   struct TempData tempNz;
   struct TempData tempPz;
   struct TempData tempNx;
   struct TempData tempPx;
   struct TempData tempNy;
   struct TempData tempPy;

   //readings from the various ina power sensors
   struct PowerData atmelPwrSensor;
   struct PowerData threeVPwrSensor;
   struct PowerData threeV_plPwrSensor;
   struct PowerData fiveV_plPwrSensor;
   struct PowerData daughter_aPwrSensor;
   struct PowerData daughter_bPwrSensor;

   struct ChargeData fuelGaugeOne;
   struct ChargeData fuelGaugeTwo;
   struct PowerData sidePanel3v3;
   struct PowerData sidePanel5v0;
   
   struct PowerData solar2PwrNz;
   struct PowerData solar2PwrNx;
   struct PowerData solar2PwrNy;
   struct PowerData solar2PwrPx;
   struct PowerData solar2PwrPy;
   struct PowerData solar2PwrPz;

   struct PowerData solar1PwrNz;
   struct PowerData solar1PwrNx;
   struct PowerData solar1PwrNy;
   struct PowerData solar1PwrPx;
   struct PowerData solar1PwrPy;
   struct PowerData solar1PwrPz;

   struct BarometerData barometer;

   //State of charge summary
   struct SOCData soc;

   //System management readings
   struct StatusUsageData usage;

   //Unix time
   uint32_t unix_time; 

   //Long duration timer
   uint16_t LDC;
} __attribute__((packed));

/**
* system manager status structure v4:
*  - Added fields for 3rd power sensor on x & y panels
*/
struct SMStatus_v4 {
   uint8_t version;
   //Temperatures from the various temp sensors
   struct TempData daughter_aTmpSensor;
   struct TempData daughter_bTmpSensor;
   struct TempData threeV_plTmpSensor;
   struct TempData rf_ampTmpSensor;
   struct TempData tempNz;
   struct TempData tempPz;
   struct TempData tempNx;
   struct TempData tempPx;
   struct TempData tempNy;
   struct TempData tempPy;

   //readings from the various ina power sensors
   struct PowerData atmelPwrSensor;
   struct PowerData threeVPwrSensor;
   struct PowerData threeV_plPwrSensor;
   struct PowerData fiveV_plPwrSensor;
   struct PowerData daughter_aPwrSensor;
   struct PowerData daughter_bPwrSensor;

   struct ChargeData fuelGaugeOne;
   struct ChargeData fuelGaugeTwo;
   struct PowerData sidePanel3v3;
   struct PowerData sidePanel5v0;
   
   struct PowerData solar3PwrNx;
   struct PowerData solar3PwrNy;
   struct PowerData solar3PwrPx;
   struct PowerData solar3PwrPy;

   struct PowerData solar2PwrNz;
   struct PowerData solar2PwrNx;
   struct PowerData solar2PwrNy;
   struct PowerData solar2PwrPx;
   struct PowerData solar2PwrPy;
   struct PowerData solar2PwrPz;

   struct PowerData solar1PwrNz;
   struct PowerData solar1PwrNx;
   struct PowerData solar1PwrNy;
   struct PowerData solar1PwrPx;
   struct PowerData solar1PwrPy;
   struct PowerData solar1PwrPz;

   struct BarometerData barometer;

   //State of charge summary
   struct SOCData soc;

   //System management readings
   struct StatusUsageData usage;

   //Unix time
   uint32_t unix_time; 

   //Long duration timer
   uint16_t LDC;
} __attribute__((packed));

/**
* system manager status structure v5:
*  - Updated information for battery cell level details
*/
struct SMStatus_v5 {
   uint8_t version;
   //Temperatures from the various temp sensors
   struct TempData daughter_aTmpSensor;
   struct TempData daughter_bTmpSensor;
   struct TempData threeV_plTmpSensor;
   struct TempData rf_ampTmpSensor;
   struct TempData tempNz;
   struct TempData tempPz;
   struct TempData tempNx;
   struct TempData tempPx;
   struct TempData tempNy;
   struct TempData tempPy;

   //readings from the various ina power sensors
   struct PowerData atmelPwrSensor;
   struct PowerData threeVPwrSensor;
   struct PowerData threeV_plPwrSensor;
   struct PowerData fiveV_plPwrSensor;
   struct PowerData daughter_aPwrSensor;
   struct PowerData daughter_bPwrSensor;

   struct ChargeData fuelGaugeOne;
   struct ChargeData fuelGaugeTwo;

   struct BatteryData batteries[8];
   struct PowerData sidePanel3v3;
   struct PowerData sidePanel5v0;
   
   struct PowerData solar3PwrNx;
   struct PowerData solar3PwrNy;
   struct PowerData solar3PwrPx;
   struct PowerData solar3PwrPy;

   struct PowerData solar2PwrNz;
   struct PowerData solar2PwrNx;
   struct PowerData solar2PwrNy;
   struct PowerData solar2PwrPx;
   struct PowerData solar2PwrPy;
   struct PowerData solar2PwrPz;

   struct PowerData solar1PwrNz;
   struct PowerData solar1PwrNx;
   struct PowerData solar1PwrNy;
   struct PowerData solar1PwrPx;
   struct PowerData solar1PwrPy;
   struct PowerData solar1PwrPz;

   struct BarometerData barometer;

   //State of charge summary
   struct SOCData soc;

   //System management readings
   struct StatusUsageData usage;

   //Unix time
   uint32_t unix_time; 

   //Long duration timer
   uint16_t LDC;
   uint32_t deployable_state;
} __attribute__((packed));


struct tester {
   uint32_t dUInt;
} __attribute__((packed));

/// Satellite Communication Structure
#define SATCOM_STATUS_NUM_CALLSIGNS 8
struct SatComCallsignInfo {
   char callsign[7];
   int8_t lastRssi;
   time_t lastRx;
   uint32_t rxCnt;
   uint32_t txCnt;
} __attribute__((packed));

struct SatComStatus {
   uint32_t rxCount;
   uint32_t rxBytes;
   uint32_t txCount;
   uint32_t txBytes;
   uint32_t dropCount;
   uint32_t authFailures;
   time_t lastRx;
   time_t lastTx;
   uint32_t ax25RxCount;
   uint32_t ax25RxBytes;
   uint32_t ax25TxCount;
   uint32_t ax25TxBytes;
   uint32_t cpl2RxCount;
   uint32_t cpl2RxBytes;
   uint32_t cpl2TxCount;
   uint32_t cpl2TxBytes;
   uint16_t digipeatsPerHour;
   uint16_t digipeatsRemaining;
   uint32_t digipeatCnt;
   uint32_t rejDigipeatCnt;
   int8_t rxRssi;
   uint32_t multicastDropPkts;
   uint32_t broadcastDropPkts;
   struct SatComCallsignInfo lastCallsigns[SATCOM_STATUS_NUM_CALLSIGNS];
   uint8_t flags;
} __attribute__((packed));

#define SATCOM_FLAG_SQUELCHED 0x01
#define SATCOM_FLAG_INHIBIT1 0x02
#define SATCOM_FLAG_INHIBIT2 0x04

// Datalogger Status Structure
struct DLStatus {
   uint32_t count;
   uint32_t rate;
   uint32_t ops_mode;
} __attribute__((packed));

#define ADCS_CTL_NONE 0
#define ADCS_CTL_BDOT 1
#define ADCS_CTL_PD 2
#define ADCS_CTL_DAMPENING 3
#define ADCS_CTL_KF_ON 0x10
#define ADCS_CTL_MAGS_ON 0x20
#define ADCS_CTL_MAGS_LOCKED 0x40
#define ADCS_CTL_WHEEL_ON 0x80

// ADCS Status
struct ADCSStatus {
   uint16_t version;
   uint32_t count;
   uint32_t pos_tv_sec;
   uint32_t pos_tv_usec;
   int32_t latitude;  // 9.23
   int32_t longitude; // 9.23
   uint32_t altitude; // in meters
   int32_t degOffX; // 9.23
   int32_t degOffY; // 9.23
   int32_t degOffZ; // 9.23
   int32_t wheelSpeed; // 24.8
   int32_t wheelAccel; // 9.23
   int32_t targetWheelSpeed;
   int32_t targetWheelAccel;
   uint32_t tle_epoch;
   uint8_t ctrlMode;
   uint8_t wheelDeltaErrCnt;
   uint32_t wheelLifetimeErrs;
   uint32_t wheelInstanceErrs;
   uint32_t wheelInstances;
   uint8_t activeMags;
   uint8_t passiveMags;
   uint8_t activeSols;
   uint8_t passiveSols;
} __attribute__((packed));

struct ClkSyncStatus {
   uint32_t offset_sec;
   uint32_t offset_usec;
   int32_t curr_rtc;        // the RTC reading for which this rsp was constructed
   int32_t vrtc_freq;       // frequency difference between RTC and VRTC
   int32_t vrtc_offset;     // offset between RTC and VRTC
   int32_t sysclk_freq;     // exponential moving average of drift calculations
   int32_t sysclk_offset;   // exponential moving average of offset measurments
   uint32_t sysclk_secs;
   uint32_t sysclk_usecs;
   uint32_t offset_id;
} __attribute__((packed));

#endif
