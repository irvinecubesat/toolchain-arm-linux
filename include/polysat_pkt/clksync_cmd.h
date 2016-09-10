#ifndef CLKSYNC_CMD_H
#define CLKSYNC_CMD_H

#include <stdint.h>

#define CLKSYNC_SET_CMD 2
#define CLKSYNC_SET_RESP (CLKSYNC_SET_CMD | 0x80)
#define CLKSYNC_SET_OFFSET_CMD 3
#define CLKSYNC_SET_OFFSET_RESP (CLKSYNC_SET_OFFSET_CMD | 0x80)

#define CLKSYNC_TIMEPKT_TYPE_REG 1
#define CLKSYNC_TIMEPKT_TYPE_END 2

struct timepacket_offset {
   int32_t sec;     // Expected time of arrival (sec)
   int32_t usec;    // Expected time of arrival (usec)
   uint32_t id;     // Unique ID for offset request
   int32_t reboot_time;     // Unique ID for offset request
} __attribute__((packed));

struct timepacket {
   uint8_t type;            // Packet type field
   uint32_t expected_sec;     // Expected time of arrival (sec)
   uint32_t expected_usec;    // Expected time of arrival (usec)
} __attribute__((packed));

struct timepacket_resp {
   uint8_t result;            // Packet type field
   uint32_t expected_sec;     // Expected time of arrival (sec)
   uint32_t expected_usec;    // Expected time of arrival (usec)
   uint32_t pkt_cnt;
} __attribute__((packed));

struct cs_status_req {
   uint32_t sec;
   uint32_t usec;
} __attribute__((packed));

#endif
