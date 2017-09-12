#include <stdlib.h>  
#include <stdio.h>  
#include <unistd.h>  
#include <signal.h>  
  
#define SLEEP_TIME 6  
  
int time_out;  
  
void handler()  
{  
    printf("Wake up!\n");  
    time_out = 1;  
}  
  
int main()  
{  
    int i;  
    
    signal(SIGALRM, handler); 		//让内核做好准备，一旦接受到SIGALARM信号,就执行 handler  
    alarm(SLEEP_TIME);					//设置闹钟，准备睡觉  
    printf("Set alarm!\n");  
    
    for(i = 1;i < 2 * SLEEP_TIME && !time_out; i++)  
    {  
        printf("sleep %d ...\n",i);  
        sleep(1);  
        
        
		         if (i == SLEEP_TIME / 2) 
		        { 
		           printf("Turn off the alarm!\n");//我中途醒了，不需要闹钟，把闹钟关闭 
		           alarm(0); 
		        } 
    }  
      
    return 0;  
}








