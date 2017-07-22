/*
** =============================================================================
** Copyright (c) 2016  Texas Instruments Inc.
**
** This program is free software; you can redistribute it and/or modify it under
** the terms of the GNU General Public License as published by the Free Software
** Foundation; version 2.
**
** This program is distributed in the hope that it will be useful, but WITHOUT
** ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
** FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License along with
** this program; if not, write to the Free Software Foundation, Inc., 51 Franklin
** Street, Fifth Floor, Boston, MA 02110-1301, USA.
**
** File:
**     tas2560.h
**
** Description:
**     definitions and data structures for TAS2560 Android Linux driver
**
** =============================================================================
*/

#ifndef _TAS2560_H
#define _TAS2560_H

/* Page Control Register */
#define TAS2560_PAGECTL_REG			0

/* Book Control Register (available in page0 of each book) */
#define TAS2560_BOOKCTL_PAGE			0
#define TAS2560_BOOKCTL_REG			127

#define TAS2560_REG(book, page, reg)		(((book * 256 * 128) + (page * 128)) + reg)

#define TAS2560_BOOK_ID(reg)			(reg / (256 * 128))
#define TAS2560_PAGE_ID(reg)			((reg % (256 * 128)) / 128)
#define TAS2560_BOOK_REG(reg)			(reg % (256 * 128))
#define TAS2560_PAGE_REG(reg)			((reg % (256 * 128)) % 128)

/* Book0, Page0 registers */
#define TAS2560_SW_RESET_REG                    TAS2560_REG(0, 0, 1)
#define TAS2560_DEV_MODE_REG                    TAS2560_REG(0, 0, 2)
#define TAS2560_SPK_CTRL_REG                    TAS2560_REG(0, 0, 4)
#define TAS2560_MUTE_REG			TAS2560_REG(0, 0, 7)
#define TAS2560_PWR_REG				TAS2560_REG(0, 0, 7)
#define TAS2560_PWR_BIT_MASK			(0x3 << 6)
#define TAS2560_MUTE_MASK				(0x7)

#define TAS2560_SR_CTRL1			TAS2560_REG(0, 0, 8)
#define TAS2560_LOAD	                        TAS2560_REG(0, 0, 9)
#define TAS2560_SR_CTRL2			TAS2560_REG(0, 0, 13)
#define TAS2560_SR_CTRL3			TAS2560_REG(0, 0, 14)

#define TAS2560_CLK_SEL	                        TAS2560_REG(0, 0, 15)
#define TAS2560_PLL_SRC_MASK					(0xc0)
#define TAS2560_PLL_CLKIN_BCLK			(0)
#define TAS2560_PLL_CLKIN_MCLK			(1)
#define TAS2560_PLL_CLKIN_PDMCLK		(2)
#define TAS2560_PLL_P_MASK					(0x3f)

#define TAS2560_SET_FREQ                        TAS2560_REG(0, 0, 16)
#define TAS2560_PLL_J_MASK						(0x7f)

#define TAS2560_PLL_D_LSB                        TAS2560_REG(0, 0, 17)
#define TAS2560_PLL_D_MSB                        TAS2560_REG(0, 0, 18)

#define TAS2560_DAI_FMT							TAS2560_REG(0, 0, 20)
#define ASI_OFFSET_1                              			TAS2560_REG(0, 0, 22)
#define TAS2560_ASI_CFG_1						TAS2560_REG(0, 0, 24)
#define	TAS2560_DIRINV_MASK				0x3c
#define TAS2560_BCLKINV					(1 << 2)
#define TAS2560_WCLKINV					(1 << 3)
#define TAS2560_BCLKDIR					(1 << 4)
#define TAS2560_WCLKDIR					(1 << 5)

#define TAS2560_DR_BOOST_REG_2                    TAS2560_REG(0, 0, 60)
#define TAS2560_DR_BOOST_REG_1                    TAS2560_REG(0, 0, 73)
#define TAS2560_ID_REG                    TAS2560_REG(0, 0, 125)

/* Book0, Page50 registers */
#define TAS2560_FADETIME_CTRL_REG1            TAS2560_REG(0,50,16)
#define TAS2560_FADETIME_CTRL_REG2            TAS2560_REG(0,50,17)
#define TAS2560_FADETIME_CTRL_REG3            TAS2560_REG(0,50,18)
#define TAS2560_FADETIME_CTRL_REG4            TAS2560_REG(0,50,19)

