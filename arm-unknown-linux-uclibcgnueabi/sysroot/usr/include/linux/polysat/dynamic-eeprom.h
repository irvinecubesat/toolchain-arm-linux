#ifndef DYNAMIC_EEPROM_H
#define DYNAMIC_EEPROM_H

#define DYN_EEPROM_TYPE_AT24C04 1
#define DYN_EEPROM_TYPE_AT24C08 2
#define DYN_EEPROM_TYPE_AT24C16 3
#define DYN_EEPROM_TYPE_AT24C32 4
#define DYN_EEPROM_TYPE_AT24C64 5
#define DYN_EEPROM_TYPE_AT24C128 6
#define DYN_EEPROM_TYPE_AT24C256 7
#define DYN_EEPROM_TYPE_AT24C512 8
#define DYN_EEPROM_TYPE_AT24C1024 9
#define DYN_EEPROM_TYPE_AT24C02 10


struct dynamic_eeprom_params {
   int i2c_bus_num, i2c_addr;
   int type;
   int readonly;
   uint32_t id;
   char location[33];
   char description[33];
};

#define DYNAMIC_EEPROM_IOC_MAGIC 'e'
#define DYNAMIC_EEPROM_IOADD _IOW(DYNAMIC_EEPROM_IOC_MAGIC, 1, \
         struct dynamic_eeprom_params)
#define DYNAMIC_EEPROM_IONEXT _IOR(DYNAMIC_EEPROM_IOC_MAGIC, 2, \
         struct dynamic_eeprom_params)
#define DYNAMIC_EEPROM_IORM _IOW(DYNAMIC_EEPROM_IOC_MAGIC, 3, \
         unsigned long)

#endif
