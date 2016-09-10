/*
 * Register definitions for the Atmel Image Sensor Interface.
 *
 * Copyright (C) 2006 Atmel Corporation
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#ifndef __ASM_AVR32_ISI_H__
#define __ASM_AVR32_ISI_H__

#include <linux/videodev2.h>

#define SYNC_CCIR656 0

/* ISI register offsets */
#define ISI_CR1					0x0000
#define ISI_CR2					0x0004
#define ISI_SR					0x0008
#define ISI_IER					0x000c
#define ISI_IDR					0x0010
#define ISI_IMR					0x0014
#define ISI_PSIZE				0x0020
#define ISI_PDECF				0x0024
#define ISI_PPFBD				0x0028
#define ISI_CDBA				0x002c
#define ISI_Y2R_SET0				0x0030
#define ISI_Y2R_SET1				0x0034
#define ISI_R2Y_SET0				0x0038
#define ISI_R2Y_SET1				0x003c
#define ISI_R2Y_SET2				0x0040

/* ISI_V2 register offsets */
#define ISI_V2_CFG1				0x0000
#define ISI_V2_CFG2				0x0004
#define ISI_V2_PSIZE				0x0008
#define ISI_V2_PDECF				0x000c
#define ISI_V2_Y2R_SET0				0x0010
#define ISI_V2_Y2R_SET1				0x0014
#define ISI_V2_R2Y_SET0				0x0018
#define ISI_V2_R2Y_SET1				0x001C
#define ISI_V2_R2Y_SET2				0x0020
#define ISI_V2_CTRL				0x0024
#define ISI_V2_STATUS				0x0028
#define ISI_V2_INTEN				0x002C
#define ISI_V2_INTDIS				0x0030
#define ISI_V2_INTMASK				0x0034
#define ISI_V2_DMA_CHER				0x0038
#define ISI_V2_DMA_CHDR				0x003C
#define ISI_V2_DMA_CHSR				0x0040
#define ISI_V2_DMA_P_ADDR			0x0044
#define ISI_V2_DMA_P_CTRL			0x0048
#define ISI_V2_DMA_P_DSCR			0x004C
#define ISI_V2_DMA_C_ADDR			0x0050
#define ISI_V2_DMA_C_CTRL			0x0054
#define ISI_V2_DMA_C_DSCR			0x0058

/* Bitfields in CR1 */
#define ISI_RST_OFFSET				0
#define ISI_RST_SIZE				1
#define ISI_DIS_OFFSET				1
#define ISI_DIS_SIZE				1
#define ISI_HSYNC_POL_OFFSET			2
#define ISI_HSYNC_POL_SIZE			1
#define ISI_VSYNC_POL_OFFSET			3
#define ISI_VSYNC_POL_SIZE			1
#define ISI_PIXCLK_POL_OFFSET			4
#define ISI_PIXCLK_POL_SIZE			1
#define ISI_EMB_SYNC_OFFSET			6
#define ISI_EMB_SYNC_SIZE			1
#define ISI_CRC_SYNC_OFFSET			7
#define ISI_CRC_SYNC_SIZE			1
#define ISI_FRATE_OFFSET			8
#define ISI_FRATE_SIZE				3
#define ISI_FULL_OFFSET				12
#define ISI_FULL_SIZE				1
#define ISI_THMASK_OFFSET			13
#define ISI_THMASK_SIZE				2
#define ISI_CODEC_ON_OFFSET			15
#define ISI_CODEC_ON_SIZE			1
#define ISI_SLD_OFFSET				16
#define ISI_SLD_SIZE				8
#define ISI_SFD_OFFSET				24
#define ISI_SFD_SIZE				8

