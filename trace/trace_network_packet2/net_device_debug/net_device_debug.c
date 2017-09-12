

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kprobes.h>
#include <linux/version.h>
#include <linux/skbuff.h>
#include <net/ip.h>
#include <linux/netdevice.h>
#include <linux/if_arp.h>

extern struct net  init_net;
struct net_device* get_net_device(void)
{
	struct net_device* net_dev= NULL;
	unsigned short eth_type= ARPHRD_ETHER;

	char eth_mac [ETH_ALEN]={0};
	eth_mac[0]= 0x3c;
	eth_mac[1]= 0x4A;
    eth_mac[2]= 0x92;
    eth_mac[3]= 0x79;
	eth_mac[4]= 0xB1;
	eth_mac[5]= 0x6F;

	net_dev = dev_getbyhwaddr(&init_net,eth_type,eth_mac);
	if (!net_dev)
	{
		return NULL;
	}
	printk(KERN_INFO"eth name is %s, priv_flags=%u\n",net_dev->name,
			net_dev->priv_flags);

	return net_dev;
}




int net_device_debug_init(void)
{
	
	
	return 0;

}





void net_device_debug_exit(void)
{



}






module_init(net_device_debug_init)
module_exit(net_device_debug_exit)

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("trace netdivece");
MODULE_AUTHOR("Jun Hu(jhu@novell.com)");


