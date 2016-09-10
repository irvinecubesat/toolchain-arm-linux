/**
 *  @file power.h 
 *
 *  @author Greg Manyak <gregmanyak@gmail.com>
 *  @author Dominic Bertolino <db11289@gmail.com> 
 *
 */

#ifndef __ADC_H__ 
#define __ADC_H__



/*---------------------------------------------------------------------------*/
/*                      #includes                                            */
/*---------------------------------------------------------------------------*/
#include <stdint.h>
#include "../driverdb.h"


/*---------------------------------------------------------------------------*/
/*                       Function Declarations                               */
/*---------------------------------------------------------------------------*/

struct ADCSensor {
   struct Sensor sensor;
   int32_t adcCache;
   // Read the current ADC value.  Returns 0 on success
   int (*read)(struct ADCSensor *sensor, int blocking, int32_t *readingOut);
};

extern struct ADCSensor *create_adc_device(struct DeviceInfo *dev,
    struct GPIOSensor *enable_gpio);

extern int generic_adc_debug_dump(struct Sensor *sensor);

#endif
