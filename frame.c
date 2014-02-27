#include <stdio.h>



int foo(int a)
{
    int b = 5;
    int c = 6;

    printf("a is %d\n", a);     //breakpoint

    return a+1;
}


int main(int argc, char **argv)
{
    int iRet = 0;
	int m =137;

	iRet = foo(m);

	printf("iRet = %d\n", iRet);

	return 0;
}
