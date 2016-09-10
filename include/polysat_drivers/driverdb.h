#ifndef DRIVERDB_H
#define DRIVERDB_H

#include <stdint.h>
#include <polysat/polysat.h>
#include <sys/time.h>

#define DRVR_CLS_TEMPERATURE "temperature"
#define DRVR_CLS_MAGNETOMETER "magnetometer"
#define DRVR_CLS_POWER "power"
#define DRVR_CLS_BAROMETER "barometer"
#define DRVR_CLS_LED_DRIVER "led_driver"
#define DRVR_CLS_GYROSCOPE "gyroscope"
#define DRVR_CLS_MAGNETORQUER "magnetorquer"
#define DRVR_CLS_GPIO "gpio"
#define DRVR_CLS_ADC "adc"
#define DRVR_CLS_SOLAR_ANGLE "solar_angle"
#define DRVR_CLS_REACTION_WHEEL "reaction_wheel"
#define DRVR_CLS_MULTI "multifunction"
#define DRVR_CLS_ACCELEROMETER "accelerometer"
#define DRVR_CLS_CHARGE_CONTROLLER "charge_controller"
#define DRVR_CLS_GPS "gps"

#define DEVICE_LOCATION_MB "mb"
#define DEVICE_LOCATION_PAYLOAD_IB "pib"
#define DEVICE_LOCATION_DAUGHTER_B "dbb"
#define DEVICE_LOCATION_DAUGHTER_A "dba"
#define DEVICE_LOCATION_MINUS_X "-x"
#define DEVICE_LOCATION_MINUS_Y "-y"
#define DEVICE_LOCATION_MINUS_Z "-z"
#define DEVICE_LOCATION_PLUS_X "+x"
#define DEVICE_LOCATION_PLUS_Y "+y"
#define DEVICE_LOCATION_PLUS_Z "+z"
#define DEVICE_LOCATION_BOOM1 "boom1"
#define DEVICE_LOCATION_BOOM2 "boom2"
#define DEVICE_LOCATION_TEST "test"

#define DRIVER_SUCCESS 0
#define DRIVER_ERROR -1

struct GPIOSensor;

struct DeviceInfo {
   const char *drvr_class;
   const char *drvr_name;
   const char *location;
   const char *description;
   const char *name;
   const char *gpio_enable_name;
   const char *gpio_enable_location;
   int x, y, z; // Position in satellite.  Units in micrometers
   int x_deg, y_deg, z_deg; // mounting offset in satellite,  Units in tenths of degrees
   uint8_t inv_x, inv_y, inv_z;
   float transform[4][4];
   int device_id;
   const char *eeprom_path;
   uint32_t cache_duration_ms;
};

struct Sensor {
   struct DeviceInfo *dev_info;
   struct GPIOSensor *enable_gpio;
   int enabled;
   int (*close)(struct Sensor**);
   int (*self_check)(struct Sensor*);
   int (*debug_dump)(struct Sensor*);
   int (*update_cached_values)(struct Sensor *sensor, struct timeval *now);
   int (*enable_sensor)(struct Sensor*);
   int (*disable_sensor)(struct Sensor*);
   int (*program_address)(struct Sensor *sensor);
};

struct xyz {
   float x;
   float y;
   float z;
};

// first pass NULL
// next, pass previous return
// struct DeviceInfo *curr = NULL;
// while ((curr = enumerate_devices(curr, drvr_class, location))) {};
struct DeviceInfo *enumerate_devices(struct DeviceInfo *start,
   const char *drvr_class, const char *location);

struct Sensor *create_device(struct DeviceInfo *devInfo);

struct HardwareID {
   uint8_t hwRevision, batchNumber;
   uint16_t vendorID, productID;
   uint32_t serialNumber;
   char vendorStr[18], productStr[18];
};

extern struct HardwareID *hardware_id_for_device(struct DeviceInfo *devInfo);
extern uint32_t uhf_calibration_for_device(struct DeviceInfo *devInfo);
extern int update_cached_values(struct Sensor *sensor);

#define EEPROM_FILE_TYPE_NONE 0
#define EEPROM_FILE_TYPE_PRIVATE 1
#define EEPROM_FILE_TYPE_UHF_CALIBRATION 2
#define EEPROM_FILE_TYPE_DETAILED_DESCRIPTION 3
#define EEPROM_FILE_TYPE_DRIVER_CONFIG_V1 4

void sensor_to_body(struct DeviceInfo *dev, int32_t x, int32_t y, int32_t z, struct xyz *val);

void *config_region_for_device(struct DeviceInfo *devInfo,
      int eepromFileType, int *lenOut);

#endif
