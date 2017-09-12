#include<stdio.h>

extern void show(); 
extern int add(int,int);

int main()
{
	int  sum=0;

	printf("Invoke my so\n");

	show();
	
	sum=add(3,5);
	return 0;

}

