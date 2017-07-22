
#include <linux/module.h>
#include <linux/init.h>
#include <linux/types.h>
#include <linux/string.h>
#include <linux/uaccess.h>
#include <linux/netdevice.h>
#include <linux/netfilter_ipv4.h>
#include <linux/ip.h>
#include <linux/tcp.h>
#include <linux/time.h>
#include <linux/kernel.h>/* add for log */
#include <linux/ctype.h>/* add for tolower */
#include <linux/spinlock.h>/* add for spinlock */
#include <linux/netlink.h>/* add for thread */
#include <uapi/linux/netlink.h>/* add for netlink */
#include <linux/kthread.h>/* add for thread */
#include <linux/jiffies.h>/* add for jiffies */
#include <linux/errno.h>
#include <linux/mutex.h>
#include <linux/semaphore.h>
#include <net/sock.h>
#include <linux/skbuff.h>
#include <huawei_platform/log/hw_log.h>

#include "wbc_hw_hook.h"
#include "chr_netlink.h"

/*This is to record the local in page information*/
static struct http_stream http_para_in;
/*This is to record the local out page information*/
static struct http_stream http_para_out;
/*The structure in order to record a different page stream with a hash index*/
static struct http_stream *stream_list;
/*This structure stores the statistics of web pages*/
static struct http_return rtn_stat;
/*Return the abnomal infomation*/
static struct http_return rtn_abn;
static struct rtt_from_stack stack_rtt;
static unsigned int sleep_flag;

/*The HTTP keyword is used to filter tcp packets*/
static char g_get_str[] = {'G', 'E', 'T', 0, 0};
static char g_http_str[] = {'H', 'T', 'T', 'P', 0};
static char g_post_str[] = {'P', 'O', 'S', 'T', 0};

/*These parameters are used to store the forbid time*/
static unsigned long rpt_stamp;
static unsigned long abn_stamp_no_ack;
static unsigned long abn_stamp_rtt_large;
static unsigned long abn_stamp_web_fail;
static unsigned long abn_stamp_web_delay;

/*tcp protocol use this semaphone to inform chr netlink thread*/
static struct semaphore g_web_stat_sync_sema;
static struct timer_list g_web_stat_timer;
static struct task_struct *g_web_stat_task;

/*This parameters lock are used to lock the common parameters*/
static spinlock_t g_web_stat_lock;
static spinlock_t g_web_para_in_lock;
static spinlock_t g_web_para_out_lock;



/*us convert to ms*/
u32 us_cvt_to_ms(u32 seq_rtt_us)
{
	return seq_rtt_us/1000;
}

/*To notify thread to update rtt*/
void notify_chr_thread_to_update_rtt(u32 seq_rtt_us)
{
	if (!spin_trylock_bh(&g_web_stat_lock)) {

		return;
	}

	if (seq_rtt_us < MAX_RTT) {

		stack_rtt.tcp_rtt = us_cvt_to_ms(seq_rtt_us);
		stack_rtt.is_valid = IS_USE;

	}

	spin_unlock_bh(&g_web_stat_lock);
	up(&g_web_stat_sync_sema);

}

