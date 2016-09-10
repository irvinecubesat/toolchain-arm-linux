/**
 *  @file power.h 
 *
 *  @author Greg Manyak <gregmanyak@gmail.com>
 *  @author Dominic Bertolino <db11289@gmail.com> 
 *
 */

#ifndef __ACCELEROMETER_H__ 
#define __ACCELEROMETER_H__



/*---------------------------------------------------------------------------*/
/*                      #includes                                            */
/*---------------------------------------------------------------------------*/
#include <stdint.h>
#include "../driverdb.h"


/*---------------------------------------------------------------------------*/
/*                       Function Declarations                               */
/*---------------------------------------------------------------------------*/

// These readings are expressed in Gs (8/24 fixed point) units
typedef struct ACCEL_DATA{
   int32_t x_result;
   int32_t y_result;
   int32_t z_result;
} AccelData;

struct AccelerometerSensor {
   struct Sensor sensor;
   AccelData accelCache;
   /**
    *  Gets the all three axis measurements for the accelerometer 
    *  specified by the pointer 'sensor.' The values will be stored in the
    *  AccelData structure provided by the caller.
    * 
    *  @param sensor A pointer to an intialized sensor that will be read from
    *  @param magData A pointer to a AccelData structe for storing all the readings
    * 
    *  @return Error code
    * 
    *  @retval DRIVER_SUCCESS Success
    *  @retval DRIVER_ERROR There was a driver error
    *  @retval NOT_READY The driver is in an unavailble state 
    *  @retval READY The driver is ready to be used 
    *
    */
   int (*read)(struct AccelerometerSensor *sensor, AccelData *accelDataOut);

};

extern struct AccelerometerSensor *
             create_accelerometer_device(struct DeviceInfo *dev,
                                         struct GPIOSensor *enable_gpio);

int generic_accelerometer_debug_dump(struct Sensor *sensor);
#endif
