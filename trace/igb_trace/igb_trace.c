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

#include "igb.h"


#define JPROBE_NUM  2

void (*show_regs_funcp)(struct pt_regs *regs);
void jshow_regs(struct pt_regs *regs)
{
	jprobe_return();
	return;
}

static void jigb_reinit_locked(struct igb_adapter *adapter)
{
	int i;
	struct net_device *netdev = adapter->netdev;
	
	printk("netdev=%p, tx_queues num=%d\n",netdev,netdev->num_tx_queues);
	
	for (i = 0; i < netdev->num_tx_queues; i++) 
	{
		struct netdev_queue *txq;

		txq = netdev_get_tx_queue(netdev, i);
		if (netif_tx_queue_stopped(txq)) 
		{
			printk("netdev=%p,queue index %d stopped\n",netdev,i);
		}
	}

	jprobe_return();
	
}


static void jigb_up(struct igb_adapter *adapter)
{
	printk("jigb_up\n");

	jprobe_return();
	return 0;
}



static struct jprobe my_jprobe[JPROBE_NUM] = {
	{
		.entry			= jigb_reinit_locked,
		.kp = {
			.symbol_name	= "igb_reinit_locked",
		},
	},
	{
		.entry			= jigb_up,
		.kp = {
			.symbol_name	= "igb_up",
		},
	},
	{
		.entry			= jshow_regs,
		.kp = {
			.symbol_name	= "show_regs",
		},
	}
	
};

struct my_data {
	struct igb_adapter *adapter;
};

static int igb_up_entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
	struct my_data *data;
	struct igb_adapter *adapter;
	data = (struct my_data *)ri->data;
	adapter = data->adapter;
	printk("igb_up_entry_handler netdev:%p\n",adapter->netdev);

	return 0;
}

static int igb_up_return(struct kretprobe_instance *ri, struct pt_regs *regs)
{
	printk("igb_up_return");
	show_regs_funcp(regs);
	return 0;
}

static struct kretprobe  my_kretprobe = {
	.kp = {
	        .symbol_name	= "igb_up"
	      },
	.handler			= igb_up_return,
	.entry_handler		= igb_up_entry_handler,
	.data_size			= sizeof(struct my_data),
	.maxactive			= 20000,
};



static int __init jprobe_init(void)
{
	int ret;
	int i;
	for (i=0; i<JPROBE_NUM; i++)
	{
		ret = register_jprobe(my_jprobe+i);
		if (ret < 0) {
			printk(KERN_INFO "register_jprobe failed, i=%d,returned %d\n", i,ret);
			return -1;
		}
		
	}

	
	show_regs_funcp = my_jprobe[i].addr;

	ret = register_kretprobe(&my_kretprobe);
	if (ret < 0) 
	{
		printk(KERN_INFO "register_kretprobe failed, returned %d\n", ret);
		return -1;
	}
	
	

	return 0;
}

static void __exit jprobe_exit(void)
{
	int i=0;
	
	unregister_kretprobe(&my_kretprobe);
	
	for (i=JPROBE_NUM; i>0; i--)
	{
		unregister_jprobe(my_jprobe+i);
	}
	
	
}

module_init(jprobe_init)
module_exit(jprobe_exit)

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("trace process signal send and receive module");
MODULE_AUTHOR("Jun Hu(jhu@novell.com)");
