/*
 *  module_param_test.c - Demonstrates command line argument passing to a module.
 */
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Peter Jay Salzman");


/* 
 * module_param(foo, int, 0000)
 * The first param is the parameters name
 * The second param is it's data type
 * The final argument is the permissions bits, 
 * for exposing parameters in sysfs (if non-zero) at a later stage.
 */
 
static short int myshort = 1;
module_param(myshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myshort, "A short integer");

static int myint = 420;
module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(myint, "An integer");

static long int mylong = 9999;
module_param(mylong, long, S_IRUSR);
MODULE_PARM_DESC(mylong, "A long integer");

static char *mystring = "blah";
module_param(mystring, charp, 0644);
MODULE_PARM_DESC(mystring, "A character string");


static int arr_argc = 0;
/*
 * module_param_array(name, type, num, perm);
 * The first param is the parameter's (in this case the array's) name
 * The second param is the data type of the elements of the array
 * The third argument is a pointer to the variable that will store the number 
 * of elements of the array initialized by the user at module loading time
 * The fourth argument is the permission bits
 */
 
static int myintArray[2] = { -1, -1 };
module_param_array(myintArray, int, &arr_argc, 0644);
MODULE_PARM_DESC(myintArray, "An array of integers");


static bool use_kthreads =false;	
module_param_named(tasklets, use_kthreads, invbool, 0);

static int __init hello_init(void)
{
	int i;
	printk(KERN_INFO "%d\n=============\n",GFP_KERNEL);
	printk(KERN_INFO "module_param_test\n=============\n");
	printk(KERN_INFO "myshort is a short integer: %hd\n", myshort);
	printk(KERN_INFO "myint is an integer: %d\n", myint);
	printk(KERN_INFO "mylong is a long integer: %ld\n", mylong);
	printk(KERN_INFO "mystring is a string: %s\n", mystring);
	for (i = 0; i < (sizeof myintArray / sizeof (int)); i++)
	{
		printk(KERN_INFO "myintArray[%d] = %d\n", i, myintArray[i]);
	}
	printk(KERN_INFO "got %d arguments for myintArray.\n", arr_argc);
	
	
	if(use_kthreads)
	{	
		printk(KERN_ALERT "use_kthreads=TRUE tasklets=False\n"); 	
	}	
	else
	{
		printk(KERN_ALERT "use_kthreads=FALSE \n"); 	
	}
	
	
	
	return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_INFO "Goodbye, module_param_test\n");
}

module_init(hello_init);
module_exit(hello_exit);



/*

sles103:/sys/module/module_param_test/parameters # echo 3,6 > myintArray
sles103:/sys/module/module_param_test/parameters # cat myintArray
3,6


字符串的改变比较麻烦：待验证

sles103:/sys/module/module_param_test/parameters # echo abcd > mystring
sles103:/sys/module/module_param_test/parameters # cat mystring

sles103:/sys/module/module_param_test/parameters # echo "abcd" > mystring
sles103:/sys/module/module_param_test/parameters # cat mystring
àm


*/
