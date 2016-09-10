/**
 *  @file temp.h Temperature sensor header
 *
 *  Hardware abstraction for temperature sensor.
 *
 *  @author Greg Manyak <gregmanyak@gmail.com>
 *  @author Dominic Bertolino <db11289@gmail.com> 
 */

#ifndef __GPIO_H__ 
#define __GPIO_H__


/*---------------------------------------------------------------------------*/
/*                       #includes                                           */
/*---------------------------------------------------------------------------*/
#include <stdint.h>
#include "../driverdb.h"

/*---------------------------------------------------------------------------*/
/*                       Function Declarations                               */
/*---------------------------------------------------------------------------*/

struct GPIOSensor {
   struct Sensor sensor;
   struct DeviceInfo *dev_info;
   int activeCached;
   int (*read)(struct GPIOSensor *sensor);
   int (*set)(struct GPIOSensor *sensor, int active);
};

/**
 *  Inits a gpio sensor. Struct with initialized device info is returned
 * 
 *  @param dev  the DeviceInfo for the sensor to init
 *
 *  @return Pointer or Null
 *
 *  @retval  pointer to GPIOSensor struct if successful
 *  @retval  NULL on failure
 */
struct GPIOSensor *create_gpio_device(struct DeviceInfo *dev);

/**
 *  Inits a gpio sensor with a given name. The driver database is searched for
 *   a matching GPIO sensor name, and the sensor is created if found.
 * 
 *  @param name  the name of the sensor to initialize
 *
 *  @return GPIOSensor pointer or Null
 *
 *  @retval  pointer to GPIOSensor struct if successful
 *  @retval  NULL on failure
 */
struct GPIOSensor *create_named_gpio_device(const char *name);

#endif
