# builds the kprobes example kernel modules;
# then to use one (as root):  insmod <module_name.ko>


obj-m := xen_bridge_debug.o

#KDIR := /lib/modules/$(shell uname -r)/build
KDIR := /usr/src/linux-obj/x86_64/xen


PWD := $(shell pwd)
default:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

clean:	
	rm -fr .tmp*  *.cmd  [mM]odule*  [a-z]*.mod* .[a-z]*.cmd *.ko *.o
