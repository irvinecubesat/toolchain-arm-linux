#ifndef PCA9548_H
#define PCA9548_H

struct pca9548_plat_data {
   int reset_gpio, reset_active_high;
   int i2c_bus_offset;
};

#endif
