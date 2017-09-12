#include <linux/init.h>
#include <linux/module.h>
#include <linux/kthread.h>
#include <linux/gfp.h>
#include <linux/delay.h>
#include <linux/sched.h>
#include <linux/err.h>
MODULE_LICENSE ("Dual BSD/GPL");
int
test_thread (void *data)
{
  struct page *page = NULL;
  struct page *leave_one_page = NULL;
  set_current_state (TASK_UNINTERRUPTIBLE);
  printk ("thread start....\n");
  while (1)
    {
      msleep (10000);
      while ((page = alloc_page (GFP_ATOMIC)) != NULL)
	{
	  left_one_page = page;
	  printk ("page =%p\n", leave_one_page);
	}
      if (leave_one_page)
	__free_page (leave_one_page);
    }
  return 0;
}

static struct task_struct *task_test;
staticint
hello_init (void)
{
  int err;
  task_test = kthread_create (test_thread, NULL, "test_task");
  printk (KERN_ALERT "Hello, world\n");
  if (IS_ERR (task_test))
    {
      printk ("Unable to start kernel thread.\n");
      err = PTR_ERR (task_test);
      task_test = NULL;
      return err;
    }
  wake_up_process (task_test);
  return 0;
}

static void
hello_exit (void)
{
  printk (KERN_ALERT "Goodbye, cruel world\n");
  if (task_test)
    kthread_stop (task_test);
}

module_init (hello_init);
module_exit (hello_exit);
