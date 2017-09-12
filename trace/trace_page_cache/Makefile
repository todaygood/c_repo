# builds the kprobes example kernel modules;
# then to use one (as root):  insmod <module_name.ko>


obj-m := trace_page_cache.o

KDIR := /lib/modules/$(shell uname -r)/build
#KDIR := /usr/src/linux-2.6.39/

#KDIR := /usr/src/linux-2.6.27.19-5-obj/x86_64/xen

PWD := $(shell pwd)
default:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

clean:	
	rm -fr .tmp*  *.cmd  [mM]odule*  [a-z]*.mod* .[a-z]*.cmd *.ko *.o
