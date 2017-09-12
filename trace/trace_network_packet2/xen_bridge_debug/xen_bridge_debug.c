
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kprobes.h>
#include <linux/version.h>
#include <linux/skbuff.h>
#include <net/ip.h>
#include <linux/netdevice.h>



int jdev_queue_xmit(struct sk_buff *skb)
{
	struct iphdr *iph;
	int proto_type;
	char srcipbuf[64];
	char dstipbuf[64];
	struct net_device *dev = skb->dev;
	iph = ip_hdr(skb);


	proto_type = iph->frag_off & htons(IP_OFFSET) ? 0 : iph->protocol;
	if(proto_type == IPPROTO_ICMP)
	{
		/* GSO will handle the following emulations directly. */
		if (netif_needs_gso(dev, skb))
		{	
			printk("go to the gso\n");
		}

		if (skb_shinfo(skb)->frag_list &&
		    !(dev->features & NETIF_F_FRAGLIST) &&
		    __skb_linearize(skb))
		{
			printk("need to free skb\n");
		}
		


		
		sprintf(srcipbuf, NIPQUAD_FMT, NIPQUAD(iph->saddr));
		sprintf(dstipbuf, NIPQUAD_FMT, NIPQUAD(iph->daddr));
		printk("srcip == %s dstip === %s \n", srcipbuf, dstipbuf);
		printk("dev name == %s\n", dev->name);
		printk("dev flags == %x\n", dev->flags );
		printk("dev->real_num_tx_queues=%d\n", dev->real_num_tx_queues);
		printk("skb->ip_summed=%x\n", skb->ip_summed);
		printk("skb->proto_csum_blank= %d\n",skb->proto_csum_blank);

	             

	}
	
	jprobe_return();
	return 0;


}



int jpfifo_fast_enqueue(struct sk_buff *skb, struct Qdisc* qdisc)
{
	struct iphdr *iph;
	int proto_type;
	char srcipbuf[64];
	char dstipbuf[64];
	struct net_device *dev;
	iph = ip_hdr(skb);


	proto_type = iph->frag_off & htons(IP_OFFSET) ? 0 : iph->protocol;
	if(proto_type == IPPROTO_ICMP)
	{
		struct netdev_queue *txq;
		dev = skb->dev;

		
		sprintf(srcipbuf, NIPQUAD_FMT, NIPQUAD(iph->saddr));
		sprintf(dstipbuf, NIPQUAD_FMT, NIPQUAD(iph->daddr));
		printk("srcip == %s dstip === %s skb->ip_summed==%d enter the enque\n", srcipbuf, dstipbuf, skb->ip_summed);
		 
		printk("skb->queue_mapping = %d\n", skb->queue_mapping);
		txq = netdev_get_tx_queue(dev, skb->queue_mapping);
		if (netif_tx_queue_stopped(txq)  )
		{
			printk("the txq is stopped\n");
		}

		if ( netif_tx_queue_frozen(txq))
		{
			printk("the txq is frozen\n");
		}
	}

	
	jprobe_return();
	return 0;


}


int jdev_hard_start_xmit(struct sk_buff *skb, struct net_device *dev,
			struct netdev_queue *txq)
{
	struct iphdr *iph;
	int proto_type;
	char srcipbuf[64];
	char dstipbuf[64];
	struct net_device *skbdev = skb->dev;
	iph = ip_hdr(skb);


	proto_type = iph->frag_off & htons(IP_OFFSET) ? 0 : iph->protocol;
	if(proto_type == IPPROTO_ICMP)
	{
		sprintf(srcipbuf, NIPQUAD_FMT, NIPQUAD(iph->saddr));
		sprintf(dstipbuf, NIPQUAD_FMT, NIPQUAD(iph->daddr));
		printk("srcip == %s dstip === %s  liyi debug  skb_dev==%s dev==%s\n", srcipbuf, dstipbuf, skbdev->name, dev->name);
    }

	
	jprobe_return();
	return 0;


}

#define JPROBE_FUNC_NUM  3
static struct jprobe my_jprobe[JPROBE_FUNC_NUM]= {
	{
		.entry			= jpfifo_fast_enqueue,	
		.kp = {
			.symbol_name	= "pfifo_fast_enqueue",
		},
	},
	{
		.entry			= jdev_hard_start_xmit,	
		.kp = {
			.symbol_name	= "dev_hard_start_xmit",
		},
	},
	{
		.entry			= jdev_queue_xmit,	
		.kp = {
			.symbol_name	= "dev_queue_xmit",
		},
	},

};


static struct kretprobe = {
	.kp.symbol_name = "igb_up",
    .entry = ,
}

int kretprobe_igb_up(struct igb_adapter *adapter);

static int __init jprobe_init(void)
{
	int ret;
	int i;

	for(i=0 ; i< JPROBE_FUNC_NUM; i++)	{	
		ret = register_jprobe(my_jprobe+i);
		if (ret < 0) {
			printk(KERN_INFO "register_jprobe failed, i=%d returned %d\n", i,ret);
			return -1;
		}

	}

	ret = register_kretprobe (&my_kretprobe);
	if (ret < 0)
	{
		for (i= JPROBE_FUNC_NUM; i>=0; i--)
		{
			unregister_jprobe(my_jprobe+i);
		}
	}
	
	return 0;
}

static void __exit jprobe_exit(void)
{
	int i;

	unregister_kretprobe (&my_kretprobe);
	for (i= JPROBE_FUNC_NUM; i>=0; i--)
	{
		unregister_jprobe(my_jprobe+i);
	}
	
}





module_init(jprobe_init)
module_exit(jprobe_exit)

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("trace xen bridge");
MODULE_AUTHOR("Jun Hu(jhu@novell.com)");




























