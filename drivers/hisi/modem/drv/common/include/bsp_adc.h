/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef __BSP_ADC_H__
#define __BSP_ADC_H__

extern u32 g_adc_level;
extern u32 g_last_convert_time;
extern u32 g_last_power_on_time;
#define adc_log(fmt,...) (bsp_trace(BSP_LOG_LEVEL_ERROR, BSP_MODU_HKADC, "[adc]:[func: %s],[line: %d]"fmt"\n", __FUNCTION__, __LINE__, ##__VA_ARGS__))
#define adc_dbg(fmt,...) (bsp_trace(g_adc_level, BSP_MODU_HKADC, "[adc]:[func: %s],[line: %d]"fmt"\n", __FUNCTION__, __LINE__, ##__VA_ARGS__))

#define ADC_ICC_CHN_MCORE_CCORE (ICC_CHN_MCORE_CCORE << 16 | MCORE_CCORE_FUNC_HKADC)
#define ADC_ICC_CHN_MCORE_ACORE (ICC_CHN_MCORE_ACORE << 16 | MCORE_ACORE_FUNC_HKADC)

#define HKADC_REFER_VCC (1800)
#ifndef BSP_CONFIG_PHONE_TYPE
#define HKADC_PRECISION         (10)
#else
#define HKADC_PRECISION         (1)
#endif

enum ADC_CHANNEL_ID{
    ADC_CHANNEL_MIN = 0,                    /*0*/
    /**********HKADC**********/
    HKADC_CHANNEL_MIN = ADC_CHANNEL_MIN,    /*0*/
    HKADC_CHANNEL_0 = HKADC_CHANNEL_MIN,    /*0*/
    HKADC_CHANNEL_1,                        /*1*/
    HKADC_CHANNEL_2,                        /*2*/
    HKADC_CHANNEL_3,                        /*3*/
    HKADC_CHANNEL_4,                        /*4*/
    HKADC_CHANNEL_5,                        /*5*/
    HKADC_CHANNEL_6,                        /*6*/
    HKADC_CHANNEL_7,                        /*7*/
    HKADC_CHANNEL_8,                        /*8*/
    HKADC_CHANNEL_9,                        /*9*/
    HKADC_CHANNEL_10,                       /*10*/
    HKADC_CHANNEL_11,                       /*11*/
    HKADC_CHANNEL_12,                       /*12*/
    HKADC_CHANNEL_13,                       /*13*/
    HKADC_CHANNEL_14,                       /*14*/
    HKADC_CHANNEL_MAX,                      /*15*/
    /********HKADC END********/
    /**********XOADC**********/
    XOADC_CHANNEL_MIN = HKADC_CHANNEL_MAX,  /*15*/
    XOADC_CHANNEL_0 = XOADC_CHANNEL_MIN,    /*15*/
    XOADC_CHANNEL_MAX,                      /*16*/
    /********XOADC END********/
    ADC_CHANNEL_MAX = XOADC_CHANNEL_MAX,    /*16*/
};

s32 bsp_adc_convert(u32 channel_id, u16* value);

#ifdef CONFIG_ADC_HI6421V600

extern void pmic_reg_write(u32 addr, u32 value);
extern void pmic_reg_read(u32 addr, u32 *pValue);

static inline void adc_reg_wr(u32 addr, u32 value)
{
    pmic_reg_write(addr, value);
    return;
}

static inline void adc_reg_rd(u32 addr, u32 *value)
{
    pmic_reg_read(addr, value);
    return;
}

#else

#define HKADC_TWO_INSTRUCTION_DELAY (0xF00043)

#endif

#endif
