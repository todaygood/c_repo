#include <linux/kernel.h>
#include <linux/spinlock.h>
#include <linux/smp_lock.h>

int dead_lock_init()
{
	printk(KERN_ALERT"begin to lock_kernel....\n");
	lock_kernel();
	return 0;
}



void dead_lock_exit()
{


	printk(KERN_ALERT"end lock_kernel....\n");

}


module_init(dead_lock_init);
module_exit(dead_lock_exit);