/* Bitfields in CFG1 */
#define ISI_V2_HSYNC_POL_OFFSET			2
#define ISI_V2_HSYNC_POL_SIZE			1
#define ISI_V2_VSYNC_POL_OFFSET			3
#define ISI_V2_VSYNC_POL_SIZE			1
#define ISI_V2_PIXCLK_POL_OFFSET		4
#define ISI_V2_PIXCLK_POL_SIZE			1
#define ISI_V2_EMB_SYNC_OFFSET			6
#define ISI_V2_EMB_SYNC_SIZE			1
#define ISI_V2_CRC_SYNC_OFFSET			7
#define ISI_V2_CRC_SYNC_SIZE			1
#define ISI_V2_FRATE_OFFSET			8
#define ISI_V2_FRATE_SIZE			3
#define ISI_V2_FULL_OFFSET			12
#define ISI_V2_FULL_SIZE			1
#define ISI_V2_THMASK_OFFSET			13
#define ISI_V2_THMASK_SIZE			2
#define ISI_V2_SLD_OFFSET			16
#define ISI_V2_SLD_SIZE				8
#define ISI_V2_SFD_OFFSET			24
#define ISI_V2_SFD_SIZE				8

/* Bitfields in CR2 */
#define ISI_IM_VSIZE_OFFSET			0
#define ISI_IM_VSIZE_SIZE			11
#define ISI_GS_MODE_OFFSET			11
#define ISI_GS_MODE_SIZE			1
#define ISI_RGB_MODE_OFFSET			12
#define ISI_RGB_MODE_SIZE			1
#define ISI_GRAYSCALE_OFFSET			13
#define ISI_GRAYSCALE_SIZE			1
#define ISI_RGB_SWAP_OFFSET			14
#define ISI_RGB_SWAP_SIZE			1
#define ISI_COL_SPACE_OFFSET			15
#define ISI_COL_SPACE_SIZE			1
#define ISI_IM_HSIZE_OFFSET			16
#define ISI_IM_HSIZE_SIZE			11
#define ISI_YCC_SWAP_OFFSET			28
#define ISI_YCC_SWAP_SIZE			2
#define ISI_RGB_CFG_OFFSET			30
#define ISI_RGB_CFG_SIZE			2

/* Bitfields in CFG2 */
#define ISI_V2_IM_VSIZE_OFFSET			0
#define ISI_V2_IM_VSIZE_SIZE			11
#define ISI_V2_GS_MODE_OFFSET			11
#define ISI_V2_GS_MODE_SIZE			1
#define ISI_V2_RGB_MODE_OFFSET			12
#define ISI_V2_RGB_MODE_SIZE			1
#define ISI_V2_GRAYSCALE_OFFSET			13
#define ISI_V2_GRAYSCALE_SIZE			1
#define ISI_V2_RGB_SWAP_OFFSET			14
#define ISI_V2_RGB_SWAP_SIZE			1
#define ISI_V2_COL_SPACE_OFFSET			15
#define ISI_V2_COL_SPACE_SIZE			1
#define ISI_V2_IM_HSIZE_OFFSET			16
#define ISI_V2_IM_HSIZE_SIZE			11
#define ISI_V2_YCC_SWAP_OFFSET			28
#define ISI_V2_YCC_SWAP_SIZE			2
#define ISI_V2_RGB_CFG_OFFSET			30
#define ISI_V2_RGB_CFG_SIZE			2

/* Bitfields in CTRL */
#define ISI_V2_EN_OFFSET			0
#define ISI_V2_EN_SIZE				1
#define ISI_V2_DIS_OFFSET			1
#define ISI_V2_DIS_SIZE				1
#define ISI_V2_SRST_OFFSET			2
#define ISI_V2_SRST_SIZE			1
#define ISI_V2_CDC_OFFSET			8
#define ISI_V2_CDC_SIZE				1

/* Bitfields in SR/IER/IDR/IMR */
#define ISI_SOF_OFFSET				0
#define ISI_SOF_SIZE				1
#define ISI_SOFTRST_OFFSET			2
#define ISI_SOFTRST_SIZE			1
#define ISI_CDC_STATUS_OFFSET			3
#define ISI_CDC_STATUS_SIZE			1
#define ISI_CRC_ERR_OFFSET			4
#define ISI_CRC_ERR_SIZE			1
#define ISI_FO_C_OVF_OFFSET			5
#define ISI_FO_C_OVF_SIZE			1
#define ISI_FO_P_OVF_OFFSET			6
#define ISI_FO_P_OVF_SIZE			1
#define ISI_FO_P_EMP_OFFSET			7
#define ISI_FO_P_EMP_SIZE			1
#define ISI_FO_C_EMP_OFFSET			8
#define ISI_FO_C_EMP_SIZE			1
#define ISI_FR_OVR_OFFSET			9
#define ISI_FR_OVR_SIZE				1