/*timer's expired process function.
* In this function, the time-out data stream is discarded
* and the statistics are reported periodically.*/
static void web_stat_timer(unsigned long data)
{
	u32 hashcnt;
	int hashNum = 0;

	spin_lock_bh(&g_web_stat_lock);

	for (hashcnt = 0; hashcnt < HASH_MAX; hashcnt++) {

		if (IS_USE == stream_list[hashcnt].is_valid) {

			if (HTTP_GET == stream_list[hashcnt].type &&
			time_after(jiffies,
			stream_list[hashcnt].get_time_stamp + EXPIRE_TIME)) {

				rtn_stat.total_num++;
				rtn_stat.no_ack_num++;
				stream_list[hashcnt].is_valid = IS_UNUSE;

				if (time_after(jiffies, abn_stamp_no_ack)) {

					rtn_abn.report_type = WEB_NO_ACK;
					spin_unlock_bh(&g_web_stat_lock);
					chr_notify_event(CHR_WEB_STAT_EVENT,
						g_user_space_pid, 0, &rtn_abn);
					spin_lock_bh(&g_web_stat_lock);

					abn_stamp_no_ack =
						jiffies + FORBID_TIME;

				}
			}

			if (HTTP_SYN == stream_list[hashcnt].type &&
			time_after(jiffies,
			stream_list[hashcnt].time_stamp + DELETE_TIME)) {

				stream_list[hashcnt].is_valid = IS_UNUSE;

			}

			hashNum++;
		}
	}

	if (time_after(jiffies, rpt_stamp + REPORT_TIME)) {

		rpt_stamp = jiffies + REPORT_TIME;
		rtn_stat.report_type = WEB_STAT;
		spin_unlock_bh(&g_web_stat_lock);
		chr_notify_event(CHR_WEB_STAT_EVENT,
			g_user_space_pid, 0, &rtn_stat);
		spin_lock_bh(&g_web_stat_lock);
		memset(&rtn_stat, 0, sizeof(rtn_stat));
	}

	/*Check if there are timeout entries and remove them*/
	if (hashNum > 0) {
		sleep_flag = false;
		g_web_stat_timer.expires = jiffies + CHECK_TIME;
		spin_unlock_bh(&g_web_stat_lock);
		add_timer(&g_web_stat_timer);
		return;
	}
	sleep_flag = true;

	spin_unlock_bh(&g_web_stat_lock);
}

/*Computes the hash value of the network tcp stream*/
u8 hash3(u32 dst, u32 src, u32 port)
{
	u32 hash;

	hash = dst + src + port;
	hash = hash + hash/256 + hash/65536 + hash/16777216;
	hash = hash%HASH_MAX;
	return (u8)hash;
}

/*Local_out packet processing*/
void out_proc(void)
{
	u8 hash_cnt;

	spin_lock_bh(&g_web_para_out_lock);

	if (IS_USE == http_para_out.is_valid) {

		hash_cnt = hash3(http_para_out.dst_addr,
			http_para_out.src_addr, http_para_out.tcp_port);

		if (IS_UNUSE == stream_list[hash_cnt].is_valid) {

			if (HTTP_SYN == http_para_out.type) {

				memcpy(&stream_list[hash_cnt],
					&http_para_out, sizeof(http_para_out));

			}

		} else if (HTTP_SYN == stream_list[hash_cnt].type &&
			HTTP_GET == http_para_out.type) {

			if (stream_list[hash_cnt].src_addr ==
				http_para_out.src_addr &&
			stream_list[hash_cnt].dst_addr ==
				http_para_out.dst_addr &&
			stream_list[hash_cnt].tcp_port ==
				http_para_out.tcp_port) {

				stream_list[hash_cnt].get_time_stamp =
					http_para_out.time_stamp;
				stream_list[hash_cnt].type = HTTP_GET;

			}
		}

		http_para_out.is_valid = IS_UNUSE;

		if (sleep_flag) {
			sleep_flag = false;
			g_web_stat_timer.expires = jiffies + CHECK_TIME;
			spin_unlock_bh(&g_web_para_out_lock);
			add_timer(&g_web_stat_timer);
			return;
		}
	}

	spin_unlock_bh(&g_web_para_out_lock);
}

