#ifndef __OSL_PER_CPU_H__
#define __OSL_PER_CPU_H__
#ifdef __OS_RTOSCK_SMP__
#include <sre_percpu.h>
#define per_cpu_ptr(ptr,cpu) OS_OTHER_PER_CPU_PTR(cpu,ptr)
#define per_cpu(var, cpu) OS_OTHER_PER_CPU_GET(cpu,var)

#define DEFINE_PER_CPU_SHARED_ALIGNED(type, name)  OS_PER_CPU_DATA_DEFINE(type, name)
#define DECLARE_PER_CPU_SHARED_ALIGNED(type, name)	OS_PER_CPU_DECLARE(type, name)

#define DECLARE_PER_CPU(type, name)					OS_PER_CPU_DECLARE(type, name)
#define DEFINE_PER_CPU(type, name)		OS_PER_CPU_DATA_DEFINE(type, name)
#define this_cpu_ptr(var) OS_PER_CPU_PTR(var)

#define __get_cpu_var(var) (*this_cpu_ptr(var))

#define get_cpu_var(var) (	{ \
	{osl_task_lock();}\
	OS_PER_CPU_GET(var);\
	})
#define put_cpu_var(var) do {				\
	(void)&(var);					\
	{osl_task_unlock();}\
} while (0)

#define get_cpu_ptr(var) ({				\
	{osl_task_lock();}\
	this_cpu_ptr(var); })

#define put_cpu_ptr(var) do {				\
	(void)(var);					\
	{osl_task_unlock();}\
} while (0)
#elif defined(__OS_RTOSCK__)

#define per_cpu_ptr(ptr,cpu) (&ptr)
#define per_cpu(var, cpu) (var)

#define DEFINE_PER_CPU_SHARED_ALIGNED(type, name)  type name
#define DECLARE_PER_CPU_SHARED_ALIGNED(type, name)	 type name

#define DECLARE_PER_CPU(type, name)	 type name				
#define DEFINE_PER_CPU(type, name)		 type name
#define this_cpu_ptr(var) (&var)

#define __get_cpu_var(var) (var)

#define get_cpu_var(var) (var)
#define put_cpu_var(var) (var)

#define get_cpu_ptr(var) (&var)

#define put_cpu_ptr(var) (var)
#endif
#endif
