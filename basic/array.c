#include <stdio.h>


int  main()
{
  int i=0;
  int a[2]={0,1};

  
  for (i=2; i<10000; i++)
  {
	a[i]=i;
	printf("i=%d\n",i);
  }

	return 0;
}
