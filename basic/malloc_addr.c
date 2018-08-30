/**
  * malloc_addr.c
  */
#include <stdio.h>
#include <stdlib.h>
 
#define LARGE_SIZE   (5*(1<<20))
#define SMALL_SIZE   (1<<5)
 
int g;
 
int main (int argc, char *argv[])
{
  int l;
  int  *lp = malloc (LARGE_SIZE*sizeof(int));
  int  *sp = malloc (SMALL_SIZE*sizeof(int));
 
  printf ("address of g = %p\n", &g);
  printf ("address of l = %p\n", &l);
  printf ("address of lp = %p\n", lp);
  printf ("address of sp = %p\n", sp);
 
  free (lp);
  free (sp);
 
  exit (EXIT_SUCCESS);
}



