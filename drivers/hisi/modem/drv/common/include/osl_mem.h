#ifndef __OSL_MEM_H
#define __OSL_MEM_H

#if defined(__OS_RTOSCK__)||defined(__OS_RTOSCK_SMP__)
#include <product_config.h>
#include <sre_buildef.h>
#include <sre_config.h>
/*
*用于标记需要在操作系统启动之前的初始化的模块
*
*PS:一旦被标记就不允许修改代码和变量
*/
#define  __sys_entry_init   __attribute__((section(".text.entry.init")))

#ifdef CONFIG_CCPU_HAS_TCM
/*
*用于标记存放在TCM中的函数和数据
*__tcmdata                用于标记放置在DTCM中的数据
*__tcmfunc                用于标记放置在ITCM中的函数，支持普通函数调用
*__tcmlocalfunc          用于标记放置在ITCM中的函数，不支持普通函数调用
*
*PS:存放在TCM中的函数尽量不要调用未加__tcmlocalfunc标记的函数
*/
#define __tcmdata           __attribute__((section(".tcm.data")))

#define __tcmfunc  __attribute__((section(".tcm.text")))

#else
#define __tcmdata
#define __tcmfunc
#endif

#ifdef CONFIG_CCPU_HAS_LLRAM
/*
*用于标记存放在LLRAM中数据
*__llramdata                用于标记放置在LLRAM中的数据
*
*PS:LLRAM中不放置函数，只放置数据
*/

#define __llramdata         __attribute__((section(".llram.data"))) 

/*支持LLRAM空间动态获取*/
#define  LLRAM_MEM_POOL_INDEX          (OS_MEM_MAX_PT_NUM -1)     /*OS 内存分区号*/

/*LLRAM 申请接口内部实现强制4字节对齐，失败为NULL*/
void* osl_llram_malloc(unsigned int size);

/*LLRAM释放，失败为非空*/
unsigned int osl_llram_free(void *free_addr);
#else
#define __llramdata

static inline void* osl_llram_malloc(unsigned int size){return NULL;}
static inline unsigned int osl_llram_free(void *free_addr){return (unsigned int)0;}
#endif
#else
#define __sys_entry_init
#define __tcmdata  
#define __tcmfunc       
#define __llramdata    
#endif
#endif
