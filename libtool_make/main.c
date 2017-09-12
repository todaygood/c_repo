#include <stdio.h> 

extern int compress_file (const char *filename); 

int main (int argc, char *argv[]) 
{ 
		if (argc < 2) 
		{   
				printf ("usage : %s file\n", argv[0]); 
				return 1; 
		}   
		return compress_file (argv[1]); 
} 
