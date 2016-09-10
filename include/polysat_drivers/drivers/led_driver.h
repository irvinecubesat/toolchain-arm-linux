/**
 *  @file led_driver.h 
 *
 *  @author Greg Manyak <gregmanyak@gmail.com>
 *  @author Dominic Bertolino <db11289@gmail.com> 
 *  @author Edmund Yee <ey7180@gmail.com>
 *  @author Robby Tong <robwasab@gmail.com>
 */

#ifndef __LED_DRIVER_H__ 
#define __LED_DRIVER_H__

/*---------------------------------------------------------------------------*/
/*                      #includes                                            */
/*---------------------------------------------------------------------------*/
#include <stdint.h>
#include "../driverdb.h"

//REGISTER addresses
#define PCA9550_REG_PWM0 0x02
#define PCA9550_REG_PWM1 0x04
#define PCA9550_REG_FREQ_PRESCALE0 0x01
#define PCA9550_REG_FREQ_PRESCALE1 0x03
#define PCA9550_REG_LS0 0x05

/*---------------------------------------------------------------------------*/
/*                       Function Declarations                               */
/*---------------------------------------------------------------------------*/

//LEDDriverSensor is a Sensor

struct LEDDriverSensor {
  struct Sensor sensor;
  int (*set_duty_cycle)(struct LEDDriverSensor *sensor, uint16_t cycle,       uint8_t regOffset);
  int (*set_frequency)(struct LEDDriverSensor *sensor,  uint16_t frequency,   uint8_t regOffset);
  int (*get_duty_cycle)(struct LEDDriverSensor *sensor, uint16_t * cycle,     uint8_t regOffset);
  int (*get_frequency)(struct LEDDriverSensor *sensor,  uint16_t * frequency, uint8_t regOffset);
  int (*get_register)(struct LEDDriverSensor *sensor,  uint16_t * result,    uint8_t regOffset);
  int (*set_register) (struct LEDDriverSensor *sensor,  uint16_t value,       uint8_t regOffset);
};

extern struct LEDDriverSensor *create_led_driver_device(struct DeviceInfo *dev,
     struct GPIOSensor *enable_gpio);

#endif
