#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
     struct sockaddr_un address;
     int sockfd;
     int len;
     int i, bytes;
     int result;
     char ch_recv, ch_send;

     /*����socket,AF_UNIXͨ��Э��,SOCK_STREAM���ݷ�ʽ*/
     if ((sockfd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
             perror ("socket");
             exit (EXIT_FAILURE);
     }

     address.sun_family = AF_UNIX;
     strcpy (address.sun_path, "server_socket");
     len = sizeof (address);

     /*�������������������*/
     result = connect (sockfd, (struct sockaddr *)&address, len);
     if (result == -1) {
         printf ("ensure the server is up\n");
         perror ("connect");
         exit (EXIT_FAILURE);
     }

         for (i = 0, ch_send = 'A'; i < 0xfffffffffffffff5; i++, ch_send++) {
         if ((bytes = write(sockfd, &ch_send, 1)) == -1) { /*����Ϣ��������*/
             perror ("write");
             exit (EXIT_FAILURE);
         }

         sleep (2);    /*��Ϣ�������ٷ�һ��*/

         if ((bytes = read (sockfd, &ch_recv, 1)) == -1) { /*������Ϣ*/
             perror ("read");
             exit (EXIT_FAILURE);
         }

         printf ("receive from server data is %c\n", ch_recv);
     }
     close (sockfd);

     return (0);
}