/*Local_in packet processing*/
void in_proc(void)
{
	u8 hash_cnt;
	u32 web_delay;
	unsigned long jiffies_tmp;

	jiffies_tmp = jiffies;

	spin_lock_bh(&g_web_para_in_lock);
	if (IS_UNUSE == http_para_in.is_valid) {
		spin_unlock_bh(&g_web_para_in_lock);
		return;
	}

	hash_cnt = hash3(http_para_in.dst_addr,
		http_para_in.src_addr, http_para_in.tcp_port);
	if (IS_UNUSE == stream_list[hash_cnt].is_valid ||
			HTTP_GET != stream_list[hash_cnt].type) {

		http_para_in.is_valid = IS_UNUSE;
		spin_unlock_bh(&g_web_para_in_lock);
		return;

	}

	/*In all three cases, the tcp stream is removed from the table.
	Http get to http response time is too long,
	that is, no response to the page.
	Visit the web page successfully. Failed to access webpage*/
	if (stream_list[hash_cnt].src_addr == http_para_in.src_addr &&
	stream_list[hash_cnt].dst_addr == http_para_in.dst_addr &&
	stream_list[hash_cnt].tcp_port == http_para_in.tcp_port) {

		switch (http_para_in.type) {
		case WEB_SUCC:
			rtn_stat.total_num++;
			rtn_stat.succ_num++;

			web_delay = (http_para_in.time_stamp -
				stream_list[hash_cnt].time_stamp) * MULTIPLE;
			rtn_stat.web_delay += web_delay;

			if (web_delay > DELAY_THRESHOLD_L1 &&
					web_delay <= DELAY_THRESHOLD_L2)
				rtn_stat.delay_num_L1++;

			else if (web_delay > DELAY_THRESHOLD_L2 &&
					web_delay <= DELAY_THRESHOLD_L3)
				rtn_stat.delay_num_L2++;

			else if (web_delay > DELAY_THRESHOLD_L3 &&
					web_delay <= DELAY_THRESHOLD_L4)
				rtn_stat.delay_num_L3++;

			else if (web_delay > DELAY_THRESHOLD_L4 &&
					web_delay <= DELAY_THRESHOLD_L5)
				rtn_stat.delay_num_L4++;

			else if (web_delay > DELAY_THRESHOLD_L5 &&
					web_delay <= DELAY_THRESHOLD_L6)
				rtn_stat.delay_num_L5++;

			else if (web_delay > DELAY_THRESHOLD_L6)
				rtn_stat.delay_num_L6++;

			if (time_after(jiffies_tmp, abn_stamp_web_delay) &&
					web_delay > WEB_DELAY_THRESHOLD) {

				rtn_abn.report_type = WEB_DELAY;
				rtn_abn.web_delay = web_delay;
				spin_unlock_bh(&g_web_para_in_lock);
				spin_unlock_bh(&g_web_stat_lock);
				chr_notify_event(CHR_WEB_STAT_EVENT,
					g_user_space_pid, 0, &rtn_abn);
				pr_info("chr: web delay report\n");
				spin_lock_bh(&g_web_stat_lock);
				spin_lock_bh(&g_web_para_in_lock);
				abn_stamp_web_delay = jiffies_tmp + FORBID_TIME;

			}
			break;

		case WEB_FAIL:
			rtn_stat.total_num++;
			rtn_stat.fail_num++;
			if (time_after(jiffies_tmp, abn_stamp_web_fail)) {
				rtn_abn.report_type = WEB_FAIL;
				spin_unlock_bh(&g_web_para_in_lock);
				spin_unlock_bh(&g_web_stat_lock);
				chr_notify_event(CHR_WEB_STAT_EVENT,
					g_user_space_pid, 0, &rtn_abn);
				pr_info("chr: web fail report\n");
				spin_lock_bh(&g_web_stat_lock);
				spin_lock_bh(&g_web_para_in_lock);
				abn_stamp_web_fail = jiffies_tmp + FORBID_TIME;

			}
			break;

		default:
			break;

		}
		stream_list[hash_cnt].is_valid = IS_UNUSE;

	} else if (HTTP_GET == stream_list[hash_cnt].type &&
		time_after(jiffies_tmp, stream_list[hash_cnt].get_time_stamp +
		EXPIRE_TIME)) {

		rtn_stat.total_num++;
		rtn_stat.no_ack_num++;

		if (time_after(jiffies_tmp, abn_stamp_no_ack)) {
			rtn_abn.report_type = WEB_NO_ACK;
			spin_unlock_bh(&g_web_para_in_lock);
			spin_unlock_bh(&g_web_stat_lock);
			chr_notify_event(CHR_WEB_STAT_EVENT,
				g_user_space_pid, 0, &rtn_abn);
			pr_info("chr: no ack report\n");
			spin_lock_bh(&g_web_stat_lock);
			spin_lock_bh(&g_web_para_in_lock);
			abn_stamp_no_ack = jiffies_tmp + FORBID_TIME;
		}

		stream_list[hash_cnt].is_valid = IS_UNUSE;
	}

	http_para_in.is_valid = IS_UNUSE;

	if (sleep_flag) {
		sleep_flag = false;
		g_web_stat_timer.expires = jiffies + CHECK_TIME;
		spin_unlock_bh(&g_web_para_in_lock);
		add_timer(&g_web_stat_timer);
		return;
	}

	spin_unlock_bh(&g_web_para_in_lock);
}

