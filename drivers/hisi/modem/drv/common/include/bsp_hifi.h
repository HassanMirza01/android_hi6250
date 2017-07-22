#ifndef __BSP_HIFI__
#define __BSP_HIFI__

#include <product_config.h>

#ifdef CONFIG_HIFI
int boot_hifi_from_flash(void);
#else
static inline int boot_hifi_from_flash(void)
{
	return 0;
}
#endif

#endif
