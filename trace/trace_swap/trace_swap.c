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

 

static void j_drop_caches_sysctl_handler(ctl_table *table, int write,
					void __user *buffer, size_t *length, loff_t *ppos)
{
	
	int sysctl_drop_caches_val=*((int*) 0xffffffff81b79cac);
	if ((sysctl_drop_caches_val &1 )|| (sysctl_drop_caches_val &2 ))
	{
		printk("process %s pid=%d drop caches, sysctl_drop_caches=%d\n",
				current->comm,
				current->pid,sysctl_drop_caches_val);
		dump_stack();	
	}
	   
    jprobe_return();
    return;
}
static struct jprobe my_jprobe = {
	.entry			= j_drop_caches_sysctl_handler,
	.kp = {
		.symbol_name	= "drop_caches_sysctl_handler",
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
