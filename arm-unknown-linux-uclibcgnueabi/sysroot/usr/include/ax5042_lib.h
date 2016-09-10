#ifndef AX5042_LIB_H
#define AX5042_LIB_H

#include <stdint.h>
#include <limits.h>
#ifdef KERNEL
#include "axsem-ax5042.h"
#else
#ifdef LOCAL_INCLUDES
#include "axsem-ax5042.h"
#else
#include <linux/polysat/axsem-ax5042.h>
#endif
#endif

struct AX5042State {
   int fd;
   struct ax5042_commparams radioParams;
};

extern int ax5042_setup_params(struct AX5042State *,
      double carrier, double xtal, double intermediateFreq, double h,
      uint32_t bitrate, uint32_t tmgCorrFrac, uint8_t modulation,
      uint8_t encoding, uint8_t framing, uint8_t crc, uint8_t fec,
      uint8_t *addr1, uint8_t *addr6, int qNum);
extern void ax5042_print_param_summary(struct AX5042State *);
extern void ax5042_print_param_details(struct AX5042State *);
extern uint32_t ax5042_comp_freq(double carrier, double xtal);

extern struct AX5042State *ax5042_open(const char *file);
extern void ax5042_close(struct AX5042State **s);
extern int ax5042_regdump(struct AX5042State *state, struct ax5042_regdump *dump);
extern int ax5042_rssi_stat(struct AX5042State *state, 
                     struct ax5042_rssi_stat *rssi_s);
extern void ax5042_check_status(struct AX5042State *state);
extern int ax5042_read_counters(struct AX5042State *state, 
                     struct ax5042_stats *stats);

extern unsigned long ax5042_crystal_value(unsigned long defaultSN);
extern unsigned long polysat_serial_number();
extern int32_t ax5042_fix_trkfreq(struct AX5042State *state, int16_t readbackValue);
extern int ax5042_drain_tx_queue(struct AX5042State *state);
extern int ax5042_set_hold_time(struct AX5042State *state, int newTime);
extern int ax5042_set_batch_duration(struct AX5042State *state, int newDurMs);
 extern int ax5042_add_doppler_correction(struct AX5042State *state, int rx_correction, struct timespec start_time, struct timespec end_time);
extern int ax5042_set_rx_queue(struct AX5042State *state, int qnum);
extern int ax5042_read_rssi(struct AX5042State *dev, float *rssi1FloatOut,
         int *rssi1IntOut, int *rssi2Out);

extern int ax5042_serial_num(const char *dev_name);
extern int ax5042_saved_crystal_value(const char *dev_name);
extern int ax5042_product_num(const char *dev_name);
extern int ax5042_revision_num(const char *dev_name);
extern int ax5042_batch_num(const char *dev_name);

#endif
