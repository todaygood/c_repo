#include <stdio.h>


int main()
{
	int i=0;
	int fd=0;
	char str[10];
	
	for (i=0; i<1025 ; i++)
	{
		sprintf(str,"%d",i);
		fd = open (str,O_RDWR);
		if (fd <0)
		{
			printf("open failed ,i=%d\n",i);
			return -1;
		}
	
	}

	return 0;

}


