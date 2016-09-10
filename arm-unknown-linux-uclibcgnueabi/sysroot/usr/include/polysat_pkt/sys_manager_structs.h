#ifndef SYS_MANAGER_STRUCTS_H
#define SYS_MANAGER_STRUCTS_H

#include <stdint.h>
#include <sys/types.h>
#include <sys/vfs.h>

#define SYS_MGR_OVER_VOLTAGE (1 << 0)
#define SYS_MGR_UNDER_VOLTAGE (1 << 1)
#define SYS_MGR_CHARGE_OVER_CURRENT (1 << 2)
#define SYS_MGR_DISCHARGE_OVER_CURRENT (1 << 3)
#define SYS_MGR_CHARGING_ACTIVE (1 << 4)
#define SYS_MGR_DISCHARGING_ACTIVE (1 << 5)
#define SYS_MGR_CHARGING_ENABLED (1 << 6)
#define SYS_MGR_DISCHARGING_ENABLED (1 << 7)

#define SYS_MGR_BATT_SW_OVERVOLT (1 << 0)
#define SYS_MGR_BATT_SW_UNDERVOLT (1 << 1)
#define SYS_MGR_BATT_SW_DC_CMD (1 << 2)
#define SYS_MGR_BATT_SW_DD_CMD (1 << 3)
#define SYS_MGR_BATT_SW_OV_RECOVERY (1 << 4)
#define SYS_MGR_BATT_SW_CFG_DISABLED (1 << 5)
#define SYS_MGR_BATT_SW_CMD_DISABLED (1 << 6)
#define SYS_MGR_BATT_SW_IGNORED (1 << 7)

#define BATTERY_CMD_ENABLE_CHARGING 1
#define BATTERY_CMD_DISABLE_CHARGING 2
#define BATTERY_CMD_ENABLE_DISCHARGING 3
#define BATTERY_CMD_DISABLE_DISCHARGING 4
#define BATTERY_CMD_POWER_CYCLE 5
#define BATTERY_CMD_RESET_FAULTS 6
#define BATTERY_CMD_ENABLE_BATT 7
#define BATTERY_CMD_ENABLE_BATT_PERSIST 8
#define BATTERY_CMD_IGNORE_BATT 9
#define BATTERY_CMD_IGNORE_BATT_PERSIST 10
#define BATTERY_CMD_DISABLE_BATT 11
#define BATTERY_CMD_DISABLE_BATT_PERSIST 12

struct TempData{
   uint16_t temp; 
} __attribute__((packed));

struct PowerData{
   uint32_t volt; 
   int32_t current; 
} __attribute__((packed));

struct ChargeData {
   uint32_t volt; 
   int32_t current; 
   int32_t currentAccum; 
} __attribute__((packed));

struct BatteryData {
   uint32_t volt; 
   int32_t current; 
   int32_t currentAccum; 
   uint8_t status, swCtrlStatus;
   uint16_t temp; 
} __attribute__((packed));

struct SOCData{
   uint32_t totalCurrentAccum;
   uint32_t maxCurrentAccum;
} __attribute__((packed));

struct BarometerData{
   uint16_t pressure; //Kpa
} __attribute__((packed));

struct MagnetometerData{
   int32_t x; 
   int32_t y; 
   int32_t z; 
} __attribute__((packed));

struct CP9_data{
   struct BarometerData  barometer;
} __attribute__((packed));

struct StandardTelem {
   struct TempData daughter_aTmpSensor;
   struct TempData daughter_bTmpSensor;
   struct PowerData threeVPwrSensor;
   struct BarometerData  barometer;
   struct MagnetometerData test_mag;
} __attribute__((packed));

struct TempStatus{
   struct TempData daughter_aTmpSensor;
   struct TempData daughter_bTmpSensor;
   struct TempData threeV_plTmpSensor;
   struct TempData rf_ampTmpSensor;
   struct TempData boardTempNz;
   struct TempData boardTempNx;
   struct TempData boardTempNy;
   struct TempData boardTempPx;
   struct TempData boardTempPy;
   struct TempData boardTempPz;
} __attribute__((packed));

struct PowerStatus{
   //readings from the various ina power sensors
   struct PowerData atmelPwrSensor;
   struct PowerData threeVPwrSensor;
   struct PowerData threeV_plPwrSensor;
   struct PowerData fiveV_plPwrSensor;
   struct PowerData daughter_aPwrSensor;
   struct PowerData daughter_bPwrSensor;
   struct PowerData sidePanel_3v3;
   struct PowerData sidePanel_5v0;

   struct ChargeData fuelGaugeOne;
   struct ChargeData fuelGaugeTwo;

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

   //State of charge summary
   struct SOCData soc;
} __attribute__((packed));

struct PowerStatus_v2 {
   //readings from the various ina power sensors
   struct PowerData atmelPwrSensor;
   struct PowerData threeVPwrSensor;
   struct PowerData threeV_plPwrSensor;
   struct PowerData fiveV_plPwrSensor;
   struct PowerData daughter_aPwrSensor;
   struct PowerData daughter_bPwrSensor;
   struct PowerData sidePanel_3v3;
   struct PowerData sidePanel_5v0;

   struct ChargeData fuelGaugeOne;
   struct ChargeData fuelGaugeTwo;

   struct BatteryData batteries[16];

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

   //State of charge summary
   struct SOCData soc;
} __attribute__((packed));

struct UsageData{
   //proc/stat info
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
   //proc/meminfo info
   uint32_t memFree;
   uint32_t buffers;
   uint32_t cached;
   uint32_t active;
   uint32_t inactive;
   uint32_t vmallocTotal;
   uint32_t vmallocUsed;
   //stat info
   uint32_t freeDataFlash;
   uint32_t freeSD;
   //proc/net/dev
   uint32_t loRxBytes; 
   uint32_t loRxPkts; 
   uint32_t loRxErrs; 
   uint32_t loTxBytes; 
   uint32_t loTxPkts; 
   uint32_t loTxErrs; 
   //proc/net/dev
   uint32_t nErasedBlocks; 
   uint32_t nPageWrites; 
   uint32_t nErasures; 
} __attribute__((packed));

struct StatusUsageData{
   //proc/stat info
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
   //proc/meminfo info
   uint32_t memFree;
   uint32_t buffers;
   uint32_t cached;
   uint32_t active;
   uint32_t inactive;
   uint32_t vmallocTotal;
   uint32_t vmallocUsed;
   //stat info
   uint32_t freeDataFlash;
   uint32_t freeSD;
} __attribute__((packed));

struct AntennaData{
   uint32_t deployDelay;
   uint32_t dailyDeployDelay;
   uint32_t unmuteDelay;
   uint32_t timeHigh;
   uint32_t deployAttempts;
   uint32_t persistTime;
   uint32_t resetCount;
} __attribute__((packed));

struct BatteryControl {
   uint8_t action;
   uint32_t bitmask;
} __attribute__((packed));

struct BatteryControlResp {
   int32_t result;
} __attribute__((packed));

#endif
