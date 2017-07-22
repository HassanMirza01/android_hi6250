
#ifndef _WEB_HW_HOOK
#define _WEB_HW_HOOK

/*Zero*/
#define ZERO						0
/*initial reset*/
#define INIT_NUM				0
/*The length of the hash table*/
#define HASH_MAX				256
/*The length of the http header recoded*/
#define HTTP_ACK_HEAD_NUM		18
/*The starting point of the return code for http*/
#define HTTP_ACK_FROM_START	9
/*Timer length*/
#define CHECK_TIME				(15*HZ)
/*Determines how long the page has timed out*/
#define EXPIRE_TIME				(30*HZ)
/*Determines how long the page has timed out*/
#define DELETE_TIME				(30*HZ)
/*The period in which the page statistics are reported*/
#define REPORT_TIME			(15*60*HZ)
/*The period in which the page statistics are forbid*/
#define FORBID_TIME				(60*60*HZ)
/*http protocal default tcp port*/
#define HTTP_PORT				80
/*Web page statistics reporting chr events*/
#define CHR_WEB_STAT_EVENT	9
/*RTT threshold*/
#define RTT_THRESHOLD			(200)
/*RTT threshold for count*/
#define RTT_THRESHOLD_L1		(0)
#define RTT_THRESHOLD_L2		(50)
#define RTT_THRESHOLD_L3		(100)
#define RTT_THRESHOLD_L4		(150)
#define RTT_THRESHOLD_L5		(200)
/*Web delay threshold*/
#define WEB_DELAY_THRESHOLD	(2500)
/*Web delay threshold for count*/
#define DELAY_THRESHOLD_L1	(0)
#define DELAY_THRESHOLD_L2	(1000)
#define DELAY_THRESHOLD_L3	(1500)
#define DELAY_THRESHOLD_L4	(2000)
#define DELAY_THRESHOLD_L5	(2500)
#define DELAY_THRESHOLD_L6	(3000)
/*The largest RTT*/
#define MAX_RTT					(REPORT_TIME*2*HZ)
/*HTTP response string length*/
#define HTTP_RSP_LEN			(16)
/*HTTP str length for Comparison*/
#define STR_HTTP_LEN			(4)
#define STR_GET_LEN				(3)
#define STR_POST_LEN			(4)
/*cs conversion ratio*/
#define MULTIPLE				(1000/HZ)
/*data service string length*/
#define DS_NET					("rmnet")
#define DS_NET_LEN				(5)

/*response and report type*/
enum {
	WEB_STAT = 0,
	WEB_NO_ACK,
	WEB_FAIL,
	WEB_DELAY,
	TCP_RTT_LARGE,
	WEB_SUCC,
	AP_PS_SLOW,
	UN_KNOW,
};

/*TCP response type*/
enum {
	HTTP_GET = 0,
	HTTP_SYN,
	OTHER,
};

/*Whether the parameter is use*/
enum {
	IS_UNUSE = 0,
	IS_USE,
};

int web_chr_init(void);
void web_chr_exit(void);
void web_proc(void);
u32 http_timer(void);

/*Hook package for data storage structures*/
struct http_stream {
	u32 src_addr;
	u32 dst_addr;
	u16 tcp_port;
	u8 is_valid;
	u8 type;
	unsigned long time_stamp;
	unsigned long get_time_stamp;
};


/*Web page statistics structure*/
struct http_return {
	u32 tcp_rtt;
	u32 web_delay;
	u32 succ_num;
	u32 fail_num;
	u32 no_ack_num;
	u32 total_num;
	u32 report_type;
	u32 tcp_total_num;
	u32 delay_num_L1;
	u32 delay_num_L2;
	u32 delay_num_L3;
	u32 delay_num_L4;
	u32 delay_num_L5;
	u32 delay_num_L6;
	u32 rtt_num_L1;
	u32 rtt_num_L2;
	u32 rtt_num_L3;
	u32 rtt_num_L4;
	u32 rtt_num_L5;
};

/*this is temporarily stores the RTT*/
struct rtt_from_stack {
	u32 tcp_rtt;
	u32 is_valid;
};

#endif /*_WEB_HW_HOOK*/

