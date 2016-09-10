#ifndef GPIO_DEMUX_H
#define GPIO_DEMUX_H

#define GPIO_DEMUX_MAX_OUTPUTS 16

struct gpio_demux_gpio_output_node {
   short output_gpio;
   char active_value, inactive_value;
   int ms_activation_delay;
   short activation_poll_gpio;
   short activation_poll_active_high;
};

struct gpio_demux_plat_data {
   int virt_gpio;
   char res1;
   char res2;
   char reverse_off_order;
   char virt_gpio_active_high;

   struct gpio_demux_gpio_output_node outputs[GPIO_DEMUX_MAX_OUTPUTS];
};

#endif
