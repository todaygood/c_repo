/*                                                     
 * $Id: hello.c,v 1.5 2004/10/26 03:32:21 corbet Exp $ 
 */                                                    
#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("Dual BSD/GPL");

extern void print_error(char * str);


static int hello_init(void)
{
	int *p =0;
	

	//printk(KERN_ALERT "Hello1, world\n");
	printk(KERN_INFO "Hello2, world\n");
    print_err("this is an error message\n");

	*p=5;

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "Goodbye2, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);
