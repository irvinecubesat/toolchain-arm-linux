/**
 *  @file charge_controller.h 
 *
 *  @author John Bellardo
 *
 */

#ifndef __CHARGE_CONTROLLER_H__ 
#define __CHARGE_CONTROLLER_H__



/*---------------------------------------------------------------------------*/
/*                      #includes                                            */
/*---------------------------------------------------------------------------*/
#include <stdint.h>
#include "../driverdb.h"
#include "power.h"


/*---------------------------------------------------------------------------*/
/*                       Function Declarations                               */
/*---------------------------------------------------------------------------*/

#define CC_OVER_VOLTAGE (1 << 0)
#define CC_UNDER_VOLTAGE (1 << 1)
#define CC_CHARGE_OVER_CURRENT (1 << 2)
#define CC_DISCHARGE_OVER_CURRENT (1 << 3)
#define CC_CHARGING_ACTIVE (1 << 4)
#define CC_DISCHARGING_ACTIVE (1 << 5)
#define CC_CHARGING_ENABLED (1 << 6)
#define CC_DISCHARGING_ENABLED (1 << 7)

struct ChargeController {
   struct PowerSensor powerSensor;
   uint8_t stateCache;
   uint32_t maxChargeVoltage;
   uint32_t chargeEnableDeltaVoltage;
   uint8_t disableAutomatedControl;

   int (*enable_charging)(struct ChargeController *sensor);
   int (*disable_charging)(struct ChargeController *sensor);
   int (*enable_discharging)(struct ChargeController *sensor);
   int (*disable_discharging)(struct ChargeController *sensor);
   int (*read_state)(struct ChargeController *sensor, uint8_t *state);
   int (*reset_state)(struct ChargeController *sensor, uint8_t *state);
};

extern struct ChargeController *create_charge_controller_device
		(struct DeviceInfo *dev, struct GPIOSensor *enable_gpio);
extern int generic_charge_controller_debug_dump(struct Sensor *sensor);

#endif
