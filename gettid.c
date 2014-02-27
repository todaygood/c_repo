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
�󲿷�ϵͳ���ö�������һ��SYS_���ų�����ָ���Լ���ϵͳ���úŵ�ӳ�䣬��������10�п���дΪ��
syscall����ԭ��Ϊ��
int syscall(int number, ...); 

����number��ϵͳ���úţ�number����Ӧ˳����ϸ�ϵͳ���õ����в���
*/

