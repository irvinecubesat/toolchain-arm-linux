/**
 *  @file solar_angle_sensor.h 
 *
 *  @author Robby Tong <robwasab@gmail.com>
 */

#ifndef __SOLAR_DRIVER_H__ 
#define __SOLAR_DRIVER_H__

/*---------------------------------------------------------------------------*/
/*                      #includes                                            */
/*---------------------------------------------------------------------------*/
#include <stdint.h>
#include "../driverdb.h"

//REGISTER addresses

/*---------------------------------------------------------------------------*/
/*                       Function Declarations                               */
/*---------------------------------------------------------------------------*/

#define NOT_READY 2
#define BLUE 0
#define RED 1
#define TEMP 2

typedef struct solar_sensor_data_struct{
   int32_t x;
   int32_t y;
   int32_t z;
   int32_t intensity;
} sun_sensor_data;

//SolarAngleSensor is a Sensor

struct SolarAngleSensor {
  struct Sensor sensor;
  sun_sensor_data solarCache;
  //abstract methods for a typical Solar Angle Sensor
  int (*read)(struct SolarAngleSensor *sensor, sun_sensor_data *data);
  int (*read_raw)(struct SolarAngleSensor *sensor, uint16_t *a1, uint16_t *a2);
};

extern struct SolarAngleSensor * create_solar_angle_device(
     struct DeviceInfo *dev, struct GPIOSensor *enable_gpio);
extern int generic_solar_angle_debug_dump(struct Sensor *sensor);

#endif

