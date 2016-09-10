#ifndef GPS_STATUS_H
#define GPS_STATUS_H


#include <polysat_drivers/drivers/gps.h>

//Contains all gps data
struct GPSStatus{
   int num_sats, lock_type, data_valid;
   double lat, log;
   double hdop, vdop, pdop, alt;
   unsigned int day, mon, year;
   unsigned char hours, mins, secs, m_secs;
} __attribute__((packed));

//Contains the gps Time data
struct GPSTime{
   unsigned int day, mon, year;
   unsigned char hours, mins, secs, m_secs;
} __attribute__((packed));

#endif
