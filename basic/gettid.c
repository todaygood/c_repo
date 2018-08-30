#include <sys/types.h>
#include <stdio.h>
#include <unistd.h> 
#include <sys/syscall.h> 

  
//#define __NR_gettid      224  
  
pid_t  gettid(void)  
{  
    pid_t tid;  
  
    tid = syscall(__NR_gettid);  
    
    return tid;
    
} 
 
 
int main()
{

 pid_t pid=0;
 
 pid=gettid();
 
 printf("pid=%d\n",pid);
 
 return 0;

}


/*
大部分系统调用都包括了一个SYS_符号常量来指定自己到系统调用号的映射，因此上面第10行可重写为：
syscall函数原型为：
int syscall(int number, ...); 

其中number是系统调用号，number后面应顺序接上该系统调用的所有参数
*/