void rtt_proc(void)
{
	if (IS_USE == stack_rtt.is_valid) {

		rtn_stat.tcp_total_num++;
		rtn_stat.tcp_rtt += stack_rtt.tcp_rtt;

		if (stack_rtt.tcp_rtt > RTT_THRESHOLD_L1 &&
				stack_rtt.tcp_rtt <= RTT_THRESHOLD_L2)
			rtn_stat.rtt_num_L1++;

		else if (stack_rtt.tcp_rtt > RTT_THRESHOLD_L2 &&
				stack_rtt.tcp_rtt <= RTT_THRESHOLD_L3)
			rtn_stat.rtt_num_L2++;

		else if (stack_rtt.tcp_rtt > RTT_THRESHOLD_L3 &&
				stack_rtt.tcp_rtt <= RTT_THRESHOLD_L4)
			rtn_stat.rtt_num_L3++;

		else if (stack_rtt.tcp_rtt > RTT_THRESHOLD_L4 &&
				stack_rtt.tcp_rtt <= RTT_THRESHOLD_L5)
			rtn_stat.rtt_num_L4++;

		else if (stack_rtt.tcp_rtt > RTT_THRESHOLD_L5)
			rtn_stat.rtt_num_L5++;

		if (stack_rtt.tcp_rtt > RTT_THRESHOLD &&
			time_after(jiffies, abn_stamp_rtt_large)) {

			abn_stamp_rtt_large = jiffies + FORBID_TIME;
			rtn_abn.report_type = TCP_RTT_LARGE;
			rtn_abn.tcp_rtt = stack_rtt.tcp_rtt;
			spin_unlock_bh(&g_web_stat_lock);
			chr_notify_event(CHR_WEB_STAT_EVENT,
				g_user_space_pid, 0, &rtn_abn);
			pr_info("chr: rtt large report\n");
			spin_lock_bh(&g_web_stat_lock);

		}
		stack_rtt.is_valid = IS_UNUSE;

		if (sleep_flag) {
			sleep_flag = false;
			g_web_stat_timer.expires = jiffies + CHECK_TIME;
			spin_unlock_bh(&g_web_stat_lock);
			add_timer(&g_web_stat_timer);
			spin_lock_bh(&g_web_stat_lock);
		}
	}
}

/*This is the main thread of web statistics*/
static int chr_web_thread(void *data)
{
	while (1) {
		if (kthread_should_stop())
			break;

		down(&g_web_stat_sync_sema);
		spin_lock_bh(&g_web_stat_lock);
		in_proc();
		out_proc();
		rtt_proc();
		spin_unlock_bh(&g_web_stat_lock);
	}
	return 0;
}

/*Calculates the return code for http*/
u8 http_response_type(char *pstr)
{
	u8 type;

	type = UN_KNOW;

	if (pstr[HTTP_ACK_FROM_START] == '2' ||
			pstr[HTTP_ACK_FROM_START] == '3') {
		type = WEB_SUCC;
	}

	if (pstr[HTTP_ACK_FROM_START] == '4' ||
			pstr[HTTP_ACK_FROM_START] == '5') {
		type = WEB_FAIL;
	}
	return type;
}

