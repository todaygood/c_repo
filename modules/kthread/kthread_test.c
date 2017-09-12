#include <linux/module.h>
#include <linux/init.h>
#include <linux/kmod.h>
#include <linux/slab.h>
#include <linux/timer.h>
#include <linux/jiffies.h>
#include <linux/string.h>
#include <linux/kernel_stat.h>
#include <linux/param.h>





struct timer_list mytimer;
static void myfunc(unsigned long data)
{
        printk("%s/n", (char *)data);
        dequeue();
        mod_timer(&mytimer, jiffies + 2*HZ);
}
static int __init mytimer_init(void)
{
        setup_timer(&mytimer, myfunc, (unsigned long)"Hello, world!");
        mytimer.expires = jiffies + HZ;
        add_timer(&mytimer);
        return 0;
}
static void __exit mytimer_exit(void)
{
        del_timer(&mytimer);
}




static struct task_struct *_task;
int thread_func(void *argm)
{
        printk("thread_func\n");
        mytimer_init();
        //     // wait to exit
        while(!kthread_should_stop())
        {
        //        printk("wait()\n");
             mdelay(1000);
        }
        return 0;
}
void exit_code(void)
{
        kthread_stop(_task);   //发信号给task，通知其可以退出了
}



static int __init this_init(void)
{
       _task = kthread_run(thread_func, NULL, "thread_func2");
        if (!IS_ERR(_task))
        {
                printk("kthread_create done\n");
        }
        else
        {
                printk("kthread_create error\n");
        }
 
        return ret;
 
}
