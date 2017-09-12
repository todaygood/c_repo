
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
	int sock;
	struct sockaddr_in toAddr;
	struct sockaddr_in fromAddr;
	int recvLen;
	unsigned int addrLen;
	char recvBuffer[128];


	sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (sock < 0)
	{
		printf("socket create failed.\n");
		exit(0);
	}


	memset(&fromAddr, 0, sizeof(fromAddr));
	fromAddr.sin_family = AF_INET;
	fromAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	fromAddr.sin_port = htons(40000);

	if (bind(sock, (struct sockaddr *)&fromAddr, sizeof(fromAddr)) < 0)
	{
		printf("bind() failed.\n");
		close(sock);
		exit(1);
	}


	while (1)
	{
		char buf [255];
	    int  len  =0;

		memset(buf,0,255);

		addrLen = sizeof(toAddr);
		if ((recvLen = recvfrom(sock, recvBuffer, 128, 0, (struct sockaddr *)&toAddr,
									&addrLen)) < 0)
		{
			printf("()recvfrom() failed.\n");
			close(sock);
			exit(1);
		}
        
		printf("client says:%s\n",recvBuffer);
		printf("server send:");
		gets(buf);
		len = strlen(buf);

		if (sendto (sock, buf, len, 0, (struct sockaddr *)&toAddr,
				 sizeof(toAddr)) != len)
		{
			printf("sendto fail\r\n");
			close(sock);
			exit(0);
		}
	}

	return 0;
}
