#include <linux/kernel.h>
#include <linux/spinlock.h>
#include <linux/smp_lock.h>
#include <linux/mutex.h>

int dead_lock_init()
{
	struct mutex  lock;
   
	mutex_init(&lock);

        printk("lock=%p\n",&lock);
        mutex_lock(&lock);
        mutex_lock(&lock);

	return 0;
}



void dead_lock_exit()
{


	//printk(KERN_ALERT"end lock_kernel....\n");

}


module_init(dead_lock_init);
module_exit(dead_lock_exit);
