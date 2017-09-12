/*
 *  linux/fs/proc/mtest.c
 *
 *  Copyright (C) 1992  by Linus Torvalds
 *
 */

#include <linux/types.h>
#include <linux/errno.h>
#include <linux/time.h>
#include <linux/kernel.h>
#include <linux/poll.h>
#include <linux/proc_fs.h>
#include <linux/fs.h>
#include <linux/syslog.h>

#include <asm/uaccess.h>
#include <asm/io.h>


static int mtest_open(struct inode * inode, struct file * file)
{
	printk(KERN_ERR "%s", __FUNCTION__);
	return 0;
}

static int mtest_release(struct inode * inode, struct file * file)
{
	printk(KERN_ERR "%s", __FUNCTION__);
	return 0;
}

ssize_t mtest_read(struct file *file, char __user *buf,
			 size_t count, loff_t *ppos)
{
	printk(KERN_ERR "%s", __FUNCTION__);
	return 0;
}

static unsigned int mtest_poll(struct file *file, poll_table *wait)
{
	printk(KERN_ERR "%s", __FUNCTION__);
	return 0;
}


static const struct file_operations proc_mtest_operations = {
	.read		= mtest_read,
	.poll		= mtest_poll,
	.open		= mtest_open,
	.release	= mtest_release,
	.llseek		= generic_file_llseek,
};

static int __init proc_mtest_init(void)
{
	proc_create("mtest", S_IRUSR, NULL, &proc_mtest_operations);
	return 0;
}

void  proc_mtest_exit(void)
{
	 remove_proc_entry("mtest",NULL);
}

module_init(proc_mtest_init);
module_exit(proc_mtest_exit);





