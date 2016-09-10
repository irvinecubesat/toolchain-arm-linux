#ifndef FILEMGR_CMD_H
#define FILEMGR_CMD_H

#include <stdint.h>

#define FILEMGR_QUEUE_ADD_FILE 16
#define FILEMGR_QUEUE_ADD_FILE_RESP 17
#define FILEMGR_QUEUE_REMOVE_FILE 18
#define FILEMGR_QUEUE_REMOVE_FILE_RESP 19
#define FILEMGR_BEACON_FILE 20
#define FILEMGR_BEACON_FILE_RESP 21
#define FILEMGR_BEACON_FILE_INTERVAL 22
#define FILEMGR_BEACON_FILE_INTERVAL_RESP 23
#define FILEMGR_FILE_BEACON 40
#define FILEMGR_FILE_BEACON_META 41

#define FILEMGR_PIC_REQUEST 64
#define FILEMGR_PIC_RESP 65

#define FILEMGR_START_DUMP 66
#define FILEMGR_START_DUMP_RESP 67
#define FILEMGR_STOP_DUMP 68
#define FILEMGR_STOP_DUMP_RESP 69
#define FILEMGR_SCHED_DUMP 70
#define FILEMGR_SCHED_DUMP_RESP 71

#define FILEMGR_SCHED_DUMP_ADD_ABS 1
#define FILEMGR_SCHED_DUMP_ADD_REL 2
#define FILEMGR_SCHED_DUMP_RM 3

struct FILEMGR_sched_op {
   char cmd;
   uint32_t start;
   uint32_t dur;
};

struct FILEMGR_queue_op {
   uint8_t group;
   uint8_t priority;
   uint8_t flags;
   char name[4];
} __attribute__((packed));

struct FILEMGR_BeaconFileInterval {
   uint32_t ms_intv;
   uint32_t revert_ms;
} __attribute__((packed));

struct FILEMGR_BeaconFile {
   uint32_t max_size;
   char name[4];
} __attribute__((packed));

struct FILEMGR_FileBeaconContents {
   uint32_t id;
   uint32_t len;
   uint16_t blkNum;
   char reserved;
   char data[128];
} __attribute__((packed));


#define PIC_LOC_NAND 1
#define PIC_LOC_SDCARD 2

struct PICRequest {
   char camera[8];
   uint8_t loc;
} __attribute__((packed));

#define PIC_STATUS_UNKNOWN 0
#define PIC_STATUS_STARTED 1
#define PIC_STATUS_BUSY 2
#define PIC_STATUS_ERROR 3
#define PIC_STATUS_IDLE 4
#define PIC_STATUS_COMPLETE 5

#define PIC_RESP_IMMEDIATE 1

struct PICResponseImm {
   uint8_t responseType;
   uint8_t status;
   char fullSuffix[16];
   char medSuffix[16];
   char thumbSuffix[16];
   char filename[1];
} __attribute__((packed));

#define PIC_RESP_COMPLETE 2

struct PICResponseComplete {
   uint8_t responseType;
   uint8_t status;
   uint16_t dataOffset;
   uint32_t thumbSize;
   uint32_t fileNum;
   uint8_t data[192];
} __attribute__((packed));

#define PIC_RESP_THUMBDATA 3

struct PICResponseThumbData {
   uint8_t responseType;
   uint16_t dataOffset;
   uint8_t data[192];
} __attribute__((packed));


struct ProcessData;
extern void FILEMGR_add_to_download_queue(struct ProcessData *proc,
   const char *file, uint8_t group, uint8_t priority);

#endif