/* Bitfields in SR/IER/IDR/IMR(ISI_V2) */
#define ISI_V2_ENABLE_OFFSET			0
#define ISI_V2_ENABLE_SIZE			1
#define ISI_V2_DIS_DONE_OFFSET			1
#define ISI_V2_DIS_DONE_SIZE			1
#define ISI_V2_SRST_OFFSET			2
#define ISI_V2_SRST_SIZE			1
#define ISI_V2_CDC_STATUS_OFFSET		8
#define ISI_V2_CDC_STATUS_SIZE			1
#define ISI_V2_VSYNC_OFFSET			10
#define ISI_V2_VSYNC_SIZE			1
#define ISI_V2_PXFR_DONE_OFFSET			16
#define ISI_V2_PXFR_DONE_SIZE			1
#define ISI_V2_CXFR_DONE_OFFSET			17
#define ISI_V2_CXFR_DONE_SIZE			1
#define ISI_V2_P_OVR_OFFSET			24
#define ISI_V2_P_OVR_SIZE			1
#define ISI_V2_C_OVR_OFFSET			25
#define ISI_V2_C_OVR_SIZE			1
#define ISI_V2_CRC_ERR_OFFSET			26
#define ISI_V2_CRC_ERR_SIZE			1
#define ISI_V2_FR_OVR_OFFSET			27
#define ISI_V2_FR_OVR_SIZE			1

/* Bitfields in PSIZE */
#define ISI_PREV_VSIZE_OFFSET			0
#define ISI_PREV_VSIZE_SIZE			10
#define ISI_PREV_HSIZE_OFFSET			16
#define ISI_PREV_HSIZE_SIZE			10

/* Bitfields in PSIZE(ISI_V2) */
#define ISI_V2_PREV_VSIZE_OFFSET		0
#define ISI_V2_PREV_VSIZE_SIZE			10
#define ISI_V2_PREV_HSIZE_OFFSET		16
#define ISI_V2_PREV_HSIZE_SIZE			10

/* Bitfields in PCDEF */
#define ISI_DEC_FACTOR_OFFSET			0
#define ISI_DEC_FACTOR_SIZE			8

/* Bitfields in PCDEF */
#define ISI_V2_DEC_FACTOR_OFFSET		0
#define ISI_V2_DEC_FACTOR_SIZE			8

/* Bitfields in PPFBD */
#define ISI_PREV_FBD_ADDR_OFFSET		0
#define ISI_PREV_FBD_ADDR_SIZE			32

/* Bitfields in CDBA */
#define ISI_CODEC_DMA_ADDR_OFFSET		0
#define ISI_CODEC_DMA_ADDR_SIZE			32

/* Bitfields in DMA_C_ADDR */
#define ISI_V2_DMA_ADDR_OFFSET			0
#define ISI_V2_DMA_ADDR_SIZE			32

/* Bitfields in DMA_C_CTRL & in DMA_P_CTRL */
#define ISI_V2_DMA_FETCH_OFFSET			0
#define ISI_V2_DMA_FETCH_SIZE			1
#define ISI_V2_DMA_WB_OFFSET			1
#define ISI_V2_DMA_WB_SIZE			1
#define ISI_V2_DMA_IEN_OFFSET			2
#define ISI_V2_DMA_IEN_SIZE			1
#define ISI_V2_DMA_DONE_OFFSET			3
#define ISI_V2_DMA_DONE_SIZE			1

/* Bitfields in DMA_CHER */
#define ISI_V2_DMA_P_CH_EN_OFFSET		0
#define ISI_V2_DMA_P_CH_EN_SIZE			1
#define ISI_V2_DMA_C_CH_EN_OFFSET		1
#define ISI_V2_DMA_C_CH_EN_SIZE			1

