#include <stdio.h>
int main()
{

    　　FILE *fp = fopen("/tmp/testfile", "w");

    　　int i = 0;

    　　for (i = 0; i < 3; ++i)

        　　
    {

        　　fprintf(fp, "%d\n", i);

        　　
    }

    　　fclose(fp);

    　　return 0;

    　　
}

