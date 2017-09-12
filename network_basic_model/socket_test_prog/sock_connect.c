
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


int main()
{
    int fd, r;
    struct sockaddr_in sa;

    fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (fd <0)
    {
        printf("socket failed\n");
        return -1;
        
    }
    printf("socket %d\n",fd);
    
    memset(&sa, 0, sizeof(sa));
    sa.sin_addr.s_addr = inet_addr("127.0.0.1");
    sa.sin_family      = AF_INET;
    sa.sin_port        = htons(80);
    
    r = connect(fd, (struct sockaddr *)&sa, sizeof(sa));
    if (!r)
    {
        printf("connect failed\n");
        return -2;
        
    }
    
   

    sleep(60);
    
    close(fd);
    return 0;
    
    
}


/*
during sleep
 sles11-1:/mnt/sda10/user/cpp # lsof -p 7150
COMMAND    PID USER   FD   TYPE DEVICE SIZE/OFF   NODE NAME
sock_conn 7150 root  cwd    DIR   8,10     4096 842131 /mnt/sda10/user/cpp
sock_conn 7150 root  rtd    DIR   8,11     4096      2 /
sock_conn 7150 root  txt    REG   8,10    12162 842153 /mnt/sda10/user/cpp/sock_connect
sock_conn 7150 root  mem    REG   8,11  1661454 283929 /lib64/libc-2.11.1.so
sock_conn 7150 root  mem    REG   8,11   149797 283922 /lib64/ld-2.11.1.so
sock_conn 7150 root    0u   CHR  136,0      0t0      3 /dev/pts/0
sock_conn 7150 root    1u   CHR  136,0      0t0      3 /dev/pts/0
sock_conn 7150 root    2u   CHR  136,0      0t0      3 /dev/pts/0
sock_conn 7150 root    3u  sock    0,6      0t0 131967 can't identify protocol

*/

