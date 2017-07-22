#ifndef _INTERNAL_HISI_BLK_MQ_H_
#define _INTERNAL_HISI_BLK_MQ_H_

#include <linux/blkdev.h>
#include <linux/hisi-blk-mq.h>

#ifdef CONFIG_HISI_BLK_MQ

#define MQ_MERGE_MAX_SIZE 0x40000

static inline void blk_request_queue_disk_register(struct gendisk *disk,struct request_queue *q)
{
	q->request_queue_disk = disk;
}

extern int blkdev_issue_flush(struct block_device *bdev, gfp_t gfp_mask, sector_t *error_sector);

static void blk_mq_flush_work_fn(struct work_struct* work)
{
	int ret;
	struct request_queue *q = container_of(work, struct request_queue, flush_work.work);/*lint !e826*/
	struct block_device *bdev = bdget_disk(q->request_queue_disk, 0);
	if(bdev == NULL)
		return;
	if((atomic_read(&q->do_delay_flush) == 0) || (atomic_read(&q->flush_work_trigger) == 0))
		return;
	atomic_set(&q->flush_work_trigger, 0);
	ret = blkdev_get(bdev, FMODE_WRITE, NULL);
	if(ret){
		printk(KERN_EMERG "<%s> blkdev_get fail! \r\n", __func__);
		return;
	}
	atomic_set(&q->flush_work_execute, 1);
	ret = blkdev_issue_flush(bdev, GFP_KERNEL, NULL);
	if(ret)
		printk(KERN_EMERG "<%s> blkdev_issue_flush fail! \r\n", __func__);
	atomic_set(&q->do_delay_flush, 0);
	atomic_set(&q->flush_work_execute, 0);
	blkdev_put(bdev, FMODE_WRITE);
}

static inline bool flush_reducing(struct request_queue *q, struct request *rq)
{
	if (!hisi_blk_mq_test_queue_quirk(q, HISI_MQ_FLUSH_REDUCING)){
		if((rq->cmd_flags & REQ_FLUSH) && (rq->__data_len == 0) &&(atomic_read(&q->wio_after_flush_fua) == 0))
			goto flush_bypass;
		else
			goto flush_dispatch;
	}
	if (rq->cmd_flags & REQ_FLUSH && (rq->__data_len == 0)) {
		if(atomic_read(&q->wio_after_flush_fua) == 0)
			goto flush_bypass;
		if(atomic_read(&q->flush_work_execute) == 1)
			goto flush_dispatch;
		if(atomic_read(&q->flush_work_trigger) == 1)
			kblockd_schedule_delayed_work_cancel(&q->flush_work);
		if(atomic_read(&q->do_delay_flush) == 0)
			atomic_set(&q->do_delay_flush, 1);
		goto flush_bypass;
	}
flush_dispatch:
	atomic_set(&q->wio_after_flush_fua, rq->__data_len ? 1 : 0);
	return false;
flush_bypass:
	return true;
}

static inline void flush_work_trigger(struct request_queue *q)
{
	if (!hisi_blk_mq_test_queue_quirk(q, HISI_MQ_FLUSH_REDUCING))
		return;
	if(atomic_read(&q->do_delay_flush) == 0)
		return;
	if(atomic_read(&q->flush_work_execute) == 0)
		kblockd_schedule_delayed_work_cancel(&q->flush_work);
	else
		return;
	if(atomic_read(&q->do_delay_flush) == 0)
		return;
	kblockd_schedule_delayed_work(&q->flush_work,msecs_to_jiffies(10));
	atomic_set(&q->flush_work_trigger, 1);
}

static inline void flush_reducing_stats_update(struct request_queue *q,
		struct request *rq, struct request *processing_rq)
{
	if (processing_rq->cmd_flags & REQ_FLUSH) {
		atomic_set(&q->wio_after_flush_fua, rq->__data_len ? 1 : 0);
	} else if ((processing_rq->cmd_type == REQ_TYPE_FS)
			   && (processing_rq->cmd_flags & REQ_WRITE)
			   && (atomic_read(&q->wio_after_flush_fua) == 0)) {
		atomic_set(&q->wio_after_flush_fua, 1);
	}
}

static inline void hisi_blk_mq_init(struct request_queue *q)
{
	INIT_DELAYED_WORK(&q->flush_work, blk_mq_flush_work_fn);
	atomic_set(&q->do_delay_flush, 0);
	atomic_set(&q->flush_work_execute, 0);
	atomic_set(&q->flush_work_trigger, 0);
	atomic_set(&q->flush_from_flush_work, 0);
	atomic_set(&q->wio_after_flush_fua,0);
}

#else /* CONFIG_HISI_BLK_MQ */

static inline void blk_request_queue_disk_register(struct gendisk *disk,struct request_queue *q){}

static inline void hisi_blk_mq_init(struct request_queue *q){}

static inline bool flush_reducing(struct request_queue *q, struct request *rq)
{
	return false;
}

static inline void flush_work_trigger(struct request_queue *q){}

static inline void flush_reducing_stats_update(struct request_queue *q,
		struct request *rq, struct request *processing_rq) {}

#endif /* CONFIG_HISI_BLK_MQ */

#endif /* _INTERNAL_HISI_BLK_MQ_H_ */
