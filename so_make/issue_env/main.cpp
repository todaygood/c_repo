#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netdb.h>

extern void show2();

int
main(int argc, char **argv)
{
    void *handle;
    //double (*cosine)(double);
    void (*show_p)();
    char *error;

    int socketfd ;


   socketfd= socket(AF_INET, SOCK_RAW, IPPROTO_SCTP);
   if (-1 == socketfd)
      printf("create raw socket failed\n");
   else
      printf("create raw socket successfully, socketfd=%d\n", socketfd);


	show2();

    handle = dlopen("./libshow.so", RTLD_LAZY);
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

   //*(void **) (&cosine) = dlsym(handle, "_Z4showv");
     *(void **) (&show_p) = dlsym(handle, "_Z4showv");

   if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }

	 (*show_p)();
  // printf("%f\n", (*cosine)(2.0));
   dlclose(handle);
   exit(EXIT_SUCCESS);
}
