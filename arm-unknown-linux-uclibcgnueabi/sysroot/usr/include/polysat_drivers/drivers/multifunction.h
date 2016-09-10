/**
 *  @file power.h 
 *
 *  @author Greg Manyak <gregmanyak@gmail.com>
 *  @author Dominic Bertolino <db11289@gmail.com> 
 *
 */

#ifndef __MULTIFUNCTION_H__ 
#define __MULTIFUNCTION_H__



/*---------------------------------------------------------------------------*/
/*                      #includes                                            */
/*---------------------------------------------------------------------------*/
#include <stdint.h>
#include "../driverdb.h"


/*---------------------------------------------------------------------------*/
/*                       Function Declarations                               */
/*---------------------------------------------------------------------------*/

struct MagnetometerSensor;
struct AccelerometerSensor;

struct MultifunctionSensor {
   struct Sensor sensor;
};

extern struct MultifunctionSensor *create_multifunction_device(
         struct DeviceInfo *dev, struct GPIOSensor *enable_gpio);
extern struct MagnetometerSensor *multifunction_get_magnetometer_device(
         struct DeviceInfo *dev);
extern struct AccelerometerSensor *multifunction_get_accelerometer_device(
         struct DeviceInfo *dev);

#endif
