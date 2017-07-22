#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/of_irq.h>
#include <linux/platform_device.h>
#include <linux/input.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/version.h>

#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/regulator/consumer.h>
#include <linux/platform_device.h>
#include <linux/wakelock.h>
#include <asm/irq.h>
#include <linux/hisi/util.h>
#include <linux/kthread.h>
#include <linux/syscalls.h>

#ifdef CONFIG_LCD_ON_OFF_CHECK
#include <huawei_platform/lcd_on_off_check/lcd_on_off_check.h>
#endif

#ifdef CONFIG_HISI_BB
#include <linux/hisi/rdr_hisi_platform.h>
#include <linux/hisi/rdr_pub.h>
#endif
typedef struct _lcd_on_off_check_timer {
	struct timer_list lcd_timer;
	uint32_t check_timeout;
	spinlock_t lcd_state_lock;
	bool is_timer_add;
	bool lcd_state_chang;
	int  lcd_backligt_level;
} lcd_on_off_check_timer;

static lcd_on_off_check_timer lcd_softwdt;

static atomic_t lcd_on_off_check_enable = ATOMIC_INIT(0);

void lcd_on_off_state_set(int level)
{
	unsigned long flags;

	if (0 == atomic_read(&lcd_on_off_check_enable)) {
		return;
	}
	spin_lock_irqsave(&(lcd_softwdt.lcd_state_lock), flags);
	lcd_softwdt.lcd_backligt_level = level;
	if (level != 0) {
		lcd_softwdt.lcd_state_chang = true;
	}
	spin_unlock_irqrestore(&(lcd_softwdt.lcd_state_lock), flags);
}

static void lcd_on_off_check(unsigned long data)
{
	del_timer(&lcd_softwdt.lcd_timer);
	lcd_softwdt.is_timer_add = false;
	if (!lcd_softwdt.lcd_state_chang) {
		show_state_filter(TASK_UNINTERRUPTIBLE);
		show_mem(0);
		rdr_syserr_process_for_ap(MODID_AP_S_RESUME_SLOWY, 0, 0);
	}
}

/*===========================================================================
** Function : lcd_on_off_check_timer_start
* @brief
* wheher screen waked up in a specific time when power key being pressed.
** ==========================================================================*/
void lcd_on_off_check_timer_start(void)
{
	unsigned long flags;

	if (0 == atomic_read(&lcd_on_off_check_enable)) {
		return;
	}
	spin_lock_irqsave(&(lcd_softwdt.lcd_state_lock), flags);
	if (0 != lcd_softwdt.lcd_backligt_level) {
		spin_unlock_irqrestore(&(lcd_softwdt.lcd_state_lock), flags);
		return;
	}
	if (!lcd_softwdt.is_timer_add) {
		lcd_softwdt.lcd_state_chang = false;
		spin_unlock_irqrestore(&(lcd_softwdt.lcd_state_lock), flags);
		lcd_softwdt.is_timer_add = true;
		lcd_softwdt.lcd_timer.expires = jiffies +
				msecs_to_jiffies(lcd_softwdt.check_timeout);
		lcd_softwdt.lcd_timer.function = lcd_on_off_check;
		lcd_softwdt.lcd_timer.data = 0;
		add_timer(&lcd_softwdt.lcd_timer);
		printk(KERN_INFO "lcd_on_off_check_timer_start work end\n");
		return;
	}
	spin_unlock_irqrestore(&(lcd_softwdt.lcd_state_lock), flags);
	return;

}


/*===========================================================================
** Function : lcd_on_off_check_powerkey_init
* @brief
* get lcd on/off check timeout.
** ==========================================================================*/
void lcd_on_off_check_init(void)
{
	int ret = 0;
	struct device_node *np;

	np = of_find_compatible_node(NULL, NULL, "hisilicon,hisi-powerkey");
	if (IS_ERR(np)) {
		printk(KERN_ERR "lcd_on_off_check_init Can not find hisilicon,hisi-powerkey node\n");
	} else {
		ret = of_property_read_u32(np, "lcd_on_off_timeout",
						&lcd_softwdt.check_timeout);
		if (ret) {
			printk(KERN_ERR "lcd_on_off_check_init get check_timeout failed!\n");
		}
		if (0 != lcd_softwdt.check_timeout) {
			lcd_softwdt.is_timer_add = false;
			lcd_softwdt.lcd_backligt_level = 1;
			spin_lock_init(&(lcd_softwdt.lcd_state_lock));
			init_timer(&lcd_softwdt.lcd_timer);
			atomic_set(&lcd_on_off_check_enable, 1);
		}
		printk(KERN_INFO "lcd_on_off_check_init get check_timeout is %d!\n", lcd_softwdt.check_timeout);
	}
}

