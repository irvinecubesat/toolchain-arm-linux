/*
  ax5042.h
 
  Copyright John Bellardo, 2011
 
*/

#ifndef AXSEM_AX5042_H
#define AXSEM_AX5042_H

#define AX5042_MODE_UNKNOWN 0
#define AX5042_MODE_RX 1
#define AX5042_MODE_TX 2
#define AX5042_MODE_IDLE 3
#define AX5042_MODE_STOPPING 4
#define AX5042_MODE_SHUTDOWN 5
#define AX5042_MODE_RX_TO_TX 6
#define AX5042_MODE_TX_TO_RX 7
#define AX5042_MODE_RX_REQUEST 8
#define AX5042_MODE_TX_REQUEST 9
#define AX5042_MODE_RX_HOLD 10
#define AX5042_MODE_LAST_MODE AX5042_MODE_RX_HOLD

#define AX5042_MOD_GFSK 1
#define AX5042_MOD_FSK 2
#define AX5042_MOD_MSK 3
#define AX5042_MOD_GMSK 4
#define AX5042_MOD_ASK 5
#define AX5042_MOD_PSK 6
#define AX5042_MOD_OQPSK 7

#define AX5042_ENC_NRZ 1
#define AX5042_ENC_NRZ_SCRAMBLED 2
#define AX5042_ENC_NRZI 3
#define AX5042_ENC_NRZI_SCRAMBLED 4
#define AX5042_ENC_FM1 5
#define AX5042_ENC_FM0 6
#define AX5042_ENC_MANCHESTER 7

#define AX5042_FRAME_RAW 1
#define AX5042_FRAME_RAW_SOFTDEC 2
#define AX5042_FRAME_HDLC 3
#define AX5042_FRAME_ZIGBEE 4

#define AX5042_CRC_CCITT 1
#define AX5042_CRC_16 2
#define AX5042_CRC_32 3

#define AX5042_REG_TRKFREQ 0x4C
#define AX5042_REG_REVISION            0x00
#define AX5042_REG_SCRATCH              0x01
#define AX5042_REG_POWERMODE            0x02

#define AX5042_REG_FIFOCTRL         0x04
#define AX5042_REG_FIFOCONTROL         0x04
#define AX5042_REG_FIFODATA            0x05

#define  AX5042_REG_IRQMASK            0x06
#define  AX5042_REG_IRQINVERSION       0x0F

