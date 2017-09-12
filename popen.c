

#include <stdio.h>

int main()
{
    FILE *filp=0;
	char command[100]="ls /" ;

	filp= popen(command, "r");
	if (filp)
	{
	    pclose(filp);
		return 0;
	}

	return -1;
}
