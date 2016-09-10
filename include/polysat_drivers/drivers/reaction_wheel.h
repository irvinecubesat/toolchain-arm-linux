/**
 *  @file gyroscope.h 
 *
 *  @author Greg Manyak <gregmanyak@gmail.com>
 *  @author Dominic Bertolino <db11289@gmail.com> 
 *  @author Edmund Yee <ey7180@gmail.com>
 *  @author Robby Tong <robwasab@gmail.com>
 *  @author Eric Funsten <efunsten@calpoly.edu>
 */

#ifndef __SINCLAIR_H__ 
#define __SINCLAIR_H__

/*---------------------------------------------------------------------------*/
/*                      #includes                                            */
/*---------------------------------------------------------------------------*/
#include <stdint.h>
#include "../driverdb.h"


/*---------------------------------------------------------------------------*/
/*                       Function Declarations                               */
/*---------------------------------------------------------------------------*/

struct ReactionWheelSensor {
   struct Sensor sensor;
   //Sets the speed, acceleration, or torque targets in the units below.
      // deg_sec2 fixed-point 9.23
   int (*set_accel)(struct ReactionWheelSensor *wheel, int32_t deg_sec2);
      // deg_sec fixed-point 24.8
   int (*set_speed)(struct ReactionWheelSensor *wheel, int32_t deg_sec);
      // N_m
   int (*set_torque)(struct ReactionWheelSensor *wheel, float N_m);

   //Reads speed, acceleration, and inertia in the units below.
      // deg_sec fixed-point 24.8
   int (*read_speed)(struct ReactionWheelSensor *wheel, int32_t *deg_sec);
      // deg_sec2 fixed-point 9.23
   int (*read_accel)(struct ReactionWheelSensor *wheel, int32_t *deg_sec2);
      // N_m
   int (*read_torque)(struct ReactionWheelSensor *wheel, float *N_m);
};

//Creates a reaction wheel device to use.
extern struct ReactionWheelSensor *create_reaction_wheel_device(struct DeviceInfo *dev);

#endif

