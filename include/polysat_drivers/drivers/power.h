/**
 *  @file power.h 
 *
 *  @author Greg Manyak <gregmanyak@gmail.com>
 *  @author Dominic Bertolino <db11289@gmail.com> 
 *
 */

#ifndef __POWER_H__ 
#define __POWER_H__



/*---------------------------------------------------------------------------*/
/*                      #includes                                            */
/*---------------------------------------------------------------------------*/
#include <stdint.h>
#include "../driverdb.h"


/*---------------------------------------------------------------------------*/
/*                       Function Declarations                               */
/*---------------------------------------------------------------------------*/

struct PowerSensor {
   struct Sensor sensor;
   uint16_t temperatureCache;
   int32_t currentCache;
   uint32_t accumulatedCurrentCache;
   uint32_t voltageCache;
   uint32_t powerCache;
   // Most power devices include a temperature sensor
   int (*read_temp)(struct PowerSensor *sensor, uint16_t *tempKOut);

   // Gets the current measurement
   int (*read_current)(struct PowerSensor *sensor, int32_t *currentOut);
   // Reads and programs (e.g. calibrates) the current accumulation register
   int (*read_accumulated_current)(struct PowerSensor *sensor,
                            uint32_t *accumulatedCurrentOut);
   int (*set_accumulated_current)(struct PowerSensor *sensor,
                            int32_t accumulatedCurrentOut);
   // Voltate
   int (*read_voltage)(struct PowerSensor *sensor, uint32_t *voltageOut);

   // Read power (mW)
   int (*read_power)(struct PowerSensor *sensor, uint32_t *powerOut);

   // Critical device configuration functions
   // Maximum amount of stored energy available in device attached
   // to sensor.  Function pointer may be NULL if stored energy device
   // is not attached or capacity is unknown.
   int (*max_accumulated_current)(struct PowerSensor *sensor,
                            int32_t *maxAccumulatedCurrentOut);
   // Maximum expected output voltage of device attached to sensor.  Function
   // pointer may be NULL.
   int (*max_voltage)(struct PowerSensor *sensor, uint32_t *voltageOut);
   // Returns one of the STORED_energy_DEVICE_* macro values indicating if
   // a stored energy device is expected to be attached to the power device.
   // Function point may be NULL.
#define STORED_energy_DEVICE_EXPECTED 0x1234
#define STORED_energy_DEVICE_NOT_EXPECTED 0x7907
   int (*stored_energy_device_attached)(struct PowerSensor *sensor);
};

extern struct PowerSensor *create_power_device(struct DeviceInfo *dev,
    struct GPIOSensor *enable_gpio);

/**
 *  Inits a power sensor. Struct with initialized device info is returned
 * 
 *  @param loc: the string giving the location of the device to initialize
 *  @param pwrLSB: sets units. (not supported currently)
 *
 *  @return Pointer or Null
 *
 *  @retval  pointer to device struct if successful
 *  @retval  NULL on failure
 */
void * power_init(const char * loc, int pwrLSB);
// int power_close(void* sensor);

/**
 *  Reads the current
 * 
 *  @param current: mA current value pointer that is updated 
 *  @param sensor: The sensor to be read from 
 *
 *  @return error code
 *
 *  @retval -1 failure and errno is set 
 *  @retval 0 success 
 */
// int read_curr( int32_t * current, void * sensor);

/**
 *  Reads the shunt voltage
 * 
 *  @param volt: mV sensor value pointer that is updated to give 
 *               the shunt voltage reading 
 *  @param sensor: The sensor to be read from 
 *
 *  @return error code
 *
 *  @retval -1 failure and errno is set 
 *  @retval 0 success 
 */
// int read_shunt(int32_t * volt, void * sensor);

/**
 *  Reads the bus voltage
 * 
 *  @param volt: mV sensor value pointer that is updated to give 
 *               the bus voltage reading 
 *  @param sensor: The sensor to be read from 
 *
 *  @return error code
 *
 *  @retval -1 failure and errno is set 
 *  @retval 0 success 
 */
// int read_bus(uint16_t * volt, void * sensor);

/**
 *  Reads the read_pwr
 * 
 *  @param pwr: mW power value pointer that is updated 
 *  @param sensor: The sensor to be read from 
 *
 *  @return error code
 *
 *  @retval -1 failure and errno is set 
 *  @retval 0 success 
 */
// int read_pwr(uint32_t * pwr, void * sensor);

int generic_power_debug_dump(struct Sensor *sensor);
#endif
