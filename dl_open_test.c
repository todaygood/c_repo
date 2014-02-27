#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int
main(int argc, char **argv)
{
   void *handle;
   double (*cosine)(double);
   char *error;

   handle = dlopen("libm.so", RTLD_LAZY);
   if (!handle) {
       fprintf(stderr, "%s\n", dlerror());
       exit(EXIT_FAILURE);
   }

   dlerror();    /* Clear any existing error */

   /* Writing: cosine = (double (*)(double)) dlsym(handle, "cos");
      would seem more natural, but the C99 standard leaves
      casting from "void *" to a function pointer undefined.
      The assignment used below is the POSIX.1-2003 (Technical
      Corrigendum 1) workaround; see the Rationale for the
      POSIX specification of dlsym(). */

   *(void **) (&cosine) = dlsym(handle, "cos");


    if ((error = dlerror()) != NULL)  {
       fprintf(stderr, "%s\n", error);
       exit(EXIT_FAILURE);
   }

   printf("%f\n", (*cosine)(2.0));
   dlclose(handle);
   exit(EXIT_SUCCESS);
}

/*
If this program were in a file named "foo.c", you would build the program with the following command:

   gcc -rdynamic -o foo foo.c -ldl

Libraries exporting _init() and _fini() will want to be compiled as follows, using bar.c as the example name:

   gcc -shared -nostartfiles -o bar bar.c

junwork:/Code # gcc -shared -nostartfiles -o share_dl_test   dl_open_test.c  
/usr/lib64/gcc/x86_64-suse-linux/4.7/../../../../x86_64-suse-linux/bin/ld: /tmp/ccPcuRjq.o: relocation R_X86_64_32 against `.rodata' can not be used when making a shared object; recompile with -fPIC
/tmp/ccPcuRjq.o: could not read symbols: Bad value
collect2: error: ld returned 1 exit status


*/

 
       
       
       

