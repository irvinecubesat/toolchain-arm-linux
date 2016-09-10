#ifndef SHARED_STRUCTS_H
#define SHARED_STRUCTS_H

/**
 * @file shared-structs.h Shared Structures for Commands
 *
 * @author Greg Manyak <gregmanyak@gmail.com>
 */

#include <stdint.h>
#include <sys/types.h>

/// Structure for temporary registration with watchdog
struct WdtTempRegister {
   /// Process ID of the process to be watched
   pid_t pid;
   /// Task ID for this watch event (user specified)
   uint8_t tid;
   /// Desired timeout in ms of the task
   uint32_t timeout;
   /// Option to be alerted upon timeout
   unsigned timeoutAlert :1;
};

/// Structure for removing a temporary watch
struct WdtTempRemove {
   /// Process ID of the process with watch on it 
   pid_t pid;
   /// Task ID for the watch event to be removed 
   uint8_t tid;
};



#endif
