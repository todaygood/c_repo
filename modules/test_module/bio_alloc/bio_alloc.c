/*                                                     
 * $Id: hello.c,v 1.5 2004/10/26 03:32:21 corbet Exp $ 
 */                                                    
#include <linux/init.h>
#include <linux/module.h>
#include <linux/mm.h>
#include <linux/swap.h>
#include <linux/bio.h>
#include <linux/blkdev.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/mempool.h>
#include <linux/workqueue.h>
#include <linux/gfp.h>

MODULE_LICENSE("Dual BSD/GPL");

struct bio *b =0;

static int hello_init(void)
{
	b=bio_alloc(GFP_KERNEL,5);
	//printk(KERN_WARNING "Hello3,world\n");
	return 0;
}

static void hello_exit(void)
{
		
}

module_init(hello_init);
module_exit(hello_exit);
