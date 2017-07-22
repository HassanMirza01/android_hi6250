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
#ifndef __OSL_SMP_H__
#define __OSL_SMP_H__
#include <sre_sys.h>
#include <osl_cpu.h>
#include <osl_list.h>
#include <osl_bio.h>
#include <osl_bitmap.h>
#include <osl_cpumask.h>
typedef struct cpumask cpumask_var_t[1];
typedef void (*smp_call_func_t)(void *info);
struct call_single_data {
	struct list_head list;
	smp_call_func_t func;
	void *info;
	u16 flags;
};

#ifdef __OS_RTOSCK_SMP__
static inline unsigned int osl_get_cpu_id(void)
{
	return SRE_GetCoreID();
}
int smp_call_function(smp_call_func_t func, void *info, int wait);
#else
static inline unsigned int osl_get_cpu_id(void)
{
	return 0;
}
static inline int up_smp_call_function(smp_call_func_t func, void *info)
{
	return 0;
}
#define smp_call_function(func, info, wait) \
			(up_smp_call_function(func, info))
#endif
#define smp_processor_id() osl_get_cpu_id()
void set_cpu_online(unsigned int cpu, bool online);
void smp_send_stop(void);
int on_each_cpu(void (*func) (void *info), void *info, int wait);
int smp_call_function_single(int cpu, smp_call_func_t func, void *info,int wait);
#endif
