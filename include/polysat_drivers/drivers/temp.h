/**
 *  @file temp.h Temperature sensor header
 *
 *  Hardware abstraction for temperature sensor.
 *
 *  @author Greg Manyak <gregmanyak@gmail.com>
 *  @author Dominic Bertolino <db11289@gmail.com> 
 */

#ifndef __TEMP_H__ 
#define __TEMP_H__


/*---------------------------------------------------------------------------*/
/*                       #includes                                           */
/*---------------------------------------------------------------------------*/
#include <stdint.h>
#include "../driverdb.h"

/*---------------------------------------------------------------------------*/
/*                       Function Declarations                               */
/*---------------------------------------------------------------------------*/

struct TemperatureSensor {
   struct Sensor sensor;
   uint16_t temperatureCache;
   int (*read)(struct TemperatureSensor *sensor, uint16_t * tempKOut);
};

/**
 *  Inits a temp sensor. Struct with initialized device info is returned
 * 
 *  @param loc  the string giving the location of the device to initialize
 *
 *  @return Pointer or Null
 *
 *  @retval  pointer to device struct if successful
 *  @retval  NULL on failure
 */
struct TemperatureSensor *create_temperature_device(struct DeviceInfo *dev,
    struct GPIOSensor *enable_gpio);
int temp_debug_dump(struct Sensor *sensor);
// int temp_close(void* sensor);
// int temp_rd(uint16_t * tempK, void * sensor);

/**
 *  Reads the temperature of a tmp101 temperature sensor and returns the value in celsius. 
 * 
 *  @param value The char* to write celsius value to
 *  @param sensor: The sensor to be read from 
 *
 *  @return error code
 *
 *  @retval -1 failure and errno is set 
 *  @retval 0 success 
 */
// int temp_rd_tmp101(uint16_t * tempK, void * sensor);

/**
 *  Reads the temperature of a ad5715 (or ad5714) temperature sensor and 
 *  returns the value in celsius. 
 * 
 *  @param value The char* to write celsius value to
 *  @param sensor: The sensor to be read from 
 *
 *  @return error code
 *
 *  @retval -1 failure and errno is set 
 *  @retval 0 success 
 */
// int temp_rd_ad7415(uint16_t * tempK, void * sensor);

#endif
