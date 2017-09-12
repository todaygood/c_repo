#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h> 
#include <string.h>
#include <netinet/in.h>
 

#define MAXLINE 80
#define SERV_PORT 8000

int main(void)
{
	struct sockaddr_in servaddr;
 
	int sockfd;
	int i, n;
	int ret =0;

	//sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd<0)
	{
	    perror("socket failed\n");
	    return -3;
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);
    
	ret= bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	if (0 != ret)
	{
	    perror("bind failed\n");
	    return -1;
	}
	
	ret = close(sockfd);
	if (0 != ret)
	{
	    perror("close failed\n");
	    return -2;
	}
	
	return 0;


}





