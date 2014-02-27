#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/mman.h>

/*
cat /proc/iomem

f2600000-f261ffff : e1000e


*/



int
main (int argc, char *argv[])
{
  char *mem;
  int fd;
  fd = open ("/dev/mem", O_RDWR);
  assert (fd >= 0);
  mem =
    mmap (NULL, getpagesize (), PROT_READ | PROT_WRITE, MAP_SHARED, fd,
	  (off_t) 0xf2600000);
  assert (mem != MAP_FAILED);
  printf ("Memory pointer: %p\n", mem);
  printf ("The PCI memory is : %#x\n", *mem);

#if WRITE
  mem = *argv[1];
  printf ("The PCI memory is : %#x\n", *mem);
#endif

  munmap (mem, getpagesize ());
  close (fd);
  return 0;
}
