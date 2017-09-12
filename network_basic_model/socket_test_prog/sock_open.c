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
    //fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd <0)
    {
        printf("socket failed\n");
        return -1;
        
    }
    
    sleep(60);
    
    return 0;
}
