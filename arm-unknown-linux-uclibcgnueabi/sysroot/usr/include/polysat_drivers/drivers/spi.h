/**
 *  @file spi.h spi source.
 *
 *  driver for the spi bus 
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
#include <linux/spi/spidev.h>

/*---------------------------------------------------------------------------*/
/*                       Function Declarations                               */
/*---------------------------------------------------------------------------*/

/*
struct SPIBusLocation {
   int address;
   const char *bus_device;
};
*/

struct SPIBusCFG {
   char *mode;
   uint16_t bits;
   uint32_t speed;
   uint16_t delay;
   char *bus;
};


struct BusInterface *create_spi_bus_interface(void *location);

/*
 * Function: spi_init
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
struct BusInterface *spi_init(void* addr, int bus);
