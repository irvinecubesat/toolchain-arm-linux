#ifndef DEPLOYABLE_STATE_H
#define DEPLOYABLE_STATE_H

#include <stdint.h>

extern int DPL_init(int changable);
extern void DPL_cleanup(void);
extern uint32_t DPL_get_deployable_state(void);
extern void DPL_set_deployable_state_bit(uint32_t);
extern void DPL_clear_deployable_state_bit(uint32_t);

#endif
