#ifdef __linux__
#include <linux/version.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,17)
#define _GNU_SOURCE
#endif
#endif
#include <errno.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <poll.h>
#include <unistd.h>
#include <poll.h>
#ifdef sun
#include <sys/sockio.h>
#elif defined (__WIN32)
#include <winsock2.h>
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/uio.h>
#include <sys/ioctl.h>
#endif
#if defined (__osf__) || defined (__hpux)
#define socklen_t int
#endif
#if defined (__WIN32) || defined (__MSYS__)
typedef unsigned int nfds_t;
#endif

#if defined (__VMS)
typedef unsigned int socklen_t;
#endif

/*
* Functional Description
*
*       This example creates a socket of type SOCK_STREAM (TCP),
*       binds and listens on the socket, receives a message
*       and closes the connection.
*       Error messages are printed to the screen.
*
*       IPC calls used:
*       poll
*       accept
*       bind
*       close
*       listen
*       recv
*       shutdown
*       socket
*
*
* Formal Parameters
*       The server program expects one parameter:
*       portnumber ... port number where it will listen
*
*
* Routine Value
*
*       Status
*/

int ls;

void cleanup(int shut, int s, int howmany)
{
	int retval;

	/*
	 * Shutdown and close sock1 completely.
	 */
	if (shut)
	{
		retval = shutdown(s, howmany);
		if (retval == -1)
		{
			perror("shutdown");

		}
	}
	retval = close(s);
	if (retval)
	{
		perror("close");

	}
}																/* end cleanup */

void sighandler(int sig)
{
	if (sig == SIGINT)
	{
		cleanup(0, ls, 1);
		exit(EXIT_SUCCESS);
	}
}

void declsighandler()
{
#ifdef __WIN32
	signal(SIGINT, sighandler);
#else
	struct sigaction action;

	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGINT);
	action.sa_flags = 0;
	action.sa_handler = sighandler;
	sigaction(SIGINT, &action, NULL);
#endif
}

