// All of watchdog's cmds

#ifndef WATCHDOG_CMD_H
#define WATCHDOG_CMD_H

#include "status-structs.h"

#define REGISTER_STATIC_PROCESS 3
#define REGISTER_TEMP_PROCESS 4
#define TEMP_PROCESS_RM 5
#define CMD_VALIDATE 6
#define WATCHDOG_CMD_DETAIL_STATUS 7
#define WATCHDOG_CMD_DETAIL_STATUS_RESP 8
#define WATCHDOG_CMD_TAP 9
#define WATCHDOG_CMD_TAP_RESP 10
#define WATCHDOG_CMD_REG_INFO 120
#define WATCHDOG_CMD_REG_INFO_RESP (WATCHDOG_CMD_REG_INFO | 0x80)
#define WATCHDOG_REBOOT_CMD 121
#define WATCHDOG_REBOOT_RESP (WATCHDOG_REBOOT_CMD | 0x80)

#define WDG_PROC_FLAG_WATCHED 1
#define WDG_PROC_FLAG_CRITICAL 2
#define WDG_PROC_FLAG_STATUS_PENDING 4
#define WDG_PROC_FLAG_STATUS_VALID 8
#define WDG_PROC_FLAG_TIMEOUT_ALERT 16
#define WDG_PROC_FLAG_TYPE 32
#define WDG_PROC_FLAG_LEAKY 64
#define WDG_PROC_FLAG_TYPE_STATIC WDG_PROC_FLAG_TYPE
#define WDG_PROC_FLAG_TYPE_TEMP 0


struct WatchedProcDetail {
   uint8_t killAttempts;
   uint8_t flags;
   uint16_t pid;
   uint32_t invalidResponses;
   uint32_t nonResponses;
   uint32_t reregisters;
   uint32_t statusTime;
   uint32_t memUsage;
   uint32_t ipAddr;
   uint16_t udpPort;
   uint8_t tid;
   char name[1];
} __attribute__((packed));

struct WatchdogDetail {
   struct WDTStatus status;
   uint8_t numProcEntries;
   // This array is really variable sized, based on numProcEntries. Also
   // note that the name field in the WatchedProcDetail struct is variable
   // sized, so you can't index this array == ugly C hack!!
   struct WatchedProcDetail details[1];
} __attribute__((packed));

struct WatchdogInfoReq {
   char name[1];
} __attribute__((packed));

typedef struct WatchedProcDetail WatchdogInfoResp;

#endif
