#include <stdio.h>
#include <string.h>

int main()
{


	char buf[10] = {0};

	//sprintf(buf,"%02x",(unsigned char)-3);
	sprintf(buf,"%02x",-3);
	printf("%s\r\n",buf); //output:

	return 0;

}


