#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc,char**argv)
{
    pid_t pid;
	int  status;

	if (argc!= 2 )
	{
		printf("Usage:%s pid \n",argv[0]);
		exit(-1);
	}

	pid = atoi(argv[1]);
	
	while(1)
	{
		waitpid(pid,&status,0);
		sleep(5);
	}

    printf("exiting.\n");

    return 0;
}
