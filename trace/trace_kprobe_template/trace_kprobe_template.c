
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kprobes.h>
#include <linux/version.h>
#include <linux/gfp.h>
#include <linux/types.h>

#include <linux/inet.h>
#include <net/inet_sock.h>
#include <net/tcp.h>

void j__kfree_skb(struct sk_buff *skb)
{
	if (skb ==NULL)
	{
		dump_stack();
	}

	jprobe_return();

}



static struct jprobe my_jprobes[] = {
	{
		.entry			= j__kfree_skb,
		.kp.symbol_name	= "__kfree_skb",
	},
		
};




int ret_do_fork(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    unsigned long retval = regs_return_value(regs);

	
	if (retval)
		printk("%s returned 0x%lx\n", __FUNCTION__,retval);//wrong ,be 0xffff8800 retval



    return 0;
}





struct kretprobe my_kretprobes[]={
	{
		  .handler        = ret_do_fork,
		  .entry_handler  = NULL,
		  .data_size      = 0,
		  .maxactive      = 20,
	},
};


int init_module(void)
{
	int ret=0;
	int i=0;
	int j=0;

	for(i=0; i <ARRAY_SIZE(my_jprobes) ; i++)
    {
        if ((ret = register_jprobe(my_jprobes+i)) <0) {
            printk("1 register failed, returned %d\n", ret);
			ret = -1;	
			goto err_i;
        }

        printk("1 registered OK.%d\n",i);
    }

	for(j=0; j <ARRAY_SIZE(my_kretprobes) ; j++)
    {

        if ((ret = register_kretprobe(my_kretprobes+j)) <0) {
            printk("2 register failed, returned %d\n", ret);
			ret = -1;	
			goto err_j;
        }

        printk("2 registered OK.%d\n",j);
    }
	
	return 0;

err_j:
	for (j=j-1;j>=0;j--)
	{
		unregister_kretprobe(my_kretprobes+j);
	}
	
err_i:
	for (i=i-1;i>=0;i--)
	{
        unregister_jprobe(my_jprobes+i);
	}

	return ret;
}

void cleanup_module(void)
{
    int i ;
	int j ;

	for (j=ARRAY_SIZE(my_kretprobes)-1;j>=0;j--)
	{
		unregister_kretprobe(my_kretprobes+j);
	}

    for (i=ARRAY_SIZE(my_jprobes)-1; i>=0; i--)
    {
        unregister_jprobe(my_jprobes+i);
    }
    printk("unregistered.OK.\n");
}



MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("trace kprobe template ,kernel version >2.6.18");
MODULE_AUTHOR("Jun Hu(jhu@novell.com)");
