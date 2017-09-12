/*
 * Here's a kernel module tracing process signal send and receive 
 * usage:
 * #insmod signal_trace.ko target_name=vi (for example:vi)
   #vi a&
   #kill -6  pid of vi
   see output message:
   #tail -20 /var/log/messages  
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kprobes.h>
#include <linux/version.h>

#if LINUX_VERSION_CODE <= KERNEL_VERSION(2,6,18)
#include <linux/kallsyms.h>
#endif



char* target_name;
module_param(target_name,charp,0644);

static long jsend_signal(int sig, struct siginfo *info, struct task_struct *t,
			struct sigpending *signals)

{
	if (t && (0== strcmp(t->comm,target_name)) )
	{
		/*内核pid是线程id,即ps -eLf 中的LWP列*/
		printk(KERN_INFO "%s %d send signal %d to %s %d\n",
			current->comm,current->pid,
                        sig,
                        t->comm,t->pid);
		/*打印内核栈*/				
		dump_stack();				
						

	}

	/* Always end with a call to jprobe_return(). */
	jprobe_return();
	return 0;
}

static struct jprobe my_jprobe = {
	.entry			= jsend_signal,
	
#if LINUX_VERSION_CODE > KERNEL_VERSION(2,6,18)
	.kp = {
		.symbol_name	= "send_signal",
	},
#endif

};

static int __init jprobe_init(void)
{
	int ret;

#if LINUX_VERSION_CODE <= KERNEL_VERSION(2,6,18)
	unsigned long addr=0;

    addr = kallsyms_lookup_name("send_signal");
	if (!addr)
	{
	    printk("kallsyms_lookup_name failed\n");
	    return -1;
	}
	my_jprobe.kp.addr=addr;
#endif
	
	ret = register_jprobe(&my_jprobe);
	if (ret < 0) {
		printk(KERN_INFO "register_jprobe failed, returned %d\n", ret);
		return -1;
	}
	printk(KERN_INFO "Planted jprobe at %p, handler addr %p\n",
	       my_jprobe.kp.addr, my_jprobe.entry);
	return 0;
}

static void __exit jprobe_exit(void)
{
	unregister_jprobe(&my_jprobe);
	printk(KERN_INFO "jprobe at %p unregistered\n", my_jprobe.kp.addr);
}

module_init(jprobe_init)
module_exit(jprobe_exit)

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("trace process signal send and receive module");
MODULE_AUTHOR("Jun Hu(jhu@novell.com)");
