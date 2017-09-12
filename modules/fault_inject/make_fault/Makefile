ifeq ($(KERNELRELEASE),)

  
KERNELDIR ?= /lib/modules/$(shell uname -r)/build 
PWD := $(shell pwd)

modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	
clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions  [mM]odule*  gen_fault

app:
	gcc -g -o gen_fault   gen_fault.c

.PHONY: modules clean

else   

obj-m += make_fault.o  
    
endif

