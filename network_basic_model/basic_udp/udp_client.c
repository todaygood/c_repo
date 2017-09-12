#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		printf("%s server_ipaddr  server_port\n",argv[0]);
		exit(0);
	}
	int sock;

	struct sockaddr_in toAddr;
	struct sockaddr_in fromAddr;
	unsigned int fromLen;
	char recvBuffer[128];
	int ret =0;

	sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (sock < 0)
	{
		printf("socket create failed\n");
		exit(1);
	}


	memset(&toAddr, 0, sizeof(toAddr));
	toAddr.sin_family = AF_INET;
	//toAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	toAddr.sin_addr.s_addr = inet_addr(argv[1]);
	toAddr.sin_port = htons(atoi(argv[2]));

#if 0
    ret = connect(sock,(struct sockaddr*)&toAddr,sizeof(struct sockaddr));
	if (ret !=0 ) 
	{
		printf("connect failed\n");
		exit(2);
	}
#endif 

	while (1)
	{
		char buf[255];
	    int  len=0;
		int  ret =0;

		memset(buf,0,255);

		printf("client send:");
	    gets(buf);	
		
		len = strlen(buf);
		
        ret =sendto (sock, buf, len, 0, (struct sockaddr *)&toAddr, sizeof(toAddr));
		
		if (ret!=len)
		{
			printf("sendto() failed.\n");
			close(sock);
			exit(1);
		}


		fromLen = sizeof(fromAddr);
		if (recvfrom (sock, recvBuffer, 128, 0, (struct sockaddr *)&fromAddr, &fromLen) < 0)
		{
			printf("recvfrom() failed.\n");
			close(sock);
			exit(1);
		}
		printf("server say:%s\n", recvBuffer);

	}
	close(sock);
	return 0 ;
}





