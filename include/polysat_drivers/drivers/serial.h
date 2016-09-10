
/**
 *  @file serial.h serial source.
 *
 *  Driver for serial port
 *
 *  @author Luc Bouchard <lucf@bouchard.com>
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



struct BusInterface *create_serial_bus_interface(void *location);

