#ifndef __BSP_PARTITION_H__
#define __BSP_PARTITION_H__

#define PART_NAMELEN                   (16)
#define MAX_PART_NUM                   (131)
#define BLOCK_SIZE_BYTE                (512)

struct partition {
	char name[PART_NAMELEN];
	unsigned int start;
	unsigned int length;
	unsigned int flags;
};

enum {
	USER_PART = 0x0,
	BOOT_PART = 0x1,
};

int partition_init(void);
struct partition* find_partition(const char *name);

#endif
