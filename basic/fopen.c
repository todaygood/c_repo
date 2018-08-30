#include <stdio.h>
#include <unistd.h>

int main()
{
    FILE* fp = NULL;
    int i=0;

    fp= fopen("/tmp/file","w");
    for(i=0; i<10;i++)
    {
        sleep(1);
        fprintf(fp,"%d\n",i);

    }

    fclose(fp);
    return 0;

}



