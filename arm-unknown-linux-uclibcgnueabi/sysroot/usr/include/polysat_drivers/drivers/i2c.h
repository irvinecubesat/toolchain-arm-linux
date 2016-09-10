/**
 *  @file i2c.h i2c source.
 *
 *  driver for the i2c bus 
 *
 *  @author Greg Manyak <gregmanyak@gmail.com>
 *  @author Dominic Bertolino <db11289@gmail.com> 
 */



/*---------------------------------------------------------------------------*/
/*                      #includes 						                     */
/*---------------------------------------------------------------------------*/
#include <stdint.h>
#include <linux/types.h>
#include <sys/types.h>
#include "../bus_interface.h"

/*---------------------------------------------------------------------------*/
/*                       Function Declarations                               */
/*---------------------------------------------------------------------------*/

/*
struct I2CBusLocation {
   int address;
   const char *bus_device;
};
*/

struct I2CBusCFG {
   uint32_t address;
   char *bus;
};


struct BusInterface *create_i2c_bus_interface(void *location);

/*
 * Function: i2c_init
 *
 * Get file descriptor for specific device at 'addr' 
 * 
 * @param addr: The address of the device to init
 *
 * @return Error code
 *
 * @retval NULL on failure and errno is set 
 * @retval void * file descriptor if success
 */
struct BusInterface *i2c_init(void* addr, int bus);

/*
 * Function: i2c_close
 *
 * Close file descriptor 
 * 
 * @param deviceFd: The fd to close
 *
 * @return Error code
 *
 * @retval -1 if failed
 * @retval 0 if success
 */
int i2c_close(void * deviceFd);
