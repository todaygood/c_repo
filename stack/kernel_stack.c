
/**
 * kernel_stack.c
 */
#include<linux/kernel.h>
#include<linux/types.h>
#include<linux/stddef.h>
#include<linux/module.h>
 
#define NUM 256
 
static int just_copy_half(int *array, int count)
{
    int i;
    int another_array[count];
    for (i = 0; i < count; i++) {
        another_array[i] = array[i];
    }
    return 0;
}
 
static int __init kernel_stack_init(void)
{
    int ret = 0;
    int total = 0;
    int array[NUM];
    int i;
    for (i = 0; i < NUM; i ++)
        array[i] = i;
 
    for (i = 0; i < NUM; i ++)
        total += array[i];
 
    just_copy_half(array, NUM/2);
 
    printk("Total: %d\n", total);
 
    return ret;
}
 
static void __exit kernel_stack_fini(void)
{
 
    //Do Nothing
    return;
}
 
module_init(kernel_stack_init);
module_exit(kernel_stack_fini);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("hujun");




