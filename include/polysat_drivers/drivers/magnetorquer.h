#ifndef __MAGNETORQUER_H__
#define __MAGNETORQUER_H__

#include <stdint.h>
#include "../driverdb.h"

struct Magnetorquer {
   struct Sensor sensor;

   int (*get_frequency)(struct Magnetorquer *sensor, uint8_t *freqOut);
   int (*get_duty_cycle)(struct Magnetorquer *sensor, uint8_t *cycleOut);

   int (*set_frequency)(struct Magnetorquer *sensor, uint8_t freq);
   int (*set_duty_cycle)(struct Magnetorquer *sensor, uint8_t cycle);
   int (*set_torque)(struct Magnetorquer *sensor, int32_t nTesla);
   int (*set_torque_amm2)(struct Magnetorquer *sensor, float amm2);
   int (*start_torque)(struct Magnetorquer *sensor);
   int (*stop_torque)(struct Magnetorquer *sensor);
};

extern struct Magnetorquer *create_magnetorquer_device(struct DeviceInfo *dev,
    struct GPIOSensor *enable_gpio);
#endif
