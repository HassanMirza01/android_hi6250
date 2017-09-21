/*
 * drivers/power/charging_core.h
 *
 * advanced charge control
 *
 * Author: cyclon1978
 *
 * This package is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/
#ifndef _ADVANCED_CHARGE_CONTROL
#define _ADVANCED_CHARGE_CONTROL

#define USB_FASTCHARGE_CURRENT_LIMIT   900
#define USB_FASTCHARGE_CHARGE_LIMIT    686

#define USB_NORMALCHARGE_CURRENT_LIMIT 500
#define USB_NORMALCHARGE_CHARGE_LIMIT  500

void setFastcharge(bool active);

#endif
