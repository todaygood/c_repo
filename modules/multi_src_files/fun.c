


#include <linux/init.h>
#include <linux/module.h>

void print_error(char * str)
{
	printk(KERN_ERR"%s\n",str);
	return;

}


