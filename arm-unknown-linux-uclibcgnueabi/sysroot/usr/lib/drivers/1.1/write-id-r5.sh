#!/bin/sh

CALIB=16000004
SERIAL=13
REV=5

eeprom-util -d -B 0 -A 0x52
eeprom-util -a -B 0 -A 0x52 -T at24c128
eeprom-util -w -B 0 -A 0x52 -V 1 -W Tyvak -P 1 -Q "UHF Radio" \
	-R $REV -L 1 -S $SERIAL -U $CALIB -C devices-r5.cfg