/*--------------------------------------------------------------------*/
int main(int argc, char **argv)
{

	char message[BUFSIZ];
	struct sockaddr_in s_name;		/* Address struct for s. */
	int opt = 1;
	int retval;										/* helpful for debugging */
	socklen_t namelength;
	int atmark;
	struct pollfd *fds = NULL;
	nfds_t nfds;
	int ret;

	/*
	 * Check input parameters.
	 */
	if (argc != 2)
	{
		printf("Usage: server portnumber.\n");
		exit(EXIT_FAILURE);
	}

	/*
	 * Open socket 2: AF_INET, SOCK_STREAM.
	 */
	if ((ls = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("socket");
		exit(EXIT_FAILURE);
	}
#ifdef __WIN32
	if (setsockopt
			(ls, SOL_SOCKET, SO_REUSEADDR, (const char *)&opt, sizeof opt) < 0)
	{
#else
	if (setsockopt(ls, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof opt) < 0)
	{
#endif
		printf("setsockopt (SO_RESUSEADDR): %s\r\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	/*
	 * Fill in the name & address structure for socket 2.
	 */
	s_name.sin_family = AF_INET;
	s_name.sin_port = htons(atoi(argv[1]));
	s_name.sin_addr.s_addr = htonl(INADDR_ANY);

	/*
	 * Bind name to socket 2.
	 */
	printf(" \t Bind name to ls. \n");
	retval = bind(ls, (struct sockaddr *)&s_name, sizeof s_name);
	if (retval)
	{
		perror("bind");
		cleanup(0, ls, 1);
		exit(EXIT_FAILURE);
	}

	/*
	 * Listen on socket 2 for connections.
	 */
	printf(" \t Listen on ls for connections. \n");
	retval = listen(ls, 5);
	if (retval)
	{
		perror("listen");
		cleanup(0, ls, 1);
		exit(EXIT_FAILURE);
	}
	declsighandler();
	nfds = 1;
	fds = (struct pollfd *)calloc(1, nfds * sizeof(struct pollfd));
	fds->fd = ls;
	fds->events = POLLIN | POLLPRI;
	for (;;)
	{
		int i;
		printf("  Selecting ...\n");
		ret = poll(fds, nfds, -1);
		if (ret == -1)
		{
			perror("poll");
			exit(EXIT_FAILURE);
		}
		for (i = 0; (i < nfds) && (ret); i++)
		{
			if (!(fds + i)->revents)
				continue;
			printf("  after : revents=0x%x, ret=%d\n\n", (fds + i)->revents, ret);
			ret--;
			if (((fds + i)->fd == ls) && ((fds + i)->revents & POLLIN))
			{
				/*
				 * Accept connection from socket ls:
				 * accepted connection will be on socket (fds+nfds)->fd.
				 */
				printf(" \t POLLIN on ls. Accepting connection\n");
				namelength = sizeof(s_name);
				fds = (struct pollfd *)realloc(fds, (nfds + 1) * sizeof(struct pollfd));
				(fds + nfds)->fd = accept(ls, (struct sockaddr *)&s_name, &namelength);
				if ((fds + nfds)->fd == -1)
				{
					perror("accept");
					cleanup(0, (fds + nfds)->fd, 1);
					fds = (struct pollfd *)realloc(fds, nfds * sizeof(struct pollfd));
					continue;
				}
				(fds + nfds)->events = POLLIN | POLLPRI | POLLRDBAND | POLLRDNORM;
#ifdef _GNU_SOURCE
				/*
				 * POLLRDHUP (since Linux 2.6.17)
				 */
				(fds + nfds)->events |= POLLRDHUP;
#endif
				nfds++;
				continue;
			}
			if ((fds + i)->revents & POLLNVAL)
			{
				printf("POLLNVAL on socket. Freeing resource\n");
				nfds--;
				memcpy(fds + i, fds + i + 1, nfds - i);
				fds = (struct pollfd *)realloc(fds, nfds * sizeof(struct pollfd));
				continue;
			}
			if ((fds + i)->revents & POLLHUP)
			{
				printf("\t POLLHUP => peer reset connection ...\n");
				cleanup(0, (fds + i)->fd, 2);
				nfds--;
				memcpy(fds + i, fds + i + 1, nfds - i);
				fds = (struct pollfd *)realloc(fds, nfds * sizeof(struct pollfd));
				continue;
			}
#ifdef _GNU_SOURCE
			if ((fds + i)->revents & POLLRDHUP)
			{
				printf("\t POLLRDHUP => peer disconnected ...\n");
				cleanup(1, (fds + i)->fd, 2);
				nfds--;
				memcpy(fds + i, fds + i + 1, nfds - i);
				fds = (struct pollfd *)realloc(fds, nfds * sizeof(struct pollfd));
				continue;
			}
#endif
			if ((fds + i)->revents & POLLERR)
			{
				printf("\t POLLERR => peer reset connection ...\n");
				cleanup(0, (fds + i)->fd, 2);
				nfds--;
				memcpy(fds + i, fds + i + 1, nfds - i);
				fds = (struct pollfd *)realloc(fds, nfds * sizeof(struct pollfd));
				continue;
			}
			if ((fds + i)->revents & POLLRDNORM)
			{
				retval = recv((fds + i)->fd, message, sizeof(message), 0);
				printf(" \t -> (recv) retval = %d.\n", retval);	/* ped */
				if (retval <= 0)
				{
					if (retval == 0)
					{
						printf("\t recv()==0 => peer disconnected...\n");
						cleanup(1, (fds + i)->fd, 2);
					}
					else
					{
						perror("\t receive");
						cleanup(0, (fds + i)->fd, 1);
					}
					nfds--;
					memcpy(fds + i, fds + i + 1, nfds - i);
					fds = (struct pollfd *)realloc(fds, nfds * sizeof(struct pollfd));
					continue;
				}
				printf(" \t Normal message :  %.*s\n", retval, message);
				continue;
			}
			if ((fds + i)->revents & (POLLPRI | POLLRDBAND))
			{
				retval = recv((fds + i)->fd, message, sizeof(message), MSG_OOB);
				printf(" \t -> (recv) retval = %d.\n", retval);	/* ped */
				if (retval == -1 && errno == EINVAL)
				{
					ioctl((fds + i)->fd, SIOCATMARK, &atmark);
					printf("\t \t atmark = %d\n", atmark);
					printf("\t \t PEEK ret = %d\n",
								 recv((fds + i)->fd, message, 1, MSG_PEEK));
					printf(" \t PEEK message: %c\n", message[0]);
					errno = 0;
					continue;
				}
				if (retval <= 0)
				{
					if (retval == 0)
					{
						printf("\t recv()==0 => peer disconnected...\n");
						cleanup(1, (fds + i)->fd, 2);
					}
					else
					{
						perror("\t recv");
						cleanup(0, (fds + i)->fd, 1);
					}
					nfds--;
					memcpy(fds + i, fds + i + 1, nfds - i);
					fds = (struct pollfd *)realloc(fds, nfds * sizeof(struct pollfd));
					continue;
				}
				else
					printf(" \t OOB message : %c\n", message[0]);
				continue;
			}
		}
	}
	/* Never reached */
#ifndef __HP_cc
	return 1;
#endif
}																/* end main */
