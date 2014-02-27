#include <stdio.h>
//#define NDEBUG
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

static int
cmpstringp(const void *p1, const void *p2)
{
   /* The actual arguments to this function are "pointers to
      pointers to char", but strcmp(3) arguments are "pointers
      to char", hence the following cast plus dereference */

   return strcmp(* (char * const *) p1, * (char * const *) p2);
}

int
main(int argc, char *argv[])
{
   int j;
   char *p =NULL;

   assert(argc > 1);

   qsort(&argv[1], argc - 1, sizeof(char *), cmpstringp);

   p =malloc(50);
   free(p);
   free(p);

   for (j = 1; j < argc; j++)
       puts(argv[j]);
   exit(EXIT_SUCCESS);
}

/*
SEE ALSO
sort(1), alphasort(3), strcmp(3), versionsort(3)
*/

