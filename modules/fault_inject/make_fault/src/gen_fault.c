#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdint.h>
#include <getopt.h>

#include "mf_pub.h"


void usage(char*prog_name)
{
		fprintf(stderr,"Usage:%s -h -n -p -s\n",prog_name);
		fprintf(stderr,"-h          print help info\n");

		fprintf(stderr,"-n          null pointer\n");
		fprintf(stderr,"-p          panic\n");
		fprintf(stderr,"-s          spinlock hang\n");
		fprintf(stderr,"-a          kernel stack overflow\n");
		fprintf(stderr,"-m          kernel thread null pointer\n");
		fprintf(stderr,"-g          general protection\n");
}



int main(int argc,char**argv)
{
	int fd = 0;
	int ret = 0;
	unsigned long cmd =0;
	char c = 0;

	if (argc < 2 )
	{
		usage(argv[0]);
		return -1;
	}
	
	fd = open(FAULT_DEV_FILE,O_RDWR);
	if (fd < 0)
	{
		fprintf(stderr,"open char dev failed\n");
		return fd;
	}

	while ((c = getopt (argc, argv, "hnpslamg")) != EOF)
	switch (c) 
	{
		
		case 'h':
			usage(argv[0]);
			break;

		case 'n':
			cmd = MF_IOC_NULL_POINTER;
			break;
			
		case 'p':
			cmd = MF_IOC_PANIC;
			break;
			
		case 's':
			cmd = MF_IOC_SPINLOCK_HANG;
			break;
			
		case 'l':
			cmd = MF_IOC_LOOP;
			break;
			
		case 'a':
			cmd = MF_IOC_KERN_STK_OVER;
			break;

		case 'm':
			cmd = MF_KTHREAD_NULL_POINTER;
			break;
			
		case 'g':
			cmd = MF_IOC_GENERAL_PROTECTION;
			break;

		case '?':
			fprintf(stderr,"unsupported param\n");
			break;
	}
	

	ret = ioctl(fd,cmd,0);
	if (ret )
	{
		fprintf(stderr,"ioctl failed %d\n",ret);
		goto out;
	}

out:
	close(fd);
	return ret;
}





