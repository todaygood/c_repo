#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


int main()
{

	pid_t f = fork();
	if (f > 0) {
		exit(0); // this is the parent dying, so the child will be an orphan
		         // and get adopted by init
	} else if (f == 0) {
		pid_t m=fork();
		if (m>0)
		{
			
		}
		else
		{

			sleep(1000); // This is the child doing something that takes enough time for
		            // its parent to commit suicide (exit(0)) and then for you to
		            // observe that it has now been adopted by init
			exit(0);    // And now it dyes as well, so init should reap its status, but
		            // it may be a zombie for a short amount of time first.
		}
	} else
	{
		printf("fork failed\n");
		return -1;	
	}


}
