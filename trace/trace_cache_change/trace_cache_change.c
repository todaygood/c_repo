#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kprobes.h>
#include <linux/version.h>
#include <linux/mm.h>
#include <linux/swap.h>
#include <linux/mman.h>
#include <linux/pagemap.h>

static  int  remove_count=0;
static long j__remove_from_page_cache( struct page *page  )
{
  	remove_count++;
  	
  	if (remove_count %20 ==0 )
   {
			/*打印内核栈*/				
			dump_stack();
			printk("remove_count=%d\n",remove_count);
	}
	
	/* Always end with a call to jprobe_return(). */
	jprobe_return();
	return 0;
}

static  int  add_count=0;
static long jadd_to_page_cache_locked(struct page *page, struct address_space *mapping,
        pgoff_t offset, gfp_t gfp_mask)
{
  	add_count++;
  	
  	if (add_count %20 ==0 )
   {
			/*打印内核栈*/				
			dump_stack();
			printk("add_count=%d\n",add_count);
	}
	
	/* Always end with a call to jprobe_return(). */
	jprobe_return();
	return 0;
}


static struct jprobe my_jprobe[] = {
	{.entry			= j__remove_from_page_cache,},	
	{.entry			= jadd_to_page_cache_locked ,}
};

static int __init jprobe_init(void)
{
	int ret;
	int i ; 
	
	for (i=0 ; i< 2 ; i++)
	{
		ret = register_jprobe(my_jprobe+i);
		if (ret < 0) {
			printk(KERN_INFO "register_jprobe failed, returned %d\n", ret);
			return -1;
		}
	}	
	printk(KERN_INFO "Planted jprobe ok\n");
	return 0;
}

static void __exit jprobe_exit(void)
{
 	int i=0;
	for (i=1;i>=0; i--)
	{
		unregister_jprobe(my_jprobe+i);
	}
	 
}

module_init(jprobe_init)
module_exit(jprobe_exit)

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("trace reboot");
MODULE_AUTHOR("Jun Hu(jhu@novell.com)");
