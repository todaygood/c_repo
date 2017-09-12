#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc,char**argv)
{
	struct sockaddr_in sai;    /* input */
	socklen_t len;         /* input */
	char hbuf[NI_MAXHOST];

	if (argc !=2 )
	{
		printf("Usage:%s ip_address\n",argv[0]);
		exit(-1);
	}
	
	sai.sin_family=AF_INET;
 	sai.sin_port=0;
	inet_aton(argv[1],&sai.sin_addr);
	
	len = sizeof(sai);

	if (getnameinfo((struct sockaddr*)&sai, len, hbuf, sizeof(hbuf),
				NULL, 0, NI_NAMEREQD))
		printf("could not resolve hostname for %s\n",argv[1]);
	else
		printf("host=%s,%s\n", hbuf,argv[1]);

	return 0;
			

}


