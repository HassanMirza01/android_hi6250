/*
 *
 * Copyright (C) 2012 Hisilicon, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/printk.h>
#include <linux/thread_info.h>
#include <linux/kdebug.h>
#include <linux/stacktrace.h>
#include <asm/stacktrace.h>
#include <linux/ftrace.h>
#include <linux/kallsyms.h>
#include <asm/smp_plat.h>
#include <linux/sched.h>

/*
 * Each cpu's sp register should be in a separeted cache line,
 */
#define CACHELINE  (64)
#define SP_REG_LEN	(CACHELINE/sizeof(unsigned long))

/*
 * Sp_reg is indexed by MPIDR. Current platform supports 2 clusters,
 * each of which is composed of 4 cpus. So we should reserve 8 CPUS.
 */
#define MAX_CPU	(8)
unsigned long sp_reg[MAX_CPU][SP_REG_LEN] __read_mostly = {{0}, {0} };
#define MAX_FUNC_CALL	(0x50)

/*
 * Dump cpu stack
 */
void mntn_show_cpustack(int cpu)
{
	unsigned int mpidr, core, i;
	u64  sp, top_st;
	struct stackframe frame;

	mpidr = (unsigned int)__cpu_logical_map[cpu];
	core = mpidr & 0x3;
	core = core + ((mpidr & 0x100) >> 6);
	if (core >= MAX_CPU) {
		pr_err("%s: CPU[%d] error mpidr =0x%x\n", __func__, cpu, mpidr);
		return;
	}
	sp = sp_reg[core][0];
	if (!sp) {
		pr_err("%s: sp is NULL\n", __func__);
		return;
	}
	top_st = ALIGN(sp, THREAD_SIZE);
	pr_info("Himntn Call trace[CPU%d]: 0x%llx  ~~ 0x%llx\n",
		cpu, sp, top_st);
	sp = sp & (~(sizeof(char *)-1));
	/* 0x10 is stack frame size of mcount. Pls check mcount_enter  */
	frame.sp = sp + 0x10;
	frame.fp = frame.sp;
	frame.pc = READ_ONCE_NOCHECK(*(unsigned long *)(sp + 8));
	for (i = 0; i < MAX_FUNC_CALL; i++) {
		unsigned long where = frame.pc;
		int ret;

		ret = unwind_frame(&frame);
		if (ret < 0)
			break;
		print_ip_sym(where);
	}
	if (i >= MAX_FUNC_CALL) {
		pr_err("%s: call trace may be corrupted!!!\n", __func__);
	}
}

/*
 * For instance, a cpu is stall and not response for IPI stop,
 * we will print it's stack.
*/
void mntn_show_stack_cpustall(void)
{
	int cpu, i;

	if (num_online_cpus() == 1)
		return;
	pr_info("[%s]:Some cpus are stall\n", __func__);
	cpu = raw_smp_processor_id();
	for (i = 0; i < NR_CPUS; i++) {
		if (!cpu_online(i))
			continue;
		if (cpu == i)
			continue;
		mntn_show_cpustack(i);
	}
}

/*
 * For rcu stall, dump other cpus stack
*/
void mntn_show_stack_othercpus(int cpu)
{
	int curr_cpu;

	curr_cpu = raw_smp_processor_id();
	/*don't dump current cpu stack */
	if (curr_cpu == cpu)
		return;

	mntn_show_cpustack(cpu);
}

