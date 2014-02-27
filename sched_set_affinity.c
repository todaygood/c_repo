/*
pthread_setaffinity_np and sched_setaffinity ÑùÀý³ÌÐò
http://blog.xuite.net/csiewap/cc/16801379

sched_setaffinity example

C:
*/

#include <stdio.h>
#include <math.h>
#include <sched.h>
double waste_time(long n)
{
    double res = 0;
    long i = 0;
    while(i <n * 200000) {
        i++;
        res += sqrt (i);
    }
    return res;
}
int main(int argc, char **argv)
{
    unsigned long mask = 1;
   
    if (sched_setaffinity(0, sizeof(mask), &mask) <0) {
        perror("sched_setaffinity");
    }
   
    printf ("result: %f\n", waste_time (2000));
    mask = 2;
    if (sched_setaffinity(0, sizeof(mask), &mask) <0) {
        perror("sched_setaffinity");
    }
   
    printf ("result: %f\n", waste_time (2000));
}
 
