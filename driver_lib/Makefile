# Makefile

obj-m:= drv.o
drv-objs:= driver.o lib/libtest.a


KDIR:=/lib/modules/$(shell uname -r)/build
PWD:=$(shell pwd)
EXTRA_CFLAGS+= -mcmodel=kernel

default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
install:
	$(MAKE) -C $(KDIR) M=$(PWD) modules_install
	depmod -a 
