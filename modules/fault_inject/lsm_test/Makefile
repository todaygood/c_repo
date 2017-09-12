ifeq ($(KERNELRELEASE),)

  
KERNELDIR ?= /lib/modules/$(shell uname -r)/build 
PWD := $(shell pwd)

modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	
clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions  [mM]odule*  


.PHONY: modules clean

else   

obj-m += lsm_test.o
    
endif

