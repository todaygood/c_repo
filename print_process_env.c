/*
*print process environment variable 
*
*
*/


#include <stdio.h>  
  
extern char **environ;  
int main(void)  
{  
    int i = 0;  
    while(environ[i] != 0)  
    {  
        printf("%s\n",environ[i]);  
        i++;  
    }  
} 
