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
#include <linux/types.h>
#include <net/inet_sock.h>
#include <linux/jiffies.h>
#include <linux/version.h>
#include <linux/if_vlan.h>
 



bool debug=0;
module_param(debug, bool, 0644);
MODULE_PARM_DESC(debug, "show debug info");


struct tuple
{
	int sip; 
	int sport;
	int dip;
	int dport;
};



void print_tuple(struct tuple *tp)
{
#if 0
	printk("sip=%d.%d.%d.%d %d sport=%d,dip=%d.%d.%d.%d %d dport=%d\n",
	NIPQUAD(tp->sip),tp->sip,tp->sport,
	NIPQUAD(tp->dip),tp->dip,tp->dport);
#endif
}

void print_tuple_debug(struct tuple *tp)
{
	if (debug)
		print_tuple(tp);
}








int jvlan_do_receive(struct sk_buff **skbp, bool last_handler)
{
    struct sk_buff *skb = *skbp;   
    u16 vlan_id = skb->vlan_tci & VLAN_VID_MASK; 
    struct net_device *vlan_dev;   

	printk("hujun vlan id=%d\n",vlan_id);

    jprobe_return(); 	

}


static struct jprobe my_jprobes[] = {
	{
		.entry			= jvlan_do_receive,
		.kp.symbol_name	= "vlan_do_receive", 
	},
	
};



void print_monitor_target(struct tuple * tp , int timeout,int debug)
{
	printk("monitor target:");
    print_tuple(tp);
	printk("monitor param :timeout=%d ms,debug=%d\n",timeout,debug);
}

int init_module(void)
{
    int ret;
    int i;
	
	for (i=0; i <ARRAY_SIZE(my_jprobes) ; i++)
	{

		if ((ret = register_jprobe(my_jprobes+i)) <0) {
			printk("register_jprobe failed, returned %d\n", ret);
			return -1;
		}
		
        printk("Registered a jprobe.OK.%d\n",i);
	}
	

    return 0;

}

void cleanup_module(void)
{	
	int i ;
	for (i=ARRAY_SIZE(my_jprobes)-1; i>=0; i--)
	{	
		unregister_jprobe(my_jprobes+i);
	}
    printk("jprobe unregistered.OK.\n");
}


MODULE_LICENSE("GPL");
MODULE_AUTHOR("jhu@suse.com");
MODULE_DESCRIPTION("trace vlan,Module_version 1.3"); //keyword module_version