#define TAS2560_HPF_CUTOFF_CTL1			TAS2560_REG(0,50, 28)
#define TAS2560_HPF_CUTOFF_CTL2			TAS2560_REG(0,50, 32)
#define TAS2560_HPF_CUTOFF_CTL3			TAS2560_REG(0,50, 36)

#define TAS2560_ISENSE_PATH_CTL1		TAS2560_REG(0,50, 40)
#define TAS2560_ISENSE_PATH_CTL2		TAS2560_REG(0,50, 44)
#define TAS2560_ISENSE_PATH_CTL3		TAS2560_REG(0,50, 48)

#define TAS2560_VLIMIT_THRESHOLD		TAS2560_REG(0,50, 60)

/* Book0, Page51 registers */
#define TAS2560_BOOST_HEAD			TAS2560_REG(0,51, 24)
#define TAS2560_BOOST_ON     			TAS2560_REG(0,51, 16)
#define TAS2560_BOOST_OFF  	 		TAS2560_REG(0,51, 20)
#define TAS2560_BOOST_TABLE_CTRL1		TAS2560_REG(0,51, 32)
#define TAS2560_BOOST_TABLE_CTRL2		TAS2560_REG(0,51, 36)
#define TAS2560_BOOST_TABLE_CTRL3		TAS2560_REG(0,51, 40)
#define TAS2560_BOOST_TABLE_CTRL4		TAS2560_REG(0,51, 44)
#define TAS2560_BOOST_TABLE_CTRL5		TAS2560_REG(0,51, 48)
#define TAS2560_BOOST_TABLE_CTRL6		TAS2560_REG(0,51, 52)
#define TAS2560_BOOST_TABLE_CTRL7		TAS2560_REG(0,51, 56)
#define TAS2560_BOOST_TABLE_CTRL8		TAS2560_REG(0,51, 60)
#define TAS2560_THERMAL_FOLDBACK		TAS2560_REG(0,51, 100)

/* Book0, Page52 registers */
#define TAS2560_VSENSE_DEL_CTL1			TAS2560_REG(0,52, 52)
#define TAS2560_VSENSE_DEL_CTL2			TAS2560_REG(0,52, 56)
#define TAS2560_VSENSE_DEL_CTL3			TAS2560_REG(0,52, 60)
#define TAS2560_VSENSE_DEL_CTL4			TAS2560_REG(0,52, 64)
#define TAS2560_VSENSE_DEL_CTL5			TAS2560_REG(0,52, 68)




#define TAS2560_DATAFORMAT_I2S			(0x0 << 2)
#define TAS2560_DATAFORMAT_DSP			(0x1 << 2)
#define TAS2560_DATAFORMAT_RIGHT_J		(0x2 << 2)
#define TAS2560_DATAFORMAT_LEFT_J			(0x3 << 2)
#define TAS2560_DATAFORMAT_MONOPCM		(0x4 << 2)

#define TAS2560_DAI_FMT_MASK			(0x7 << 2)

#define LOAD_MASK				0x18
#define LOAD_8OHM				(0)
#define LOAD_6OHM				(1)
#define LOAD_4OHM				(2)
#define UNUSED(x) ((x)=(x))

struct tas2560_register {
	int book;
	int page;
	int reg;
};

struct tas2560_dai_cfg {
	unsigned int dai_fmt;
	unsigned int tdm_delay;
};

struct tas2560_priv {
	u8 i2c_regs_status;
	struct device *dev;
	struct regmap *regmap;
	struct mutex dev_lock;
	unsigned int mnClkin;
	int mnClkid;
	bool mbPowerUp;
	unsigned int mnCurrentBook;
	unsigned int mnCurrentPage;
	int mnAddr;
	int mnLoad ;
	unsigned int mnResetGPIO;
	unsigned int mnSamplingRate ;
	unsigned int mnFrameSize;

	int (*read) (struct tas2560_priv * pTAS2555, unsigned int reg,
		unsigned int *pValue);
	int (*write) (struct tas2560_priv * pTAS2555, unsigned int reg,
		unsigned int Value);
	int (*bulk_read) (struct tas2560_priv * pTAS2555, unsigned int reg,
		unsigned char *pData, unsigned int len);
	int (*bulk_write) (struct tas2560_priv * pTAS2555, unsigned int reg,
		unsigned char *pData, unsigned int len);
	int (*update_bits) (struct tas2560_priv * pTAS2555, unsigned int reg,
		unsigned int mask, unsigned int value);

	int mnDBGCmd;
	unsigned int mnCurrentReg;
	struct mutex file_lock;

};
#endif
