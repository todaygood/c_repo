#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
 
int main(void)
{
        pid_t pids[10];
        int i;
 
 		signal(SIGCHLD,SIG_IGN);
        for (i = 9; i >= 0; --i) {
                pids[i] = fork();
                if (pids[i] == 0) {
                        sleep(i+1);
                        _exit(0);
                }
        }

#if   0
        for (i = 9; i >= 0; --i)
                waitpid(pids[i], NULL, 0);
 #endif 
 
 	   while(1);
 	   
        return 0;
}
