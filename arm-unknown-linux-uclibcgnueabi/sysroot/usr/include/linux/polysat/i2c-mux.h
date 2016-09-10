#ifndef I2C_MUX_H
#define I2C_MUX_H

#define I2C_MUX_MAX_PINS 3
#define I2C_MUX_MAX_ADDRS (1 << I2C_MUX_MAX_PINS)

struct i2cmuxbus_plat_data {
   int gpio_base;
   int virt_gpio_active_high;
   struct {
      int pin, active_val;
      int ms_activation_delay;
      short activation_poll_gpio;
      short activation_poll_active_high;
   } master_pins[8];
   int num_addrs, num_pins;
   int gpios[I2C_MUX_MAX_PINS];
   struct {
      char values[I2C_MUX_MAX_PINS];
   } gpio_values[I2C_MUX_MAX_ADDRS];
   struct i2c_board_info *devices;
   int num_devices;
};

#endif
