#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kprobes.h>
#include <linux/version.h>

#if LINUX_VERSION_CODE <= KERNEL_VERSION(2,6,18)
#include <linux/kallsyms.h>
#endif




static long jsys_reboot(int magic1, int  magic2, unsigned int  cmd, void __user * arg)
{
	
	printk(KERN_EMERG "%s %d send reboot command %d to kernel\n",
					current->comm,
					current->pid,
                    cmd);
             
	dump_stack();

	
	/* Always end with a call to jprobe_return(). */
	jprobe_return();
	return 0;
}

static struct jprobe my_jprobe = {
	.entry			= jsys_reboot,
	
#if LINUX_VERSION_CODE > KERNEL_VERSION(2,6,18)
	.kp = {
		.symbol_name	= "sys_reboot",
	},
#endif

};

static int __init jprobe_init(void)
{
	int ret;

#if LINUX_VERSION_CODE <= KERNEL_VERSION(2,6,18)
	unsigned long addr=0;

    addr = kallsyms_lookup_name("sys_reboot");
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
MODULE_DESCRIPTION("trace reboot");
MODULE_AUTHOR("Jun Hu(jhu@novell.com)");
