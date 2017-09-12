#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>


int main (int argc, char *argv[])
{
         int server_sockfd, client_sockfd;
         int server_len, client_len;
         struct sockaddr_un server_address;      /*声明一个UNIX域套接字结构*/
         struct sockaddr_un client_address;
         int i, bytes;
         char ch_send, ch_recv;
         
        unlink ("server_socket"); /*删除原有server_socket对象*/
        
        /*创建 socket, 通信协议为AF_UNIX, SCK_STREAM 数据方式*/
         server_sockfd = socket (PF_UNIX, SOCK_STREAM, 0);
         if (server_sockfd < 0 )
         {
            printf("socket create error\n");
            return -1;  
         }
         printf("server_sockfd=%d\n",server_sockfd);
         
        /*配置服务器信息(通信协议)*/
         server_address.sun_family = AF_UNIX;
         
         
        /*配置服务器信息(socket 对象)*/
         strcpy (server_address.sun_path, "server_socket");
         
         
         
        /*配置服务器信息(服务器地址长度)*/
         server_len = sizeof (server_address);
         
        /*绑定 socket 对象*/
         i = bind (server_sockfd, (struct sockaddr *)&server_address, server_len);
         if (i<0)
         {
            printf("bind error %d\n ",i );
            return -2;
         }
         
         /*监听网络,队列数为5*/
         i= listen (server_sockfd, 5);
         if (i<0)
         {
            printf("listen error %d\n ",i );
            return -2;
         }
         
        printf ("Server is waiting for client connect...\n");
        
        
        client_len = sizeof (client_address);
        /*接受客户端请求; 第2个参数用来存储客户端地址; 第3个参数用来存储客户端地址的大小*/
         /*建立(返回)一个到客户端的文件描述符,用以对客户端的读写操作*/
         
         
         client_sockfd = accept (server_sockfd, 
                                 (struct sockaddr *)&server_address, 
                                 (socklen_t *)&client_len);
         if (client_sockfd == -1) 
         {
                 perror ("accept");
                 exit (EXIT_FAILURE);
         }
         
         
        printf ("The server is waiting for client data...\n");
        for (i = 0, ch_send = '1'; i < 0xfffffffffffffff5; i++, ch_send++) 
        {
                 if ((bytes = read (client_sockfd, &ch_recv, 1)) == -1) 
                 {
                         perror ("read");
                         exit (EXIT_FAILURE);
                 }
                printf ("The character receiver from client is %c\n", ch_recv);
                sleep (1);
                if ((bytes = write (client_sockfd, &ch_send, 1)) == -1)
                {
                         perror ("read");
                         exit (EXIT_FAILURE);
                }
         }
               
               
        close (client_sockfd);
        unlink ("server socket");
}


