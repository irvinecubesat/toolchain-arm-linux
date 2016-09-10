/**
  * @file barometer.h Barometer sensor header
  *
  * Hardware abstraction for barometer sensor
  *
  * @author Edmund Yee <ey7180@gmail.com>
  */

#ifndef __BAROMETER_H__
#define __BAROMETER_H__

/*---------------------------------------------------------------------------*/
/*                              #includes                                    */
/*---------------------------------------------------------------------------*/

#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdint.h>
#include <polysat/polysat.h>
#include "../driverdb.h"

/*
   Function Declarations
*/

struct BarometerSensor;

typedef void (*barometer_completion_cb)(struct BarometerSensor *sensor, uint16_t *pascal, void *opaque);

struct BarometerSensor {
   struct Sensor sensor;
   uint16_t temperatureCache;
   uint16_t pressureCache;

/**
  * Reads the temperature and returns value in standard PolySat fixed-point temperature format
  *
  * @param tempCel variable to write celsius value to
  * @param sensor sensor to be read from
  *
  * @return error code
  *
  * @retval -1 failure and errno is set
  * @retval 0 success
  */
  int (*read_temperature)(struct BarometerSensor *sensor, uint16_t *tempKOut);

/**
  * Reads from the sensor and calculate the compensated pressure.  This method
  *  blocks.  It should be avoided where possible.
  *
  * @param pascal variable ot write pascal value to
  * @param sensor sensor to be read from
  *
  * @return error code
  *
  * @retval -1 faillure and errno is set
  * @retval 0 success
  */
  int (*blocking_read)(struct BarometerSensor *sensor, uint16_t *pascal);

/**
  * Reads from the sensor and calculate the compensated pressure.  This
  *  is an async method with completion callback.  Use this in all event
  *  driven programs.
  *
  * @param pascal variable ot write pascal value to
  * @param sensor sensor to be read from
  *
  * @return error code
  *
  * @retval -1 faillure and errno is set
  * @retval 0 success
  */
  int (*async_read)(struct BarometerSensor *sensor, uint16_t *pascal, EVTHandler *event_loop, barometer_completion_cb cb, void *cb_opaque_param);

};


struct BarometerSensor *create_barometer_device(struct DeviceInfo *dev,
    struct GPIOSensor *enable_gpio);

/**
  * Reads from the sensor and returns temperature within range -40C to 105C
  *
  * @param tempCelsius variable to write temperature value to
  * @param sensor sensor to be read from
  *
  * @return error code
  *
  * @retval -1 faillure and errno is set
  * @retval 0 success
  */
// int barometer_read_temperature_celsius(signed short *celsius, void *sensor);

int barometer_debug_dump(struct Sensor *sensor);

#endif
