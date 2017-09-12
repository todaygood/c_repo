
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/resource.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>

static int bind_and_listen(int fd, int port)
{
        struct sockaddr_in in_addr;
        int reuseaddr_on = 1;

        // addr reuse
        if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (const char *)&reuseaddr_on, sizeof(reuseaddr_on)) == -1)
                return -1;

        // bind & listen
        bzero(&in_addr, sizeof(in_addr));
        in_addr.sin_family      = AF_INET;
        in_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        in_addr.sin_port        = htons(port);

        if ( bind(fd, (struct sockaddr *) &in_addr, sizeof(in_addr)) == -1 )
                return -1;
 
#if 1
        if ( listen(fd, 64) == -1 )
                return -1;
#endif
 
        return fd;
}

int main()
{
    int fd, r;

    fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (fd <0)
    {
        printf("socket failed\n");
        return -1;
        
    }
    
    r  = bind_and_listen(fd, 2224);
    if (r <0)
    {
        printf("bind_and_listen failed\n");
        return -2;        
    }

    sleep(60);
    close(fd);
    return 0;
}


/*
only bind ,no listern 
sles11-1:/mnt/opt/user/cpp # lsof -p 7336
COMMAND    PID USER   FD   TYPE DEVICE SIZE/OFF   NODE NAME
sock_bind 7336 root  cwd    DIR   8,10     4096 842131 /mnt/sda10/user/cpp
sock_bind 7336 root  rtd    DIR   8,11     4096      2 /
sock_bind 7336 root  txt    REG   8,10    12196 842156 /mnt/sda10/user/cpp/sock_bind
sock_bind 7336 root  mem    REG   8,11  1661454 283929 /lib64/libc-2.11.1.so
sock_bind 7336 root  mem    REG   8,11   149797 283922 /lib64/ld-2.11.1.so
sock_bind 7336 root    0u   CHR  136,1      0t0      4 /dev/pts/1
sock_bind 7336 root    1u   CHR  136,1      0t0      4 /dev/pts/1
sock_bind 7336 root    2u   CHR  136,1      0t0      4 /dev/pts/1
sock_bind 7336 root    3u  sock    0,6      0t0 137728 can't identify protocol


bind_and_listen
during sleep

sles11-1:/mnt/opt/user/cpp # lsof -p 7082
COMMAND    PID USER   FD   TYPE DEVICE SIZE/OFF   NODE NAME
sock_bind 7082 root  cwd    DIR   8,10     4096 842131 /mnt/sda10/user/cpp
sock_bind 7082 root  rtd    DIR   8,11     4096      2 /
sock_bind 7082 root  txt    REG   8,10    12240 842156 /mnt/sda10/user/cpp/sock_bind
sock_bind 7082 root  mem    REG   8,11  1661454 283929 /lib64/libc-2.11.1.so
sock_bind 7082 root  mem    REG   8,11   149797 283922 /lib64/ld-2.11.1.so
sock_bind 7082 root    0u   CHR  136,1      0t0      4 /dev/pts/1
sock_bind 7082 root    1u   CHR  136,1      0t0      4 /dev/pts/1
sock_bind 7082 root    2u   CHR  136,1      0t0      4 /dev/pts/1
sock_bind 7082 root    3u  IPv4 128116      0t0    TCP *:efi-mg (LISTEN)
*/


