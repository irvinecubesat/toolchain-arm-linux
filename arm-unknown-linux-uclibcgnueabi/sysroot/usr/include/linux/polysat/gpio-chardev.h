#ifndef GPIO_CHARDEV_H
#define GPIO_CHARDEV_H

struct gpio_chardev_plat_data {
   int gpio, jitter_delay_ms;
   const char *dev_name;
};

#endif
