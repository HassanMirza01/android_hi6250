#ifndef __LINUX_USB31_TCA_H__
#define __LINUX_USB31_TCA_H__

typedef enum {
	TCPC_NO_CONNECTION = 0,
	TCPC_USB31_CONNECTED = 1,
	TCPC_DP_4LINE = 2,
	TCPC_USB31_AND_DP_2LINE = 3,
	TCPC_MUX_MODE_MAX
}TCPC_MUX_CTRL_TYPE;


extern void tca_mode_switch(TCPC_MUX_CTRL_TYPE mode_type);

#endif 
