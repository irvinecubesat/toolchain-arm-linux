// All of datalogger's cmds

#ifndef DATALOGGER_CMD_H
#define DATALOGGER_CMD_H

#include <stdint.h>

#define DATALOGGER_CREATE_SEQ 0x07
#define DATALOGGER_SPAWN 0x08
#define DATALOGGER_REMOVE_SEQ 0x09
#define DATALOGGER_ACK 0x0A
#define DATALOGGER_SET_OPS_MODE 0x0B
#define DATALOGGER_SET_OPS_MODE_ACK 0x0C
#define DATALOGGER_LOG_EVENT 0x0D

struct DataloggerEventDesc {
   uint32_t proc_id;
   uint32_t event_id;
   uint32_t timestamp;
   char description[1];
} __attribute__((packed));

struct ProcessData;

extern void DL_log_event(struct ProcessData *proc, uint32_t id,
    const char *description);
extern void DL_vlog_event(struct ProcessData *proc, uint32_t id,
    const char *format, ...);
extern void DL_set_ops_mode(struct ProcessData *proc, uint32_t mode);

#endif
