#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/types.h>
#include <linux/timer.h>
#include <linux/miscdevice.h>
#include <linux/watchdog.h>
#include <linux/fs.h>
#include <linux/notifier.h>
#include <linux/reboot.h>
#include <linux/init.h>
#include <linux/jiffies.h>
#include <linux/uaccess.h>
#include <linux/kernel_stat.h>
#include <linux/interrupt.h>
#include <linux/init.h>
#include <linux/mm.h>
#include <linux/notifier.h>
#include <linux/percpu.h>
#include <linux/cpu.h>
#include <linux/freezer.h>
#include <linux/kthread.h>
#include <linux/rcupdate.h>
#include <linux/smp.h>
#include <linux/tick.h>
#include <trace/irq.h>


static int cpu_num = 0;

module_param(cpu_num, int, 0);

static void watchdog_fire(unsigned long);



static void watchdog_fire(unsigned long data)
{
  // printk(KERN_CRIT "not scheduling cause panic.\n");
   panic("begin scheduling panic\n");
}


  	


static int ksoftirqd(void * __bind_cpu)
{
       struct timer_list watchdog_ticktock =
		TIMER_INITIALIZER(watchdog_fire, 0, 0);
	
       while(1){
		set_current_state(TASK_UNINTERRUPTIBLE);
//                printk("cpu%d run1 for a loop\n",__bind_cpu);
//		  if (signal_pending(current))
  //                {
//		     set_current_state(TASK_RUNNING);
  //                   return -EINTR;
  //		  }

		mod_timer(&watchdog_ticktock, jiffies+(30*HZ));
		schedule_timeout(10*HZ);
 		printk("cpu%d run for a loop\n",__bind_cpu);
//                if (signal_pending(current))
//                return -EINTR;
//                while(1);

	}
       
}

static int __init watchdog_init(void)
{
	
   struct task_struct *p;
   int i, num = cpu_num;
   for(i=0;i<num;i++) {
	p = kthread_create(ksoftirqd, i, "kschedwatch/%d", i);
	if (IS_ERR(p)) {
		printk("ksoftirqd for  cpu%d failed\n", i);
		return NOTIFY_BAD;
	}
	kthread_bind(p, i);
  	wake_up_process(p);
   }
   printk("dog-fire load successfully\n");
   return 0;
}	

static void __exit watchdog_exit(void)
{
	printk("bye bye for schedule-dog \n");
}

module_init(watchdog_init);
module_exit(watchdog_exit);
