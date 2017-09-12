# builds the kprobes example kernel modules;
# then to use one (as root):  insmod <module_name.ko>


obj-m := net_device_debug.o

KDIR := /lib/modules/$(shell uname -r)/build


PWD := $(shell pwd)
default:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

clean:	
	rm -fr .tmp*  *.cmd  [mM]odule*  [a-z]*.mod* .[a-z]*.cmd *.ko *.o
