#include <linux/kernel.h>
#include <linux/spinlock.h>
#include <linux/smp_lock.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/types.h>
#include <linux/timer.h>
#include <linux/miscdevice.h> 
#include <linux/fs.h>
#include <linux/notifier.h>
#include <linux/init.h>
#include <asm/uaccess.h>

#include <linux/security.h>

int my_inode_create (struct inode *dir,	struct dentry *dentry, int mode)
{
	
	printk("%s ------\n",__FUNCTION__);
	return 0;
}




struct security_operations my_security_ops =
{
	.inode_create= my_inode_create,

};









int my_security_init(void)
{
	int err = 0;
	
	err = register_security(&my_security_ops);
	if (err)
	{
		printk(KERN_ERR"register my security module failed\n");
		return err;
	}
	return 0;
}



void my_security_exit(void)
{

	
	
	
}


module_init(my_security_init);
module_exit(my_security_exit);






