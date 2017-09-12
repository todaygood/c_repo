#include <linux/types.h>
#include <linux/ioctl.h>

#define MF_MISCDEV_MINOR  10
#define FAULT_DEV_NAME  "fault"
#define FAULT_DEV_FILE  "/dev/"FAULT_DEV_NAME

#define MF_IOC_MAGIC			0xf5

#define MF_IOC_RD_MODE			_IOR(MF_IOC_MAGIC, 1, __u8)
#define MF_IOC_WR_MODE			_IOW(MF_IOC_MAGIC, 1, __u8)

#define MF_IOC_NULL_POINTER     _IO(MF_IOC_MAGIC,0)

#define MF_IOC_PANIC            _IO(MF_IOC_MAGIC,1)

#define MF_IOC_SPINLOCK_HANG    _IO(MF_IOC_MAGIC,2)


#define MF_IOC_LOOP             _IO(MF_IOC_MAGIC,3)

#define MF_IOC_KERN_STK_OVER    _IO(MF_IOC_MAGIC,4)

#define MF_KTHREAD_NULL_POINTER    _IO(MF_IOC_MAGIC,5)
#define MF_IOC_GENERAL_PROTECTION  _IO(MF_IOC_MAGIC,6)


