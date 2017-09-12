/*
 * Here's a kernel module tracing process signal send and receive 
 * usage:
 * 
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kprobes.h>
#include <linux/version.h>

#include <linux/etherdevice.h>  //MAC地址的一些函数
#include <linux/ip.h>  // struct iphdr
#include <linux/tcp.h> //struct tcphdr
#include <linux/socket.h> //struct msghdr
#include <linux/skbuff.h> //struct sk_buff
#include <linux/netdevice.h>  //struct net_device

#if LINUX_VERSION_CODE <= KERNEL_VERSION(2,6,18)
#include <linux/kallsyms.h>
#endif

char* interface_name ="br0";
//module_param_named(interface, interface_name, charp, 0644);
module_param(interface_name, charp, 0644);

int var=3;
module_param(var, int, 0644);

int jdev_queue_xmit(struct sk_buff *skb)
{
	char str1[20];
	char str2[20];

	struct net_device *dev = skb->dev;
	if(!strcmp(interface_name,dev->name))
	{
		sprintf(str1,"%u.%u.%u.%u",NIPQUAD(ip_hdr(skb)->saddr));
		sprintf(str2,"%u.%u.%u.%u",NIPQUAD(ip_hdr(skb)->daddr));
		
		printk(KERN_EMERG "%s %d jdev_pick_tx %s dev:%p src ip %s,dst ip %s\n",
						current->comm,
						current->pid,
						interface_name,
						dev,
						str1,
						str2
						);

		/*打印内核栈*/				
		dump_stack();				

    }
	
	/* Always end with a call to jprobe_return(). */
	jprobe_return();
	return 0;
}

static struct jprobe my_jprobe = {
	.entry			= jdev_queue_xmit,
	
#if LINUX_VERSION_CODE > KERNEL_VERSION(2,6,18)
	.kp = {
		.symbol_name	= "dev_queue_xmit",
	},
#endif

};

static int __init jprobe_init(void)
{
	int ret;

#if LINUX_VERSION_CODE <= KERNEL_VERSION(2,6,18)
	unsigned long addr=0;

    addr = kallsyms_lookup_name("dev_queue_xmit");
	if (!addr)
	{
	    printk("kallsyms_lookup_name failed\n");
	    return -1;
	}
	my_jprobe.kp.addr=(kprobe_opcode_t *)addr;
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

module_init(jprobe_init);
module_exit(jprobe_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("trace sock tx");
MODULE_AUTHOR("Jun Hu(jhu@novell.com)");