/* Bitfields in Y2R_SET0 */
#define ISI_Y2R_SET0_C3_OFFSET			24
#define ISI_Y2R_SET0_C3_SIZE			8

/* Bitfields in Y2R_SET0(ISI_V2) */
#define ISI_V2_Y2R_SET0_C3_OFFSET		24
#define ISI_V2_Y2R_SET0_C3_SIZE			8

/* Bitfields in Y2R_SET1 */
#define ISI_Y2R_SET1_C4_OFFSET			0
#define ISI_Y2R_SET1_C4_SIZE			9
#define ISI_YOFF_OFFSET				12
#define ISI_YOFF_SIZE				1
#define ISI_CROFF_OFFSET			13
#define ISI_CROFF_SIZE				1
#define ISI_CBOFF_OFFSET			14
#define ISI_CBOFF_SIZE				1

/* Bitfields in Y2R_SET1(ISI_V2) */
#define ISI_V2_Y2R_SET1_C4_OFFSET		0
#define ISI_V2_Y2R_SET1_C4_SIZE			9
#define ISI_V2_YOFF_OFFSET			12
#define ISI_V2_YOFF_SIZE			1
#define ISI_V2_CROFF_OFFSET			13
#define ISI_V2_CROFF_SIZE			1
#define ISI_V2_CBOFF_OFFSET			14
#define ISI_V2_CBOFF_SIZE			1

/* Bitfields in R2Y_SET0 */
#define ISI_C0_OFFSET				0
#define ISI_C0_SIZE				8
#define ISI_C1_OFFSET				8
#define ISI_C1_SIZE				8
#define ISI_C2_OFFSET				16
#define ISI_C2_SIZE				8
#define ISI_ROFF_OFFSET				24
#define ISI_ROFF_SIZE				1

/* Bitfields in R2Y_SET0(ISI_V2) */
#define ISI_V2_C0_OFFSET			0
#define ISI_V2_C0_SIZE				8
#define ISI_V2_C1_OFFSET			8
#define ISI_V2_C1_SIZE				8
#define ISI_V2_C2_OFFSET			16
#define ISI_V2_C2_SIZE				8
#define ISI_V2_ROFF_OFFSET			24
#define ISI_V2_ROFF_SIZE			1

/* Bitfields in R2Y_SET1 */
#define ISI_R2Y_SET1_C3_OFFSET			0
#define ISI_R2Y_SET1_C3_SIZE			8
#define ISI_R2Y_SET1_C4_OFFSET			8
#define ISI_R2Y_SET1_C4_SIZE			8
#define ISI_C5_OFFSET				16
#define ISI_C5_SIZE				8
#define ISI_GOFF_OFFSET				24
#define ISI_GOFF_SIZE				1

/* Bitfields in R2Y_SET1(ISI_V2) */
#define ISI_V2_R2Y_SET1_C3_OFFSET		0
#define ISI_V2_R2Y_SET1_C3_SIZE			8
#define ISI_V2_R2Y_SET1_C4_OFFSET		8
#define ISI_V2_R2Y_SET1_C4_SIZE			8
#define ISI_V2_C5_OFFSET			16
#define ISI_V2_C5_SIZE				8
#define ISI_V2_GOFF_OFFSET			24
#define ISI_V2_GOFF_SIZE			1

/* Bitfields in R2Y_SET2 */
#define ISI_C6_OFFSET				0
#define ISI_C6_SIZE				8
#define ISI_C7_OFFSET				8
#define ISI_C7_SIZE				8
#define ISI_C8_OFFSET				16
#define ISI_C8_SIZE				8
#define ISI_BOFF_OFFSET				24
#define ISI_BOFF_SIZE				1

/* Bitfields in R2Y_SET2(ISI_V2) */
#define ISI_V2_C6_OFFSET			0
#define ISI_V2_C6_SIZE				8
#define ISI_V2_C7_OFFSET			8
#define ISI_V2_C7_SIZE				8
#define ISI_V2_C8_OFFSET			16
#define ISI_V2_C8_SIZE				8
#define ISI_V2_BOFF_OFFSET			24
#define ISI_V2_BOFF_SIZE			1

