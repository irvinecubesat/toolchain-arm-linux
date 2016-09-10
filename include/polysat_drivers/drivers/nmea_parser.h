#ifndef NMEA_PARSER_H
#define NMEA_PARSER_H

#include "gps.h"

int process_nmea_buff(char *buff, int len, struct GPSData *data);
int process_nmea_record(char *record, struct GPSData *data);

#endif
