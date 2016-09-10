/**
 *  @file gyroscope.h 
 *
 *  @author Greg Manyak <gregmanyak@gmail.com>
 *  @author Dominic Bertolino <db11289@gmail.com> 
 *  @author Edmund Yee <ey7180@gmail.com>
 *  @author Robby Tong <robwasab@gmail.com>
 *  @author Eric Funsten <efunsten@calpoly.edu>
 */

#ifndef __GYROSCOPE_H__ 
#define __GYROSCOPE_H__

/*---------------------------------------------------------------------------*/
/*                      #includes                                            */
/*---------------------------------------------------------------------------*/
#include <stdint.h>
#include "../driverdb.h"


/*---------------------------------------------------------------------------*/
/*                       Function Declarations                               */
/*---------------------------------------------------------------------------*/

typedef struct GYRO_DATA{
   int32_t x,	/* x-axis angular rate data. */
         y,     /* y-axis angluar rate data. */
         z;     /* z-axis angular rate data. */
}GyroData;


struct GyroscopeSensor {
   struct Sensor sensor;
   int (*set_bandwidth)(struct GyroscopeSensor *sensor, char bw);
   int (*set_mode)(struct GyroscopeSensor *sensor, char mode);
   int (*set_range)(struct GyroscopeSensor *sensor, char range);
   int (*read)(struct GyroscopeSensor *sensor, GyroData *data);
   int (*get_bandwidth)(struct GyroscopeSensor *sensor, unsigned char * bw);
};

extern struct GyroscopeSensor *create_gyroscope_device(struct DeviceInfo *dev,
    struct GPIOSensor *enable_gpio);
extern int generic_gyroscope_debug_dump(struct Sensor *sensor);
void * gyro_init(const char * name);

#endif

