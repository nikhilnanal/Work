#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h> // for accessing file operations structure available with the file system
#include <linux/cdev.h> // for creating a char device and accessing its cdev structure
#include <linux/semaphore.h> // for locking and creating semaphores
#include <asm/uaccess.h> // for copy_from_user and copy_to_user

// declared a char virtual device
struct fakedevice {
char data[100];
struct semaphore sem;
} virtual_device;


dev_t device_num; // dev_t is defined in linux/types.h is an unsigned 32 bit integer contains major+minor number.

/*
struct cdev {
  struct kobject kobj;
  struct module *owner;
  const struct file_operations *ops;
  struct list_head list;
  dev_t dev;
  unsigned int count;
 };
*/

struct file_operations{
        .owner   = THIS_MODULE;
        .open    = mycdev_open;
        .read    = mycdev_read;
        .write   = mycdev_write;
        .release = mycdev_release;
}mydev_fops;

struct cdev *mycdev; // declare a pointer to cdev struct object. the cdev struct contains the identity of the device and its driver
#define DEVICE_NAME "MYCHARDEV" // note this is a string char* required for alloc_char_region 's last argument.

#define DEVICE_NAME "MYCHARDEV" // note this is a string char* required for alloc_char_region 's last argument.

static int  mydevice_init(void)
{
        /* Step 1 : Allocate Device number
        int alloc_chrdev_region(dev_t *dev, unsigned int firstminor,
                        unsigned int count, char *name);
        */
        int ret = alloc_char_region(&device_num,0,1,DEVICE_NAME);
                if (ret < 0){
                        printk(KERN_ALERT "Failed to allocate device number");
                        return ret;
                }
        /* Step 2 : Initialize the character device.
          call the cdev_init to initialize or do manual initializations.Here manually initialized
                void cdev_init(struct cdev *cdev, struct file_operations *fops);
                in either case mycdev->owner must be set to THIS_MODULE.
        */
                mycdev = cdev_alloc();
                mycdev->owner = THIS_MODULE;
                mycdev->ops = &mydev_fops;

        /* Step 3 : Add the character device to the system by calling cdev_add. Check also for the
            return code for errors in adding the device to the segment.
                int cdev_add(struct cdev *dev, dev_t num, unsigned int count);                  
            Once a device is added, the kernel can access it any time so care must be taken that no further dependenvy exists
            otherwise if some step is missing, the kernel could crash.
        */
                ret = cdev_add(mycdev,device_num,1);
                if (ret < 0){
                        printk(KERN_ALERT "Failed to add the character device");
                        return ret ;
                }
return 0;
}
/* This function is called when the device module is removed. */
void mydevice_cleanup()
{
        /* 
        step 1: call cdev_del(cdev_t* dev); to delete the memory and everything else allocated. to this device.
        */
          cdev_del(mycdev);
        /* step 2: unregister the char device. numbers 
                void unregister_chrdev_region(dev_t first, unsigned int count); */
          unregister_chrdev_region(device_num,1);
}

//int mydevice_open(struct inode* mycdevInode,struct file* filp)
