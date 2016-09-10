#ifndef OV3642_H
#define OV3642_h

struct ov3642_platform_data {
   int enable_gpio;
   int enable_active_high;
   char *name;
   uint8_t dataorder;
   int debug_flag;
   int always_on_gpio;
   int always_on_gpio_active_high;
};

#endif
