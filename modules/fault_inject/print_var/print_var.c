#include <linux/kernel.h>
#include <linux/spinlock.h>
#include <linux/smp_lock.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/types.h>
#include <linux/timer.h>
#include <linux/miscdevice.h> 
#include <linux/fs.h>
#include <linux/notifier.h>
#include <linux/init.h>
#include <asm/uaccess.h>
#include <linux/mm.h>



MODULE_LICENSE("GPL");



int print_var_init(void)
{
	unsigned long start_pfn, end_pfn, memmapsize, limit;
	unsigned long pfn = 0;
	struct page *page = NULL;
	int nodeid=0;
	
#if 0
	page = alloc_page(GFP_KERNEL);
	if (!page)
	{
		printk(KERN_INFO"alloc page failed\n");
		return -1;
	}
	
    printk(KERN_INFO"page=0x%llx\n",page);
#endif
    page = ((struct page *)0xffff810420b33848LLU);

 
	printk(KERN_INFO"PAGE_SIZE=0x%llx\n",PAGE_SIZE);	
	printk(KERN_INFO"ZONETABLE_PGSHIFT=0x%lx\n",ZONETABLE_PGSHIFT);
	printk(KERN_INFO"ZONETABLE_MASK=0x%lx\n", ZONETABLE_MASK);
	printk(KERN_INFO"ZONES_MASK=0x%lx\n",ZONES_MASK);
	printk(KERN_INFO"ZONES_PGSHIFT=0x%lx\n",ZONES_PGSHIFT);
	printk(KERN_INFO"NODES_MASK=0x%lx\n",NODES_MASK);
	printk(KERN_INFO"NODES_PGSHIFT=0x%lx\n",NODES_PGSHIFT);
	printk(KERN_INFO"SECTIONS_MASK=0x%lx\n",SECTIONS_MASK);
	printk(KERN_INFO"SECTIONS_PGSHIFT=0x%lx\n",SECTIONS_PGSHIFT);
	
	//pfn = page_to_pfn(page);
	printk(KERN_INFO"pfn=0x%llx\n",pfn);
	
	
	return 0;
}



void print_var_exit(void)
{

	
	
	
}


module_init(print_var_init);
module_exit(print_var_exit);
