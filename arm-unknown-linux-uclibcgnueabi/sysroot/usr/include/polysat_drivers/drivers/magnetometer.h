/**
 *  @file magnetometer. magnetometer sensor header.
 *
 *  @author Dominic Bertolino <db11289@gmail.com> 
 */


#ifndef MAGNETOMETER_H
#define MAGNETOMETER_H

#include <stdint.h>
#include "../driverdb.h"

#define SHIFT_AMOUNT 7

// These readings are expressed in nT (nano-Tesla) units
typedef struct MAG_DATA{
   int32_t x_result;
   int32_t y_result;
   int32_t z_result;
} MagData;

struct MagnetometerSensor {
   struct Sensor sensor;
   MagData magnetometerCache;
   /**
    *  Gets the all three axis measurements for the magnetometer 
    *  specified by the pointer 'sensor.' The values will be stored in the
    *  MagData structure provided by the caller.
    * 
    *  @param sensor A pointer to an intialized sensor that will be read from
    *  @param magData A pointer to a MagData structe for storing all the readings
    * 
    *  @return Error code
    * 
    *  @retval DRIVER_SUCCESS Success
    *  @retval DRIVER_ERROR There was a driver error
    *  @retval NOT_READY The driver is in an unavailble state 
    *  @retval READY The driver is ready to be used 
    *
    */
   int (*read)(struct MagnetometerSensor *sensor, MagData *magDataOut);

   /**
    *  Closes and destroys the magnetometer specified by 'sensor' 
    * 
    *  @param sensor A pointer to an intialized sensor that will be closed
    *
    *  @retval -1 Failure to close
    *  @retval 0 Success
    *  
    */
   // int (*close)(struct MagnetometerSensor **sensor);
};

/**
 *  Initializes the magnetometer specified by 'loc' 
 * 
 *  @param loc The string identifying the magnetometer to be initialized 
 *
 *  @return A pointer to the initialized magnetometer or NULL for failure 
 *
 */
struct MagnetometerSensor *create_magnetometer_device(struct DeviceInfo *dev,
    struct GPIOSensor *enable_gpio);

#endif