#define AX5042_REG_PINCFG1          0x0C
#define AX5042_REG_PINCFG2          0x0D
#define AX5042_REG_PINCFG3          0x0E
#define AX5042_REG_XTALOSC              0x03
#define AX5042_REG_IRQREQUEST           0x07
#define AX5042_REG_IFMODE               0x08
#define AX5042_REG_MODULATION           0x10
#define AX5042_REG_ENCODING             0x11
#define AX5042_REG_FRAMING              0x12
#define AX5042_REG_CRCINIT3             0x14
#define AX5042_REG_CRCINIT2             0x15
#define AX5042_REG_CRCINIT1             0x16
#define AX5042_REG_CRCINIT0             0x17
#define AX5042_REG_FEC                  0x18
#define AX5042_REG_FECSYNC              0x19
#define AX5042_REG_FREQ3                0x20
#define AX5042_REG_FREQ2                0x21
#define AX5042_REG_FREQ1                0x22
#define AX5042_REG_FREQ0                0x23
#define AX5042_REG_FSKDEV2              0x25
#define AX5042_REG_FSKDEV1              0x26
#define AX5042_REG_FSKDEV0              0x27
#define AX5042_REG_IFFREQHI             0x28
#define AX5042_REG_IFFREQLO             0x29
#define AX5042_REG_PLLLOOP              0x2c
#define AX5042_REG_PLLRANGING           0x2d
#define AX5042_REG_PLLRNGCLK            0x2e
#define AX5042_REG_TXPWR                0x30
#define AX5042_REG_TXRATEHI             0x31
#define AX5042_REG_TXRATEMID            0x32
#define AX5042_REG_TXRATELO             0x33
#define AX5042_REG_MODMISC              0x34
#define AX5042_REG_ADCMISC              0x38
#define AX5042_REG_AGCTARGET            0x39
#define AX5042_REG_AGCATTACK            0x3a
#define AX5042_REG_AGCDECAY             0x3b
#define AX5042_REG_AGCCOUNTER           0x3c
#define AX5042_REG_CICSHIFT             0x3d
#define AX5042_REG_CICDECHI             0x3e
#define AX5042_REG_CICDECLO             0x3f
#define AX5042_REG_DATARATEHI           0x40
#define AX5042_REG_DATARATELO           0x41
#define AX5042_REG_TMGGAINHI            0x42
#define AX5042_REG_TMGGAINLO            0x43
#define AX5042_REG_PHASEGAIN            0x44
#define AX5042_REG_FREQGAIN             0x45
#define AX5042_REG_FREQGAIN2            0x46
#define AX5042_REG_AMPLGAIN             0x47
#define AX5042_REG_TRKAMPHI             0x48
#define AX5042_REG_TRKAMPLO             0x49
#define AX5042_REG_TRKPHASEHI           0x4A
#define AX5042_REG_TRKPHASELO           0x4B
#define AX5042_REG_TRKFREQHI            0x4C
#define AX5042_REG_TRKFREQLO            0x4D
#define AX5042_REG_SPAREOUT             0x60
#define AX5042_REG_TESTOBS              0x68
#define AX5042_REG_APEOVER              0x70
#define AX5042_REG_TMMUX                0x71
#define AX5042_REG_PLLVCOI              0x72
#define AX5042_REG_PLLCPEN              0x73
#define AX5042_REG_PLLRNGMISC           0x74
#define AX5042_REG_AGCMANUAL            0x78
#define AX5042_REG_ADCDCLEVEL           0x79
#define AX5042_REG_RFMISC               0x7a
#define AX5042_REG_TXDRIVER             0x7b
#define AX5042_REG_REF                  0x7c
#define AX5042_REG_RXMISC               0x7d

#define AX5042_IRQMFIFONOTEMPTY         0x01
#define AX5042_IRQMFIFONOTFULL          0x02
#define AX5042_IRQMPLLUNLOCK            0x04
#define AX5042_IRQMPLLRNGDONE           0x08

#define AX5042_IRQRQFIFONOTEMPTY        0x01
#define AX5042_IRQRQFIFONOTFULL         0x02
#define AX5042_IRQRQPLLUNLOCK           0x04
#define AX5042_IRQRQPLLRNGDONE          0x08
#define AX5042_REG_PINCFG2_IRQ_TXENI    0x02


#define AX5042_REG_APEOVER_POWERDOWN 0x80
#define AX5042_REG_PWRMODE_POWERDOWN 0x00
#define AX5042_REG_PWRMODE_RST 0x80

#define AX5042_REG_APEOVER_ON 0x00
#define AX5042_REG_PWRMODE_STANDBY 0x60
#define AX5042_REG_PWRMODE_SYNTHRX 0x68
#define AX5042_REG_PWRMODE_FULLRX 0x69
#define AX5042_REG_PWRMODE_SYNTHTX 0x6C
#define AX5042_REG_PWRMODE_FULLTX 0x6D

#define AX5042_BANDSEL_433MHZ 0x20

#define AX5042_FEC_FECENA 0x01
#define AX5042_FEC_FECNEG 0x20
#define AX5042_FEC_FECPOS 0x10
#define AX5042_FEC_RESET 0x40

#define AX5042_RSSI1_COARSE  0x01
#define AX5042_RSSI2_FINE    0x02
#define AX5042_RSSI_ALL      (AX5042_RSSI1_COARSE | AX5042_RSSI2_FINE) 

#define PKT_MTU 1500

struct ax5042_regdump {
   unsigned char regvalues[0x80];
   unsigned char regnums[0x80];
};

struct ax5042_commparams {
   double carrierFreq, crystalFreq;
   double intermediateFreq, h;
   uint32_t bitrate, tmgCorrFrac;
   uint8_t modulation, encoding, framing, crc;
   uint8_t fec;

