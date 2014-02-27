#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	int fd =0;
	char buf[5120]={0};
	int count=0;
	
	fd = open("/tmp/rw_test_file",O_CREAT| O_RDWR|O_SYNC);
	if (fd < 0 )
	{
		printf("open failed,fd=%d\n",fd);
		return -1;
	
	}
	
	memset(buf,1,5120);
	count= write (fd,buf, 4096);
	if (count<0)
	{
		printf("write failed,count=%d\n",count);
		close(fd);
		return -2;
	}
	
	close(fd);


	return 0;

}


