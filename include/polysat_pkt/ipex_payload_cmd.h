#ifndef IPEX_PAYLOAD_CMD_H
#define IPEX_PAYLOAD_CMD_H

#define CMD_IPEX_ENABLE_CPU 2
#define CMD_IPEX_ENABLE_CPU_RESPONSE 3
#define CMD_IPEX_DISABLE_CPU 4
#define CMD_IPEX_DISABLE_CPU_RESPONSE 5
// 6 & 7 are payload beacon commands
#define CMD_IPEX_COPY_INI 8
#define CMD_IPEX_COPY_INI_RESP 9
#define CMD_IPEX_START_CASPER 10
#define CMD_IPEX_START_CASPER_RESP 11
#define CMD_IPEX_STOP_CASPER 12
#define CMD_IPEX_STOP_CASPER_RESP 13
#define CMD_IPEX_START_PICS 14
#define CMD_IPEX_START_PICS_RESP 15
#define CMD_IPEX_STOP_PICS 16
#define CMD_IPEX_STOP_PICS_RESP 17
#define CMD_IPEX_1HOUR_GUMSTIX 18
#define CMD_IPEX_1HOUR_GUMSTIX_RESP 19
#define CMD_IPEX_TAKE_PICTURE 20
#define CMD_IPEX_TAKE_PICTURE_RESP 21
#define CMD_IPEX_KILL_CASPER 22
#define CMD_IPEX_KILL_CASPER_RESP (CMD_IPEX_KILL_CASPER | 0x80)
#define CMD_IPEX_RESTART_CASPER 23
#define CMD_IPEX_RESTART_CASPER_RESP (CMD_IPEX_RESTART_CASPER | 0x80)
#define CMD_IPEX_STOP_PIC_BEACON 24
#define CMD_IPEX_STOP_PIC_BEACON_RESP (CMD_IPEX_STOP_PIC_BEACON | 0x80)
#define CMD_IPEX_START_PIC_BEACON 25
#define CMD_IPEX_START_PIC_BEACON_RESP (CMD_IPEX_START_PIC_BEACON | 0x80)

struct IPEXStatus
{
   uint32_t gstxHeartbeatPollCnt, gstxHeartbeatRespCnt;
   uint32_t gstxBootHeartbeatPollCnt, gstxBootHeartbeatRespCnt;
   uint32_t gstxRebootCnt;
   int32_t gstxPwrSensorCurrent;
   uint32_t gstxPwrSensorVolt;
   int32_t scmPwrSensorCurrent;
   uint32_t scmPwrSensorVolt;
   uint16_t pibTemp;
   uint32_t socGoodCnt, socLowCnt;
   uint32_t ppp0RxBytes, ppp0RxPkts, ppp0RxErrs;
   uint32_t ppp0TxBytes, ppp0TxPkts, ppp0TxErrs;
} __attribute__((packed));

#define IPEX_CAM_FMT_YUV 1
#define IPEX_CAM_FMT_JPEG 2
#define IPEX_CAM_FMT_J2K 3

struct IPEXPictureCmd {
   uint16_t width, height;
   uint8_t format;
   char camera[11];
} __attribute__((packed));

struct IPEXPictureResp {
   uint32_t result;
   char file[1];
} __attribute__((packed));


#endif
