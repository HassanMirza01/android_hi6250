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
#ifndef __BSP_WP_H__
#define __BSP_WP_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <product_config.h>
#include "osl_types.h"
#include "drv_comm.h"

enum
{
    WATCHPOINT_R    = 1,
    WATCHPOINT_W    = 2,
    WATCHPOINT_RW   = WATCHPOINT_R | WATCHPOINT_W,
    WATCHPOINT_X    = 4,
};

enum
{
    WP_EVENT_INFO_HANDLER           = 1,
    WP_EVENT_SUSPEND_HANDLER        = 2,
    WP_EVENT_INFO_SUSPEND_HANDLER   = WP_EVENT_INFO_HANDLER | WP_EVENT_SUSPEND_HANDLER,
    WP_EVENT_RESET_HANDLER          = 4,
    WP_EVENT_NO_HANDLER             = 8,
};

enum
{
    WP_TRIGGER_ALL_STATE          = 0,
    WP_TRIGGER_NO_SECURE_STATE    = 1,
    WP_TRIGGER_SECURE_STATE       = 2,
    WP_TRIGGER_DEFAULT
};


typedef void (*wp_event_callback)(void* regs);


#ifdef CONFIG_WATCHPOINT
/* 注册watchpoint做地址范围监控时，需要选择合适的范围，由于watchpoint实现机制限制，通常会扩大监控范围
 * watchpoint匹配规则: 满足(访问地址 & ~mask == 监控起始地址 & ~mask), 则触发watchpoint异常
 * mask计算规则: start_addr与end_addr二进制表示的公共前缀长度为n，mask = (1 << (32 - n)) - 1
 * 示例: start_addr = 0x55600014, end_addr = 0x55600028, mask = 0b111111，实际监控范围为0x55600000~0x55600040
 */

int bsp_wp_register(void *addr, unsigned int len, unsigned int type,unsigned int way,unsigned int scope,wp_event_callback cb);
int bsp_wp_enable(int wp_id);
int bsp_wp_disable(int wp_id);
int bsp_wp_unregister(int wp_id);
int bsp_wp_init(void);

#else
static int inline bsp_wp_register(void *addr, unsigned int len, unsigned int type,unsigned int way,unsigned int scope,wp_event_callback cb)
{
    return BSP_OK;
}

static int inline bsp_wp_enable(int wp_id)
{
    return BSP_OK;
}

static int inline bsp_wp_disable(int wp_id)
{
    return BSP_OK;
}

static int inline bsp_wp_unregister(int wp_id)
{
    return BSP_OK;
}

static int inline bsp_wp_init(void)
{
    return BSP_OK;
}

#endif

#ifdef __cplusplus
}
#endif

#endif //__BSP_WP_H__

