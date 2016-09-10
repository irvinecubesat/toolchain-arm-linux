#ifndef EXOCUBE_PAYLOAD_CMD_H
#define EXOCUBE_PAYLOAD_CMD_H

#define CMD_EXOCUBE_ENABLE_CPU 2
#define CMD_EXOCUBE_ENABLE_CPU_RESPONSE 3
#define CMD_EXOCUBE_DISABLE_CPU 4
#define CMD_EXOCUBE_DISABLE_CPU_RESPONSE 5

#define CMD_EXOCUBE_DEPLOY_BOOM 21
#define CMD_EXOCUBE_DEPLOY_BOOM_RESP (CMD_EXOCUBE_DEPLOY_BOOM | 0x80)
#define CMD_EXOCUBE_INIT_SERIAL 22
#define CMD_EXOCUBE_INIT_SERIAL_RESP (CMD_EXOCUBE_INIT_SERIAL | 0x80)
#define CMD_EXOCUBE_DISABLE_SERIAL 25
#define CMD_EXOCUBE_DISABLE_SERIAL_RESP (CMD_EXOCUBE_DISABLE_SERIAL | 0x80)
#define CMD_EXOCUBE_SEND_COMMAND 23
#define CMD_EXOCUBE_SEND_COMMAND_RESP (CMD_EXOCUBE_SEND_COMMAND | 0x80)
#define CMD_EXOCUBE_ENABLE_INSTRUMENT 24
#define CMD_EXOCUBE_ENABLE_INSTRUMENT_RESP (CMD_EXOCUBE_ENABLE_INSTRUMENT | 0x80)
#define CMD_EXOCUBE_DISABLE_INSTRUMENT 27
#define CMD_EXOCUBE_DISABLE_INSTRUMENT_RESP (CMD_EXOCUBE_DISABLE_INSTRUMENT | 0x80)
#define CMD_EXOCUBE_GET_COMMAND 26
#define CMD_EXOCUBE_GET_COMMAND_RESP (CMD_EXOCUBE_GET_COMMAND | 0x80)
#define CMD_EXOCUBE_SET_PARAMS 28
#define CMD_EXOCUBE_SET_PARAMS_RESP (CMD_EXOCUBE_SET_PARAMS | 0x80)


// Exocube specific structs

struct EXOCUBEStatus
{
   uint32_t totalCmdSent;
   uint32_t totalSerRead;

   uint32_t pwr_3v3Volt;
   int32_t pwr_3v3Curr;
   uint32_t pwr_5v0Volt;
   int32_t pwr_5v0Curr;
   uint32_t pwr_wheelVolt;
   int32_t pwr_wheelCurr;

   uint16_t pib_temp;
   uint16_t boom0_temp;
   uint16_t boom1_temp;
   
   uint32_t instrumentUTC;
   uint16_t instrumentSubSeconds;
   uint8_t instrumentCounter;
   uint16_t instrumentTemp1;
   uint16_t instrumentTemp2;
} __attribute__((packed));

#endif
