
#include <linux/init.h>
#include <linux/module.h>
#include "./lib/myalib.h" 
MODULE_LICENSE("Dual BSD/GPL");




int init_module(void)
{
	int sum=0;
	printk("into init_module.\n");	
	test();	
	sum= add(1,2);
	printk("sum=%d\n",sum);

	return 0;
}

void cleanup_module(void)
{
	printk("into cleanup_module.\n");
	test();
}


