#include<unistd.h>
#include<signal.h>
#include<stdio.h>

void handler()
{
    printf("Hello\n");
    signal(SIGALRM, handler); //让内核做好准备，一旦接受到SIGALARM信号,就执行 handler
    alarm(5);
}

 

void main()
{
    int i;
    handler();
    
    for(i=1;i<21;i++)
    {
        printf("sleep %d ...\n",i);
        sleep(1);
    }
}
