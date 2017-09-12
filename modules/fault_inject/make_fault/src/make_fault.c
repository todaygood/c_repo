#include <linux/kernel.h>
#include <linux/spinlock.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/types.h>
#include <linux/timer.h>
#include <linux/miscdevice.h> 
#include <linux/fs.h>
#include <linux/notifier.h>
#include <linux/init.h>
#include <asm/uaccess.h>
#include <linux/kthread.h>
#include <linux/delay.h>

#include "mf_pub.h"

MODULE_LICENSE("GPL");


spinlock_t  slock;

#ifdef  MOD_PARAM 
static int MODPARM_copy_skb = 1;
module_param_named(copy_skb, MODPARM_copy_skb, bool, 0);
MODULE_PARM_DESC(copy_skb, "Copy data received from netfront without netloop");

static int MODPARM_permute_returns = 0;
module_param_named(permute_returns, MODPARM_permute_returns, bool, S_IRUSR|S_IWUSR);


static bool use_kthreads = true;
module_param_named(tasklets, use_kthreads, invbool, 0);
MODULE_PARM_DESC(tasklets, "Use tasklets instead of kernel threads");
#endif

struct task_struct * kthread_null_pointer;
int g_kthread_null_var =0; 

void make_null_pointer(void)
{
	int *p = NULL;

	*p =6;

	return ;

}

/*
kernel stack overflow
*/
void make_kernel_stack_over(void)
{
	int a[8192];

	
	memset(a,0,8192);
	
	

	return ;	
}




long mf_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	switch (cmd) 
	{
	
		case MF_IOC_NULL_POINTER:
			make_null_pointer();
			break;
		case MF_IOC_PANIC:
			panic("this is a test called panic\n");

			break;

			
		case MF_IOC_SPINLOCK_HANG:
			spin_lock_init(&slock);
			spin_lock(&slock);
			spin_lock(&slock);
			break;
			
		case MF_IOC_LOOP:
			while(1);
			break;

		case MF_IOC_KERN_STK_OVER:
		
			printk("kernel stack size:%lu\n",THREAD_SIZE);
			make_kernel_stack_over();
			break;

		case MF_KTHREAD_NULL_POINTER:
			{
				printk("kernel thread null pointer happening...\n");
				g_kthread_null_var =1;
				wake_up_process(kthread_null_pointer);
			}
			break;

		case MF_IOC_GENERAL_PROTECTION:
	        {
				void (*func)(); //declare a function pointer;
				int instr=0x12345678;
				func=&instr;
				printk("panic general protection happening...\n");
				func(); 
			} 
			break;

		default:
			printk(KERN_INFO"unknown command\n");
			break;
	}

	return 0;

}





static const struct file_operations mf_chrdev_ops = {
	.owner		= THIS_MODULE,
	.unlocked_ioctl  = mf_ioctl,
	
};

static struct miscdevice mf_miscdev = {
	.minor		= MF_MISCDEV_MINOR,
	.name		= FAULT_DEV_NAME,
	.nodename	= FAULT_DEV_NAME,
	.fops		= &mf_chrdev_ops,
};



int kthread_null_pointer_handler(void *data)
{
//	while (!kthread_should_stop())
	printk("null_pointer kthread begin...\n");
	printk("g_kthread_null_var=%d\n",g_kthread_null_var);
	while (1)
	{
		if (g_kthread_null_var ==1)
		{
			char *p =NULL;
			*p = 5;	
		}
	//	schedule();
		mdelay(10);
	}
	printk("null_pointer kthread end...\n");
	return 0;
}




int make_fault_init(void)
{
	int err = 0;
	
	err = misc_register(&mf_miscdev);
	if (err)
	{
		printk(KERN_ERR"register fault-making char device failed\n");
		return err;
	}

#ifdef  MOD_PARAM 
	printk(KERN_INFO"MODPARM_copy_skb=%d\n",MODPARM_copy_skb);
	printk(KERN_INFO"MODPARM_permute_returns=%d\n",MODPARM_permute_returns);
	printk(KERN_INFO"use_kthreads=%d\n",use_kthreads);
	
#endif

	
    kthread_null_pointer= kthread_run(&kthread_null_pointer_handler, NULL, "mf_kthread_null_pointer");
    if (IS_ERR(kthread_null_pointer)){
        printk(KERN_WARNING "kthread_null_pointer failed to spawn, error = %ld\n", PTR_ERR(kthread_null_pointer));
        return -1;
    }
	return 0;
}



void make_fault_exit(void)
{

	misc_deregister(&mf_miscdev);
	
	
}


module_init(make_fault_init);
module_exit(make_fault_exit);
