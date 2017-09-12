
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kprobes.h>
#include <linux/version.h>
 




static long j__kfree_skb(struct sk_buff *skb )
{
	if (skb && skb_shinfo(skb))
	{
		n = skb_shinfo(skb)->nr_frags;
		
        printk("skb:%p,n=%d, len=%d\n",skb,n,skb->len);
    }
             
	/*´òÓ¡ÄÚºËÕ»*/				
	//dump_stack();

	
	/* Always end with a call to jprobe_return(). */
	jprobe_return();
	return 0;
}

static struct jprobe my_jprobe = {
	.entry			= j__kfree_skb,
	
#if LINUX_VERSION_CODE > KERNEL_VERSION(2,6,18)
	.kp = {
		.symbol_name	= "__kfree_skb",
	},
#endif

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
MODULE_DESCRIPTION("trace reboot");
MODULE_AUTHOR("Jun Hu(jhu@novell.com)");
