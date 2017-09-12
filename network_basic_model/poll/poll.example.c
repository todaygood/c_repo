/** Name:	poll.example.c
** Author:	K. Reek
** Contributor:	Warren Carithers
** Description: Demonstrate the use of polling.  The parent thread creates
**		several children that write back to it through pipes; the
**		parent uses poll to read the data as it arrives even though
**		the order is (in principle) not known in advance.
** SCCS ID:	@(#)poll.example.c	1.3	02/17/05
** Compilation:	$com cc -mt $@ -o $* -lpthread
*/
/* START */
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <poll.h>

void child( int id, int fd, int delay ) {
	int	value = rand() % 100;

	/*
	** Wait for a random time
	*/
	printf( "\t\t\tChild %d pausing %d seconds before writing fd %d\n",
	    id, delay, fd );
	fflush( stdout );
	sleep( delay );

	/*
	** Write our value to the pipe
	*/
	printf( "\t\t\tProcess %d writing value %d\n", id, value );
	fflush( stdout );
	if( write( fd, &value, sizeof( value ) ) != sizeof( value ) ) {
		perror( "write" );
	}
	printf( "\t\t\tProcess %d exiting\n", id );
	fflush( stdout );
	exit( EXIT_SUCCESS );
}

#define	N_CHILDREN	4
#define	TIMEOUT		( 3 * 1000 )	/* poll timeout in milliseconds */

int main() {
	int	pipefd[ 2 ];
	int	i;
	int	n;
	struct	pollfd	fds[ N_CHILDREN ];

	srand( time( NULL ) );
/* STOP1 */
	/*
	** Create the child processes
	*/
	for( i = 0; i < N_CHILDREN; i += 1 ) {
		int	delay = rand() % 10 + 1;

		/*
		** Create the pipe
		*/
		if( pipe( pipefd ) < 0 ) {
			exit( EXIT_FAILURE );
		}

		/*
		** Create the new process
		*/
		switch( fork() ) {
		case -1:
			perror( "fork" );
			exit( EXIT_FAILURE );

		case 0:	/* child process */
			/*
			** Close the input side of the pipe, and then start
			*/
			close( pipefd[ 0 ] );
			child( i, pipefd[ 1 ], delay );
			/* NOTREACHED */

		default: /* parent process */
			/*
			** Close the output side of the pipe and save the
			** fd of the input side
			*/
			close( pipefd[ 1 ] );
			fds[ i ].fd = pipefd[ 0 ];
			fds[ i ].events = POLLRDNORM;
			break;
		}
	}
/* STOP2 */
	/*
	** Now read from the child processes
	*/
	for( n = N_CHILDREN; n > 0; ) {
		/*
		** See if anyone is ready right now
		*/
		i = poll( fds, N_CHILDREN, 0 );
		if( i == 0 ) {
			printf( "Nobody ready right now, must wait...\n" );
			fflush( stdout );
			i = poll( fds, N_CHILDREN, TIMEOUT );
			printf( "%d children ready after waiting:\n", i );
			fflush( stdout );
		} else  {
			printf( "%d children ready right now:\n", i );
			fflush( stdout );
		}

		for( i = 0; i < N_CHILDREN; i += 1 ) {
			/*
			** Any data available on this fd?
			*/
			if( ( fds[ i ].revents & POLLRDNORM ) != 0 ) {
				int	value, nbytes;

				/*
				** Able to read, so read what they sent
				*/
				nbytes = read( fds[ i ].fd, &value,
				    sizeof( value ) );
				if( nbytes != sizeof( value ) ) {
					perror( "read" );
					exit( EXIT_FAILURE );
				}

				printf( "Child %d returned %d\n", i, value );
				fflush( stdout );
			}
/* STOP3 */
			/*
			** Did the child close this yet?
			*/
			if( ( fds[ i ].revents & POLLHUP ) != 0 ) {
				printf( "HUP on fd %d from child %d\n",
				    fds[ i ].fd, i );
				fflush( stdout );
				fds[ i ].fd = -1;
				n -= 1;
			}
		}
		putchar( '\n' );
		fflush( stdout );
	}
}