/*Local out hook function*/
static unsigned int hook_local_out(const struct nf_hook_ops *ops,
					struct sk_buff *skb,
					const struct nf_hook_state *state)
{
	struct iphdr *iph = NULL;
	struct tcphdr *tcph = NULL;
	struct tcp_sock *sock = NULL;
	char *pHttpStr = NULL;
	bool up_req = false;
	int dlen;

	if (NULL == skb)
		return NF_ACCEPT;

	iph = ip_hdr(skb);
	if (NULL == iph)
		return NF_ACCEPT;

	if (IPPROTO_TCP == iph->protocol) {

		tcph = tcp_hdr(skb);
		if (NULL == tcph || NULL == skb->data || 0 == tcph->doff)
			return NF_ACCEPT;

		pHttpStr = (char *)((u32 *)tcph + tcph->doff);
		dlen = skb->len - (pHttpStr - (char *)iph);
		if (dlen < 0) {
			return NF_ACCEPT;
		}

		if (NULL == skb->dev || NULL == skb->dev->name)
			return NF_ACCEPT;

		if (strncmp(skb->dev->name, DS_NET, DS_NET_LEN))
			return NF_ACCEPT;

		if (NULL == skb->sk)
			return NF_ACCEPT;

		if (skb->sk->sk_state == TCP_ESTABLISHED) {

			sock = tcp_sk(skb->sk);
			sock->data_net_flag = true;
		}

		if (HTTP_PORT != htons(tcph->dest))
			return NF_ACCEPT;

		/*When the lock is not locked, the lock is triggered*/
		if (!spin_trylock_bh(&g_web_para_out_lock)) {
			return NF_ACCEPT;
		}

		if (http_para_out.is_valid == IS_UNUSE) {

			/*This is an http ack syn packet processing*/
			if (tcph->syn == 1 && tcph->ack == 0) {

				http_para_out.tcp_port = tcph->source;
				http_para_out.src_addr = iph->saddr;
				http_para_out.dst_addr = iph->daddr;
				http_para_out.type = HTTP_SYN;
				http_para_out.time_stamp = jiffies;
				http_para_out.is_valid = IS_USE;
				up_req = true;

			} else if (dlen > 5 &&
			(strncmp(pHttpStr, g_get_str, STR_GET_LEN) ||
			strncmp(pHttpStr, g_post_str, STR_POST_LEN))) {

				http_para_out.tcp_port = tcph->source;
				http_para_out.src_addr = iph->saddr;
				http_para_out.dst_addr = iph->daddr;
				http_para_out.type = HTTP_GET;
				http_para_out.time_stamp = jiffies;
				http_para_out.is_valid = IS_USE;
				up_req = true;
			}
		}

		spin_unlock_bh(&g_web_para_out_lock);

		if (up_req)
			up(&g_web_stat_sync_sema);

	}

	return NF_ACCEPT;
}

