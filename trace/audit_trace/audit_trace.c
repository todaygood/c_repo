/*

 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kprobes.h>
#include <linux/version.h>
#include <linux/fs.h>
#include <linux/audit.h>



static void jaudit_log_task_info(struct audit_buffer *ab, struct task_struct *tsk)
{
	 
	printk(KERN_INFO "%s %d  \n",
					current->comm,current->pid                      
                );
	dump_stack();	
	
	jprobe_return();
}

static struct jprobe my_jprobe = {
	.entry			= jaudit_log_task_info,
	.kp = {
		.symbol_name	= "audit_log_task_info",
	},

};

static int __init jprobe_init(void)
{
	int ret;

	
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
MODULE_DESCRIPTION("trace set_anon_super module");
MODULE_AUTHOR("Jun Hu(jhu@novell.com)");



