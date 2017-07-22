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

#ifndef __BSP_AMON_H__
#define __BSP_AMON_H__

#ifdef __cplusplus
extern "C" {
#endif


#include "osl_common.h"
#include "drv_nv_def.h"

/* Monitorº‡øÿ°¢≤…ºØID◊Ó¥Û ˝ƒø */
#define AXI_MAX_CONFIG_ID	8
#define AXI_MAX_PORT_CNT    8

#define AMON_SOC_MASK           0x1
#define AMON_CPUFAST_MASK       0x2
#define AMON_ENABLE_MASK        0x4
#define AMON_OPT_READ           0x1
#define AMON_OPT_WRITE          0x2

typedef enum amon_func
{
    AMON_CNT = 0,
    AMON_CAPT,
}AMON_FUNC;
typedef enum rst_deal
{
    CNT_ON ,
    CNT_BOOT ,
    CNT_ONCE,
}CNT_OPT;

typedef enum opt_type
{
    CNT_READ = 0x01 ,
    CNT_WRIRE = 0x10 ,
    CNT_READ_WRIRE = 0x11,
}CNT_TYPE;
typedef enum axi_config_enum
{
    AXI_CPUFAST_CONFIG,         /* CPUFAST≈‰÷√ */
    AXI_SOC_CONFIG,             /* SOC≈‰÷√ */
    AXI_CONFIG_BUTT
}AXI_CONFIG_E;
typedef struct
{
    u32 hig_count;
    u32 low_count;
}count_stru;
typedef struct
{
    count_stru read_count[AXI_MAX_CONFIG_ID];
    count_stru write_count[AXI_MAX_CONFIG_ID];
	u64			global_access_count;
	u64			monitor_time_delta;
}amon_count_stru;
typedef struct master_info
{
    char master_name[16];
    u32 master_id;      /* º‡øÿmasterid */
    u32 cnt_reg_cfg;
    u32 capt_reg_cfg;
}AMON_MASTER_INFO;
typedef struct port_info
{
    u32 port_id;
    u32 master_num;
    u32 capt_flag;
    char port_name[16];
    AMON_MASTER_INFO* master_info;
}AMON_PORT_INFO;

typedef struct port_cfg
{
    u32 port_num ;
    AMON_PORT_INFO* port_info;

}AMON_PORT_CFG;
typedef struct amon_cnt_cfg
/* AXI≈‰÷√—°‘Ò */
{
    u32 id;
    AMON_CNT_CONFIG_T cnt_cfg;
}AMON_CNT_CONFIG_S;

typedef struct
{
    u32 id;
    u32 port;
    u32 master_id;
    u32 opt_type;
}AMON_CAPT_CFG;

#if defined(ENABLE_BUILD_AMON_SOC) || defined(ENABLE_BUILD_AMON_MDM)
s32 bsp_axi_mon_cnt_cfg(u32 id,u32 port,u32 master_id,u32 addr_enable,u32 start_addr,u32 end_addr,u32 opt_type,CNT_OPT cnt_opt);
s32 bsp_axi_cnt_start(void);
s32 bsp_axi_cnt_stop(void);
s32 bsp_axi_capt_cfg(u32 id, u32 port,u32 master_id,u32 opt_type);
s32 bsp_axi_capt_start(void);
s32 bsp_axi_capt_stop(void);
s32 bsp_axi_capt_export(void);
s32 bsp_amon_init(void);
s32 bsp_axi_cnt_info_get(amon_count_stru *count);
#else
static  inline s32 bsp_amon_init(void)
{
    return 0;
}
static inline s32 bsp_axi_mon_cnt_cfg(u32 id,u32 port,u32 master_id,u32 addr_enable,u32 start_addr,u32 end_addr,u32 opt_type,CNT_OPT cnt_opt)
{
    return 0;
}
static inline  s32 bsp_axi_cnt_start(void)
{
    return 0;
}
static inline s32 bsp_axi_cnt_stop(void)
{
    return 0;
}
static inline s32  bsp_axi_capt_cfg(u32 id, u32 port,u32 master_id,u32 opt_type)
{
    return 0;
} 
static inline s32  bsp_axi_capt_start(void)
{
    return 0;
}
static inline s32  bsp_axi_capt_stop(void)
{
    return 0;
}
static inline s32  bsp_axi_capt_export(void)
{
    return 0;
}
static inline s32  bsp_axi_cnt_info_get(amon_count_stru *count)
{
    return 0;

}
#endif


#ifdef __cplusplus
}
#endif


#endif

