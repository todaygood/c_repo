#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kprobes.h>
#include <linux/version.h>
#include <linux/gfp.h>
#include <linux/types.h>

#include <linux/inet.h>
#include <net/inet_sock.h>
#include <net/tcp.h>
#include <net/af_unix.h>
#include <linux/socket.h>
#include <linux/un.h>
#include <linux/fcntl.h>

/*
 
bind(4, {sa_family=AF_FILE, path="/abc/dev/log"}, 15) = 0

static int unix_mkname(struct sockaddr_un *sunaddr, int len, unsigned *hashp)

*/

char* dirname="hujun";
module_param(dirname, charp, 0644);


int g_target=0;

int get_path_from_sockaddr(struct sockaddr_un*sunaddr,int len)
{
	if (len <= sizeof(short) || len > sizeof(*sunaddr))
        return -EINVAL;
    if (!sunaddr || sunaddr->sun_family != AF_UNIX)
        return -EINVAL;       

    if (sunaddr->sun_path[0]) 
	{
        ((char *)sunaddr)[len] = 0;
		printk("\npath is %s\n",sunaddr->sun_path);
    }

	return 0;

}


void j_security_socket_bind(struct socket *sock, struct sockaddr *address, int addrlen)
{
		printk("%s 1 ========\n",__FUNCTION__);
	if (!get_path_from_sockaddr((struct sockaddr_un*)address,addrlen))
	{
		printk("%s 2 ========\n",__FUNCTION__);
		g_target=1;
	}
	jprobe_return();

}

int j_unix_mkname(struct sockaddr_un *sunaddr, int len, unsigned *hashp)
{
	if (!get_path_from_sockaddr(sunaddr,len))
	{
		printk("%s ========\n",__FUNCTION__);
	}

	jprobe_return();

	return 0;
}

static struct jprobe my_jprobes[] = {
	{
        .entry          = j_security_socket_bind,
        .kp.symbol_name = "security_socket_bind",
	},
    {
        .entry          = j_unix_mkname,
        //.kp.symbol_name    = "",
    },
};



int ret_security_socket_bind(struct kretprobe_instance *ri, struct pt_regs *regs)
{
    long retval = regs_return_value(regs);

	printk("%s returned 0x%x\n", __FUNCTION__,retval);//wrong ,be 0xffff8800 retval

    return 0;
}

struct kretprobe my_kretprobes[]={
	{
		  .kp.symbol_name = "security_socket_bind",
		  .handler        = ret_security_socket_bind,
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
		if (i==ARRAY_SIZE(my_jprobes)-1)
			my_jprobes[i].kp.addr=(void*)0xffffffff8142f130;  // unix_mkname

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
MODULE_DESCRIPTION("trace bind");
MODULE_AUTHOR("Jun Hu(jhu@novell.com)");
