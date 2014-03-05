/*
 * Copyright (C) 2013-2014 Bing Sun <b.y.sun.cn@gmail.com>
 *
 * Released under the terms of the GNU GPL v2.0.
 */


/* param of reserved memory at boot*/
MODULE_PARM(iet_mem_start, "i");
MODULE_PARM(iet_mem_size, "i");

static int iet_mem_start = 910, iet_mem_size = 80;


extern int iet_page_num;



struct iet_cache_page{
	struct page *page;
	dev_t bdev;
	sector_t		sector;
	struct list_head lru_list;
	
};

static struct kmem_cache *iet_page_cache;

struct iet_device{
	struct address_space mapping;
	struct list_head list;
	dev_t bdev;
};

struct list_head iet_devices;