/* Constants for FRATE */
#define ISI_FRATE_CAPTURE_ALL			0

/* Constants for FRATE(ISI_V2) */
#define ISI_V2_FRATE_CAPTURE_ALL		0

/* Constants for YCC_SWAP */
#define ISI_YCC_SWAP_DEFAULT			0
#define ISI_YCC_SWAP_MODE_1			1
#define ISI_YCC_SWAP_MODE_2			2
#define ISI_YCC_SWAP_MODE_3			3

/* Constants for YCC_SWAP(ISI_V2) */
#define ISI_V2_YCC_SWAP_DEFAULT			0
#define ISI_V2_YCC_SWAP_MODE_1			1
#define ISI_V2_YCC_SWAP_MODE_2			2
#define ISI_V2_YCC_SWAP_MODE_3			3

/* Constants for RGB_CFG */
#define ISI_RGB_CFG_DEFAULT			0
#define ISI_RGB_CFG_MODE_1			1
#define ISI_RGB_CFG_MODE_2			2
#define ISI_RGB_CFG_MODE_3			3

/* Constants for RGB_CFG(ISI_V2) */
#define ISI_V2_RGB_CFG_DEFAULT			0
#define ISI_V2_RGB_CFG_MODE_1			1
#define ISI_V2_RGB_CFG_MODE_2			2
#define ISI_V2_RGB_CFG_MODE_3			3

