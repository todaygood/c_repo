#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kprobes.h>
#include <linux/version.h>
#include <linux/skbuff.h>
#include <net/ip.h>
#include <linux/netdevice.h>
#include <linux/if_arp.h>
#include <asm/ptrace.h>

#include "igb.h"
/*
¸ú×ÙresetÁ÷³Ì

*/

struct igb_adapter *igb_adapter =NULL ; 

void (*show_registers_p)(struct pt_regs *regs);
unsigned long (*kallsyms_lookup_name_p)(const char *name);


void jshow_registers(struct pt_regs *regs)
{
	jprobe_return();
}

unsigned long jkallsyms_lookup_name(const char *name)
{
	jprobe_return();
	return 0;
}


static struct jprobe kernel_trace_tools_probe[]= {
	{
		.entry          = jshow_registers,
		.kp.symbol_name	= "show_registers",
	},

	 {
		.entry          = jkallsyms_lookup_name,
		.kp.symbol_name	= "kallsyms_lookup_name",
	},

	
};


void jigb_reinit_locked(struct igb_adapter *adapter)
{
	if (adapter == igb_adapter)
	{
		dump_stack();
	}

	jprobe_return();

}



int jigb_up(struct igb_adapter *adapter)
{
	if (adapter == igb_adapter)
	{
		dump_stack();
	}

	jprobe_return();
	return 0;
}

static struct jprobe igb_reset_probe[] = {
	{
		.entry = jigb_reinit_locked,
		.kp.symbol_name = "igb_reinit_locked",
	},
	{
		.entry = jigb_up,
		.kp.symbol_name = "igb_up",
	}

};

int igb_up_entry_handler(struct kretprobe_instance *ri, struct pt_regs * regs)
{
	if ((unsigned long)igb_adapter != regs->bx)
	{
		printk("igb_up_entry_handler error\n");
	
	}
	
	return 0;
}


int igb_up_ret_handler(struct kretprobe_instance *ri ,struct pt_regs * regs)
{
	int retval= regs_return_value(regs);
	if ((unsigned long)igb_adapter != regs->bx)
	{
		printk("igb_up_ret_handler error\n");	
	}

	printk("igb_up return %d\n",retval);
	
	return 0;
}

static struct kretprobe  igb_up_finish_trace ={
	.kp.symbol_name = "igb_up",
	.entry_handler  = igb_up_entry_handler,	
	.handler        = igb_up_ret_handler,
	.maxactive      = 20,
};


int igb_reset_probe_register(void)
{
	int ret ;
	int i = 0;
	int j = 0;
	int count= ARRAY_SIZE(igb_reset_probe);
	
	for (i = 0;i < count; i++){
		ret = register_jprobe(igb_reset_probe+i);
		if (ret < 0) {
			for(j=i-1;j>=0;j--)
			{
				unregister_jprobe(igb_reset_probe+j);
			}
			printk(KERN_INFO "register_kprobe failed, i=%d,returned %d\n",i, ret);
			return ret;
		}
	}


	return 0;
}



void igb_reset_probe_unregister(void)
{
	int i = 0;
	int count= ARRAY_SIZE(igb_reset_probe);
	
	for (i = count;i >= 0; i--){
		unregister_jprobe(igb_reset_probe+i);	
	}	
}



int kernel_trace_tools_probe_register(void)
{
	int ret ;
	int i = 0;
	int j = 0;
	int count= ARRAY_SIZE(kernel_trace_tools_probe);
	
	for (i = 0;i < count; i++){
		ret = register_jprobe(kernel_trace_tools_probe+i);
		if (ret < 0) {
			for(j=i-1;j>=0;j--)
			{
				unregister_jprobe(kernel_trace_tools_probe+j);
			}
			printk(KERN_INFO "register_kprobe failed, i=%d,returned %d\n",i, ret);
			return ret;
		}
	}

	show_registers_p       = (void*)((kernel_trace_tools_probe+0)->kp.addr);
	kallsyms_lookup_name_p = (void*)((kernel_trace_tools_probe+1)->kp.addr);
	return 0;
}

void kernel_trace_tools_probe_unregister(void)
{
	int i = 0;
	int count= ARRAY_SIZE(kernel_trace_tools_probe);
	
	for (i = count;i >= 0; i--){
		unregister_jprobe(kernel_trace_tools_probe+i);	
	}

	
}

extern struct net  init_net;

struct net_device* get_net_device_byname(char*name)
{
	struct net_device* (*dev_get_by_name_p)(struct net *net, const char *name)= NULL;

	dev_get_by_name_p = kallsyms_lookup_name_p("dev_get_by_name");
	if (!dev_get_by_name_p)
	{
		return NULL;
	}

	return dev_get_by_name_p(&init_net,name);
	
}



int igb_dev_debug_init(void)
{
	int ret =0 ;
	struct net_device* eth1_netdev= NULL;
	struct net_device*  br1_netdev= NULL;

	ret = igb_reset_probe_register();
	if (ret)
	{
		return ret;
	}
	

	ret = kernel_trace_tools_probe_register();
	if(ret)
	{
		igb_reset_probe_unregister();
		return ret;
	}

	ret = register_kretprobe(&igb_up_finish_trace);
	if (ret)
	{
		goto out;
	}
	
	eth1_netdev= get_net_device_byname("eth1");
	br1_netdev = get_net_device_byname("br1");

	if (eth1_netdev && br1_netdev )
	{
		printk(KERN_INFO"eth1:%p,br1:%p\n",eth1_netdev,br1_netdev);
		igb_adapter = netdev_priv(eth1_netdev);
		printk("apapter num_tx_queues=%d\n",igb_adapter->num_tx_queues);
		printk("apapter netdev=%p\n",igb_adapter->netdev);
		return 0;
	}
	
out:	
	kernel_trace_tools_probe_unregister();
	igb_reset_probe_unregister();

	return -2;

}


void igb_dev_debug_exit(void)
{
	unregister_kretprobe(&igb_up_finish_trace);
	kernel_trace_tools_probe_unregister();
	igb_reset_probe_unregister();
}

module_init(igb_dev_debug_init)
module_exit(igb_dev_debug_exit)

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("trace igb net device");
MODULE_AUTHOR("Jun Hu(jhu@novell.com)");