/*Local in hook function*/
static unsigned int hook_local_in(const struct nf_hook_ops *ops,
					struct sk_buff *skb,
					const struct nf_hook_state *state)
{
	struct iphdr *iph = NULL;
	struct tcphdr *tcph = NULL;
	char *pHttpStr = NULL;
	bool up_req = false;
	u32 dlen;

	if (NULL == skb)
		return NF_ACCEPT;

	iph = ip_hdr(skb);
	if (NULL == iph)
		return NF_ACCEPT;

	if (IPPROTO_TCP == iph->protocol) {

		tcph = tcp_hdr(skb);
		if (NULL == tcph || NULL == skb->data || 0 == tcph->doff)
			return NF_ACCEPT;

		pHttpStr = (char *)((u32 *)tcph + tcph->doff);
		dlen = skb->len - (pHttpStr - (char *)iph);

		if (dlen < HTTP_RSP_LEN)
			return NF_ACCEPT;

		if (NULL == skb->dev || NULL == skb->dev->name)
			return NF_ACCEPT;

		if (strncmp(skb->dev->name, DS_NET, DS_NET_LEN))
			return NF_ACCEPT;

		if (HTTP_PORT != htons(tcph->source))
			return NF_ACCEPT;

		if (!spin_trylock_bh(&g_web_para_in_lock)) {
			return NF_ACCEPT;
		}

		/*Determine whether the received packet is an HTTP response*/
		if (strncmp(pHttpStr, g_http_str, STR_HTTP_LEN) == 0 &&
			http_response_type(pHttpStr) != UN_KNOW &&
			http_para_in.is_valid == IS_UNUSE) {

			http_para_in.tcp_port = tcph->dest;
			http_para_in.src_addr = iph->daddr;
			http_para_in.dst_addr = iph->saddr;
			http_para_in.time_stamp = jiffies;
			http_para_in.is_valid = IS_USE;
			http_para_in.type = http_response_type(pHttpStr);
			up_req = true;

		}

		spin_unlock_bh(&g_web_para_in_lock);

		if (up_req)
			up(&g_web_stat_sync_sema);

	}
	return NF_ACCEPT;
}

static struct nf_hook_ops net_hooks[] = {
	{
		.hook		= hook_local_in,
		.owner		= THIS_MODULE,
		.pf			= PF_INET,
		.hooknum	= NF_INET_LOCAL_IN,
		.priority	= NF_IP_PRI_FILTER - 1,
	},
	{
		.hook		= hook_local_out,
		.owner		= THIS_MODULE,
		.pf			= PF_INET,
		.hooknum	= NF_INET_POST_ROUTING,
		.priority	= NF_IP_PRI_FILTER - 1,
	}
};

/*CHR Initialization function*/
int web_chr_init(void)
{
	int ret = 0;

       /*Initializes the array*/
	stream_list = kmalloc(sizeof(struct http_stream)*HASH_MAX, GFP_KERNEL);
	if (NULL == stream_list)
		return -1;

	memset(stream_list, 0, sizeof(struct http_stream)*HASH_MAX);

	/*Variable initialization*/
	memset(&rtn_stat, 0, sizeof(rtn_stat));
	memset(&rtn_abn, 0, sizeof(rtn_abn));
	memset(&http_para_in, 0, sizeof(http_para_in));
	memset(&http_para_out, 0, sizeof(http_para_out));
	memset(&stack_rtt, 0, sizeof(stack_rtt));

	/*spin lock initialization*/
	spin_lock_init(&g_web_stat_lock);
	spin_lock_init(&g_web_para_in_lock);
	spin_lock_init(&g_web_para_out_lock);
	sema_init(&g_web_stat_sync_sema, 0);

	/*Timestamp initialization*/
	abn_stamp_no_ack = jiffies;
	abn_stamp_rtt_large = jiffies;
	abn_stamp_web_fail = jiffies;
	abn_stamp_web_delay = jiffies;
	rpt_stamp = jiffies;

	/*Create a thread*/
	g_web_stat_task = kthread_run(chr_web_thread, NULL, "chr_web_thread");

	/*Timer initialization*/
	init_timer(&g_web_stat_timer);
	g_web_stat_timer.data = 0;
	g_web_stat_timer.function = web_stat_timer;
	g_web_stat_timer.expires = jiffies + CHECK_TIME;
	add_timer(&g_web_stat_timer);
	sleep_flag = false;

       /*Registration hook function*/
	ret = nf_register_hooks(net_hooks, ARRAY_SIZE(net_hooks));
	if (ret) {
		pr_info("chr:nf_init_in ret=%d  ", ret);
		return -1;
	}
	pr_info("chr:web stat init success\n");

	return 0;
}

void web_chr_exit(void)
{
	nf_unregister_hooks(net_hooks, ARRAY_SIZE(net_hooks));
	kfree(stream_list);
	pr_info("chr:web stat exit success\n");
}


