/********
*
* This client.c code does a socket connect followed by a socket close with no
* shutdown. Depending on whether you run this code on, it generates an RST or
* a FIN TCP/IP event. A FIN TCP/IP event means the TCP/IP stack where this code
* ran on performed an implicit socket shutdown on your behalf.
* With the tests performed on the above mentionned operating systems, it appears
* that all tested Unix/Linux systems generate an RST TCP/IP event, whereas
* Windows 7 and OpenVMS generate a FIN TCP/IP event.
*
* server_poll.c behavior on the tested operating systems:
*
* Linux generates a POLLHUP on RST and POLLRDHUP or recv == 0 on FIN if
* POLLRDHUP is undefined at compile-time.
*
* HP-UX generates a POLLERR on RST and an recv == 0 on FIN.
*
* AIX is a bit special. As far as it seems, it immediately answers with a
* [SYN,ACK] on poll, not leaving the necessary time for the server_poll to
* indeed honor the connect request with the accept statement. The consequence is
* that when usleep(TIME) with a short delay is programmed in this client.c code,
* the accept statement fails with an ECONNABORTED errno reason. Otherwise, when 
* given enough time for the accept statement to complete, the server_poll reacts
* on RST with an ECONNRESET on the recv statement and recv == 0 on FIN.
*
* OpenVMS and Windows 7 set errno to ECONNRESET on recv when RST and set
* recv == 0 on FIN.
********
*  client.c 
*********/
#ifdef __WIN32
#include <windows.h>
#include <winsock2.h>
#else
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#ifdef __VMS
#include <unixio.h>
#else
#include <sys/uio.h>
#endif
#endif
/*
*
*   MACRO DEFINITIONS
*
*/

#ifndef TIME
#define TIME 5
#endif

#ifndef vms
#define TRUE 1
#define FALSE 0
#endif

/*
* Functional Description
*
*       This example creates a socket of type SOCK_STREAM (TCP),
*       initiates a connection to the remote host, and shortly 
*       closes the connection WITHOUT calling shutdown.
*       Error messages are printed to the screen.
*
*       IPC calls used:
*       close
*       connect
*       gethostbyname
*       shutdown
*       socket
*
*
* Formal Parameters
*       The client program expects two parameters:
*       hostname ... name of remote host
*       portnumber ... port where remote host(server) is listening
*
*
* Routine Value
*
*       Status
*/
/*-----------------------------------------------------------*/
void
cleanup(int shut, int s)
{
        int     retval;

        /*
         * Shutdown socket completely -- only if it was connected
         */
        if (shut && shutdown(s,2)< 0)
            perror ("shutdown");

        /*
         * Close socket.
         */
        if (close (s))
            perror ("close");
 } /* end cleanup */
/*--------------------------------------------------------------------*/
int main(int argc,char **argv){

        int     sock_1;                         /* socket */
static  char    message[] = "Hi there.";
        struct  sockaddr_in sock2_name;     /* Address struct for socket2.*/
        struct  hostent         *hp;    /* Pointer to hostent data.  */
        int     flag;
        int     retval;                         /* helpful for debugging */
        int     shut = 0;                   /* flag to cleanup */
        int     status;                         /* For return status - ped - */
        struct linger linger;

        /*
         * Check input parameters.
         */
        if (argc != 3 )
                {
                printf("Usage: client hostname portnumber.\n");
                exit(1);
                }
        if (atoi(argv[1]) > 0 )  {
           /* Numeric */
           sock2_name.sin_family = AF_INET;
           sock2_name.sin_addr.s_addr = inet_addr(argv[1]);
        } else {
           if ((hp=gethostbyname(argv[1])) == NULL) {
                perror("bad hostname");
                exit(EXIT_FAILURE);
           }
           sock2_name.sin_family = hp->h_addrtype;
           memcpy(&sock2_name.sin_addr,hp->h_addr_list[0],sizeof(struct in_addr));
        }
        sock2_name.sin_port = htons(atoi(argv[2]));
        /*
         * Open socket 1: AF_INET, SOCK_STREAM.
         */
        printf(" \t Open socket 1: AF_INET, SOCK_STREAM. \n");
        if ((sock_1 = socket (AF_INET, SOCK_STREAM, 0)) == -1){
            perror( "socket");
            exit(EXIT_FAILURE);
        }
        linger.l_onoff = 1;
        linger.l_linger = 0;
        setsockopt(sock_1, SOL_SOCKET, SO_LINGER, (void *)&linger, sizeof(linger));

       /*
         * Connect socket 1 to sock2_name.
         */
        printf(" \t Connect socket 1 to sock2_name. \n");
        retval = connect(sock_1, (struct sockaddr *)&sock2_name, 
                          sizeof (sock2_name));
        if (retval){
            perror("connect");
            exit(EXIT_FAILURE);
        }
#ifdef _AIXVERSION_530 
        {
            int i;
            char ThisHostName[60];
            int found=0;
            /*
             * Under AIX Version 5.3, the sleep is necessary as the connect
             * above does not wait enough for remote peer accept completion
             * or an error return. This is only true when testing the
             * server_poll and client codes on the same host
             */
            if (gethostname(ThisHostName,sizeof(ThisHostName))){
                perror("gethostname");
                exit(EXIT_FAILURE);
            }
            printf (" \t ThisHostName=%s\n",ThisHostName);
            if ((hp = gethostbyname(ThisHostName)) == NULL){
                perror("gethostbyname");
                exit(EXIT_FAILURE);
            }
            for (i=0;i<hp->h_length;i++){
                 printf ("hp->h_addr_list[%d] = %s\n",i,inet_ntoa(*((struct in_addr *)hp->h_addr_list[0])));
                 if (!memcmp(&sock2_name.sin_addr,hp->h_addr_list[0],sizeof (struct in_addr)))
                     found=1;
           }
           if (sock2_name.sin_addr.s_addr == inet_addr("127.0.0.1") || found)
               sleep(TIME);
           else
               usleep(TIME);
        }
#else
        usleep(TIME);
#endif
        cleanup(FALSE, sock_1);
        printf("\t Client socket cleaned up\n");
        exit(EXIT_SUCCESS);
        return 1;
 } /* end main */