/* Bit manipulation macros */
#define ISI_BIT(name)					\
	(1 << ISI_##name##_OFFSET)
#define ISI_BF(name,value)				\
	(((value) & ((1 << ISI_##name##_SIZE) - 1))	\
	 << ISI_##name##_OFFSET)
#define ISI_BFEXT(name,value)				\
	(((value) >> ISI_##name##_OFFSET)		\
	 & ((1 << ISI_##name##_SIZE) - 1))
#define ISI_BFINS(name,value,old)			\
	(((old) & ~(((1 << ISI_##name##_SIZE) - 1)	\
		    << ISI_##name##_OFFSET))\
	 | ISI_BF(name,value))

/* Register access macros */
#define isi_readl(port,reg)				\
	__raw_readl((port)->regs + ISI_##reg)
#define isi_writel(port,reg,value)			\
	__raw_writel((value), (port)->regs + ISI_##reg)

#define ATMEL_V4L2_VID_FLAGS ( V4L2_CAP_VIDEO_OUTPUT )

struct atmel_isi;

enum atmel_isi_pixfmt {
	ATMEL_ISI_PIXFMT_GREY,		/* Greyscale */
	ATMEL_ISI_PIXFMT_CbYCrY,
	ATMEL_ISI_PIXFMT_CrYCbY,
	ATMEL_ISI_PIXFMT_YCbYCr,
	ATMEL_ISI_PIXFMT_YCrYCb,
	ATMEL_ISI_PIXFMT_RGB24,
	ATMEL_ISI_PIXFMT_BGR24,
	ATMEL_ISI_PIXFMT_RGB16,
	ATMEL_ISI_PIXFMT_BGR16,
	ATMEL_ISI_PIXFMT_GRB16,		/* G[2:0] R[4:0]/B[4:0] G[5:3] */
	ATMEL_ISI_PIXFMT_GBR16,		/* G[2:0] B[4:0]/R[4:0] G[5:3] */
	ATMEL_ISI_PIXFMT_RGB24_REV,
	ATMEL_ISI_PIXFMT_BGR24_REV,
	ATMEL_ISI_PIXFMT_RGB16_REV,
	ATMEL_ISI_PIXFMT_BGR16_REV,
	ATMEL_ISI_PIXFMT_GRB16_REV,	/* G[2:0] R[4:0]/B[4:0] G[5:3] */
	ATMEL_ISI_PIXFMT_GBR16_REV,	/* G[2:0] B[4:0]/R[4:0] G[5:3] */
};

struct atmel_isi_format {
	struct v4l2_pix_format pix;
	enum atmel_isi_pixfmt input_format;
   int input_width, input_height;
   int allow_jpeg;
};

struct isi_platform_data {
	u16 image_hsize;
	u16 image_vsize;
	u16 prev_hsize;
	u16 prev_vsize;
	u16 cr1_flags;
#define ISI_HSYNC_ACT_LOW	0x01
#define ISI_VSYNC_ACT_LOW	0x02
#define ISI_PXCLK_ACT_FALLING	0x04
#define ISI_EMB_SYNC		0x08
#define ISI_CRC_SYNC		0x10
#define ISI_FULL		0x20
	u8 gs_mode;
#define ISI_GS_2PIX_PER_WORD	0x00
#define ISI_GS_1PIX_PER_WORD	0x01
	u8 pixfmt;
	u8 sfd;
	u8 sld;
	u8 thmask;
#define ISI_BURST_4_8_16	0x00
#define ISI_BURST_8_16		0x01
#define ISI_BURST_16		0x02
	u8 frate;
#define ISI_FRATE_DIV_2		0x01
#define ISI_FRATE_DIV_3		0x02
#define ISI_FRATE_DIV_4		0x03
#define ISI_FRATE_DIV_5		0x04
#define ISI_FRATE_DIV_6		0x05
#define ISI_FRATE_DIV_7		0x06
#define ISI_FRATE_DIV_8		0x07
	int capture_v4l2_fmt;	
	int streaming_v4l2_fmt;
   void *bootmem;
   int bootmemSize;
};

struct atmel_isi_camera {
	const char		*name;
	struct module		*owner;
	struct list_head	list;
	unsigned int		hsync_act_low:1;
	unsigned int		vsync_act_low:1;
	unsigned int		pclk_act_falling:1;
	unsigned int		has_emb_sync:1;
	unsigned int		always_on_gpio_act_high:1;
	/* ISI supports up to 17 formats */
	unsigned int		pixelformats[17];
	int (*get_format)(struct atmel_isi_camera *cam,
			  struct atmel_isi_format *fmt);
	int (*set_format)(struct atmel_isi_camera *cam,
			  struct atmel_isi_format *fmt);
	int (*initial_format)(struct atmel_isi_camera *cam,
			  struct atmel_isi_format *fmt);
	int (*check_format)(struct atmel_isi_camera *cam,
			  struct atmel_isi_format *fmt);
	int (*start_capture)(struct atmel_isi_camera *cam,
			  struct atmel_isi_format *fmt);
	int (*stop_capture)(struct atmel_isi_camera *cam);
   int (*set_power_state)(struct atmel_isi_camera *cam, int on);
   int (*reprogram)(struct atmel_isi_camera *cam);
   int (*queryctrl)(struct atmel_isi_camera *cam, struct v4l2_queryctrl*);
   int (*get_ctrl)(struct atmel_isi_camera *cam, struct v4l2_control*);
   int (*set_ctrl)(struct atmel_isi_camera *cam, struct v4l2_control*);
   int (*data_conversion)(struct atmel_isi_camera *cam, void *data,
         size_t *data_len);
	struct atmel_isi	*isi;
   int debug_flag;
	int		always_on_gpio;
	int		always_on_gpio_ref_cnt;
};

extern int atmel_isi_register_camera(struct atmel_isi_camera *cam);
extern void atmel_isi_unregister_camera(struct atmel_isi_camera *cam);

extern void atmel_isi_camera_off(struct atmel_isi *isi,
                  struct atmel_isi_camera *cam, int holds_list_mutex);
extern void atmel_isi_camera_on(struct atmel_isi *isi,
                  struct atmel_isi_camera *cam, int holds_list_mutex);
extern int atmel_isi_camera_probe_poweron(int always_on_gpio, int active_high);
extern void atmel_isi_camera_probe_poweroff(int always_on_gpio, int active_high,
      int gpio_needs_free);


#endif /* __ASM_AVR32_ISI_H__ */

