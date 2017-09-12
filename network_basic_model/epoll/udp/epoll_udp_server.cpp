#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h> 
#include <errno.h> 
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define MAXLINE 10
#define OPEN_MAX 100
#define LISTENQ 20
//#define SERV_PORT 5555
#define INFTIM 1000 
#define MAX_EVENT 10000

void setnonblocking(int sock) 
{
	int opts;
	opts = fcntl(sock, F_GETFL);
	if (opts < 0)
	{
		perror("fcntl(sock,GETFL)");
		exit(1);
	}
	opts = opts | O_NONBLOCK;
	if (fcntl(sock, F_SETFL, opts) < 0)
	{
		perror("fcntl(sock,SETFL,opts)");
		exit(1);
	}
}

int main(int argc,char**argv) 
{
	int i, maxi, listenfd, connfd, sockfd, epfd, nfds;
	int ret;
	ssize_t n;
	char line[MAXLINE];
	socklen_t clilen;
	char szAddr[256] = "\0";
	
	//声明epoll_event结构体的变量,ev用于注册事件,数组用于回传要处理的事件
	struct epoll_event ev, events[20];
	
	if (argc <2 )
	{
		printf("Usage:%s port_number\n",argv[0]); 
		exit(1);
	}


	
	//生成用epoll专用文件描述符
	epfd = epoll_create(256);
	printf("epoll_create(256) return %d\n", epfd);

	struct sockaddr_in clientaddr;
	struct sockaddr_in serveraddr;

	listenfd = socket(AF_INET, SOCK_DGRAM, 0);
	socklen_t addrlen = sizeof(clientaddr);
	
	//把socket设置为非阻塞方式 
	setnonblocking(listenfd);

	//设置与要处理的事件相关的文件描述符 
	ev.data.fd = listenfd;

	//设置要处理的事件类型  
	ev.events = EPOLLIN | EPOLLET;

	//注册epoll事件
	ret = epoll_ctl(epfd, EPOLL_CTL_ADD, listenfd, &ev);

	printf("epoll_ctl return %d\n", ret);

	bzero(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;

//	char *local_addr = "127.0.0.1";
//	inet_aton(local_addr, &(serveraddr.sin_addr));
//	serveraddr.sin_addr.s_addr = inet_addr(local_addr);
	serveraddr.sin_addr.s_addr = htons(INADDR_ANY);
	serveraddr.sin_port = htons(atoi(argv[1]));

	bind(listenfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
	memset(line, 0, MAXLINE);


	for (;;)
	{
		
		//等待epoll事件的发生
		//nfds=epoll_wait(epfd,events,MAX_EVENT,-1);
		nfds = epoll_wait(epfd, events, MAX_EVENT, 0);

		//处理所发生的所有事件      
		for (i = 0; i < nfds; ++i)
		{
			if (events[i].events & EPOLLIN)
			{
				if ((sockfd = events[i].data.fd) < 0)
					continue;

				n= recvfrom(sockfd, line, MAXLINE, 0, (sockaddr *) & clientaddr, &addrlen);
				if (n  < 0) 
				{
					if (errno == ECONNRESET)
					{
						close(sockfd);
						events[i].data.fd = -1;
					}
					else
						printf("readline error\n");
				}
				else if (n == 0)
				{
					perror("connfd=0\n");
					close(sockfd);
					events[i].data.fd = -1;
				}


//				char *p = (char *)&clientaddr.sin_addr;
//				sprintf(szAddr, "%d.%d.%d.%d", *p, *(p + 1), *(p + 2), *(p + 3));
//				printf("recv %s from ip:%s\n", line, szAddr);
				printf("recv %s from ip:%s\n", line, inet_ntoa(clientaddr.sin_addr));
				
				//设置用于写操作的文件描述符       
				ev.data.fd = sockfd;
		
				//设置用于注测的写操作事件        
				ev.events = EPOLLOUT | EPOLLET;
		
				//修改sockfd上要处理的事件为EPOLLOUT        
				epoll_ctl(epfd, EPOLL_CTL_MOD, sockfd, &ev);
			}
			else if (events[i].events & EPOLLOUT)
			{
				if (events[i].data.fd == -1)
					continue;

				sockfd = events[i].data.fd;

				write(sockfd, line, n);
				printf("send %s\n", line);
				
				//设置用于读操作的文件描述符       
				ev.data.fd = sockfd;
		
				//设置用于注测的读操作事件      
				ev.events = EPOLLIN | EPOLLET;

				char buf[256]={0} ;

				sprintf(buf,"server welcome fd=%d\n",sockfd);

				sendto(sockfd, buf, strlen(buf), 0, (sockaddr *) & clientaddr, addrlen);
		
				//修改sockfd上要处理的事件为EPOLIN        
				epoll_ctl(epfd, EPOLL_CTL_MOD, sockfd, &ev);
			}
		}

	}//for end 
}



