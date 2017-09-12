#include <linux/module.h>
#include <linux/init.h>
#include <linux/kmod.h>
#include <linux/slab.h>
#include <linux/timer.h>
#include <linux/jiffies.h>
#include <linux/string.h>
#include <linux/kernel_stat.h>
#include <linux/param.h>
#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/file.h>
#include <linux/fs.h>
#include <linux/poll.h>
#include <linux/kprobes.h>

int delay = 10;  //s
module_param(delay,int,0644);


struct timer_list exp_timer;

int count=0;
//do_gettimeofday(struct timeval *tv)


struct tm_data
{
	struct timeval tmv;
	unsigned long irqc;
    unsigned long jiff;	

};

struct tm_data first; //static
struct tm_data second; //var
struct tm_data third ; //var


//kstat_irqs: ffffffff810a1100

//unsigned int(*my_kstat_irqs)(unsigned int )=0xffffffff810a1100;

int (*select_fn)(int n, fd_set __user *inp, fd_set __user *outp,
               fd_set __user *exp, s64 *timeout) =(void*)0xffffffff801909d5;


void j__pollwait(struct file *filp, wait_queue_head_t *wait_address,
                poll_table *p)
{

//	dump_stack();

	jprobe_return();

}

void get_tm_data(struct tm_data *td)
{
		do_gettimeofday(&(td->tmv));
        //td->irqc= my_kstat_irqs(0);
        //td->irqc= kstat_irqs_cpu(0,0);
        td->irqc= kstat_irqs(0);
		td->jiff= get_jiffies_64();
}



static void do_something(unsigned long data)
{
		unsigned long  irq_diff;
		unsigned long  total_irq_diff;
		unsigned long  jiff_diff;
		unsigned long  total_jiff_diff;
			
		count++;

		memcpy(&second,(struct tm_data*)data,sizeof(struct tm_data));

	    get_tm_data(&third);		

//		diff =       timeval_to_jiffies(&b)-timeval_to_jiffies(&c);
//		total_diff = timeval_to_jiffies(&b)-timeval_to_jiffies(&a);
		irq_diff = third.irqc- second.irqc;
		total_irq_diff = third.irqc-first.irqc;

	    jiff_diff= third.jiff - second.jiff;
		total_jiff_diff = third.jiff - first.jiff;
		

        printk(KERN_INFO "timer_test:%5d timer %ds expired,irq_diff %ld %ld real jiffies diff:%ld %ld\n",
			   count,delay,irq_diff, total_irq_diff,jiff_diff,total_jiff_diff 
			  );

        exp_timer.data = (unsigned long)&third;
		mod_timer(&exp_timer, jiffies + delay*HZ);
}

static DECLARE_WAIT_QUEUE_HEAD(select_wait); /* waiting for timeout finished */
struct task_struct *thread;

int work_fn(void*arg)
{

	int ret =0;	
	int stop =0;
	s64 timeout = -1;
	struct timeval rtv;
	timeout = delay * HZ;
	
//	set_current_state(TASK_INTERRUPTIBLE);

	do {

		//ret = sleep_on_timeout(&select_wait,delay*HZ);
		ret = select_fn(0,0,0,0,&timeout);

		 __set_current_state(TASK_RUNNING);
		 
		rtv.tv_usec = jiffies_to_usecs(do_div((*(u64*)&timeout), HZ));
		rtv.tv_sec = timeout;

		printk("timer_test:%5d select %ds over,ret =%d,remain:%ld us\n",count,delay,ret,
			(rtv.tv_sec*1000000+rtv.tv_usec));

//	 	set_current_state(TASK_INTERRUPTIBLE);

		stop = kthread_should_stop();
	}while(!stop);

//	 __set_current_state(TASK_RUNNING);

	thread = NULL;
	return 0;
}


struct jprobe my_probe={
	 .entry          = j__pollwait,

};

static int __init tst_init(void)
{       
		int ret =0;

        printk(KERN_INFO "Init called\n");

        //init_timer_on_stack(&exp_timer);
        init_timer(&exp_timer);

		get_tm_data(&first);

        exp_timer.expires = jiffies + delay * HZ;
        exp_timer.data = (unsigned long)&first;
        exp_timer.function = do_something;

        add_timer(&exp_timer);

		my_probe.kp.addr=(void*)0xffffffff8017dbcb;

		ret = register_jprobe (&my_probe);
		if (ret!=0 )
		{
			printk("register failed\n");
			return -1;
		}


        thread= kthread_run(work_fn, NULL,"tst_do_select");
	    if (!IS_ERR(thread))
        {
                printk("timer_test:tst_do_select kthread done\n");
        }
		else 
		{
			unregister_jprobe (&my_probe);
		}

        return 0;
}

static void __exit tst_exit(void)
{       
        del_timer_sync(&exp_timer);  
        if (thread)
			kthread_stop(thread);

		unregister_jprobe (&my_probe);

        printk(KERN_INFO "Exit called\n");
}

module_init(tst_init);
module_exit(tst_exit);

MODULE_LICENSE("GPL");