   uint32_t freq, fskdev, txrate;
   uint16_t iffreq, cicdec, datarate, tmggain;
   uint8_t pllloop, mod, agcattack, agcdecay;
   uint8_t phasegain, freqgain, freqgain2, amplgain;
   uint8_t enc, frm, txpwr;
   int queue_num;

   uint8_t has1byte_addr, has5byte_addr;
   uint8_t addr1;
   uint8_t addr5[5];
};

struct ax5042_regstate {
   unsigned char regvalues[0x80];
   unsigned char updated[0x80];
   unsigned char set[0x80];
};

struct ax5042_pkt_header {
   uint32_t pkt_num;
   uint16_t trkfreq;
   int8_t rssi1, rssi2;
   struct timeval rx_time;
   uint8_t rx_queue;
};

/*
struct ax5042_rssi_stat {
   int8_t rssi1, rssi2;
   int8_t agcref, agc;
};
*/

struct ax5042_doppler_correction {
   struct timespec start_time, end_time;
   int32_t rx_correction;
};

struct ax5042_rssi_stat {
   int agc;
   int rssi1;
   int rssi2;
   int trkampl;
   int agcref_precomp;
   int cicdec;
   int cicshift;
};

struct ax5042_stats {
   unsigned int abortCnt, pktBuffOverrunCnt, pktCnt;
   unsigned int badSizeCnt, invalidCrcCnt, underrunCnt;
   unsigned int overrunCnt, spiErrCnt, readAgainCnt;
   unsigned int fifoReadCnt, fifoctlReadCnt, shortReadCnt;
   unsigned int delmCnt, plllockCnt, trkfreqReadCnt, pktstatReadCnt;
   unsigned int fifoWriteCnt, pktTxCnt, batchCnt;
};

typedef void (*AX5042_rxtx_trigger_cb)(int triggerTx, void *arg);
extern void AX5042_set_radio_trigger_cb(AX5042_rxtx_trigger_cb cb, void *arg);
extern void AX5042_set_min_rx_to_tx_wait_in_ms(int ms);
extern void AX5042_set_min_tx_to_rx_wait_in_ms(int ms);

#define AX5042_IOC_MAGIC 'x'
#define AX5042_IOGREGDUMP _IOR(AX5042_IOC_MAGIC, 1, struct ax5042_regdump)
#define AX5042_IOWREGDUMP _IOW(AX5042_IOC_MAGIC, 2, struct ax5042_regdump)
#define AX5042_IOWREGSTATE _IOW(AX5042_IOC_MAGIC, 3, struct ax5042_commparams)
#define AX5042_IOWMODE _IOW(AX5042_IOC_MAGIC, 4, int)
#define AX5042_IOGSTATUS _IOR(AX5042_IOC_MAGIC, 5, char)
#define AX5042_IOGFIFODATA _IOR(AX5042_IOC_MAGIC, 6, uint16_t)
#define AX5042_IOGFIFOCTRL _IOR(AX5042_IOC_MAGIC, 7, uint16_t)
#define AX5042_IORWSPI _IOW(AX5042_IOC_MAGIC, 8, unsigned char)
#define AX5042_IOWAIT4RX _IOW(AX5042_IOC_MAGIC, 9, int)
#define AX5042_IOWRXHOLDTIME _IOW(AX5042_IOC_MAGIC, 10, int)
#define AX5042_IOWTXBATCHDUR _IOW(AX5042_IOC_MAGIC, 11, int)
#define AX5042_IOADDDOPPLER _IOW(AX5042_IOC_MAGIC, 12, struct ax5042_doppler_correction)
#define AX5042_IOSETRXQUEUE _IOW(AX5042_IOC_MAGIC, 13, int)
//#define AX5042_IORSSI _IOR(AX5042_IOC_MAGIC, 14, struct ax5042_rssi_stat)
#define AX5042_IOGRSSI _IOR(AX5042_IOC_MAGIC, 15, struct ax5042_rssi_stat)
#define AX5042_IOGSTATS _IOR(AX5042_IOC_MAGIC, 16, struct ax5042_stats)

#endif
