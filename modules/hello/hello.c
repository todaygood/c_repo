/*                                                     
 * $Id: hello.c,v 1.5 2004/10/26 03:32:21 corbet Exp $ 
 */                                                    
#include <linux/init.h>
#include <linux/module.h>
#include <linux/gfp.h>

MODULE_LICENSE("Dual BSD/GPL");

static int hello_init(void)
{
	printk(KERN_ALERT "GFP_KERNEL=0x%u\n",GFP_KERNEL);
	printk(KERN_INFO "Hello2, world\n");
	//printk(KERN_WARNING "Hello3,world\n");
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "Goodbye2, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);
