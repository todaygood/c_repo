#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kprobes.h>
#include <linux/kallsyms.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/mm.h>
#include <linux/writeback.h>
#include <linux/sysctl.h>
#include <linux/gfp.h>

 
ssize_t jmtest_read(struct file *file, char __user *buf,
			 size_t count, loff_t *ppos)
{
	
	{
		printk("process %s pid=%d \n",
				current->comm,
				current->pid);
		dump_stack();	
	}
	   
    jprobe_return();
    return;
}
static struct jprobe my_jprobe = {
	.entry			= jmtest_read,
	.kp = {
		.symbol_name	= "",
	},
};


int init_module(void)
{
    int ret;

    if ((ret = register_jprobe(&my_jprobe)) <0) {
        printk("register_jprobe failed, returned %d\n", ret);
        return -1;
    }
    printk("Registered a jprobe.\n");
    return 0;
}

void cleanup_module(void)
{
    unregister_jprobe(&my_jprobe);
    printk("jprobe unregistered\n");
}

MODULE_LICENSE("GPL");
