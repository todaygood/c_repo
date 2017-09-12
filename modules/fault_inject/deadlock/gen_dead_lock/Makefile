#
# Makefile for the linux reiser-filesystem routines.
#

 





ifeq ($(KERNELRELEASE),)

  
    KERNELDIR ?= /lib/modules/$(shell uname -r)/build
    #KERNELDIR ?= /lib/modules/$(shell uname -r)/build
    #KERNELDIR ?= /usr/src/linux-headers-3.0.0-14
 
    PWD := $(shell pwd)

modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

modules_install:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules_install

clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions

.PHONY: modules modules_install clean

else   
    obj-m += gen_dead_lock.o
endif

