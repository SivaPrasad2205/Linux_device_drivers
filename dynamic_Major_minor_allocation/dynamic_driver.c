#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/fs.h>

dev_t dev=0;


// Module Init function
static int __init driver_init(void){

	if((alloc_chrdev_region(&dev,0,1,"Dynamic_driver"))<0){
			pr_info("cannot allocate major number for device\n");
			return -1;
	}
	pr_info("Major= %d Minor = %d \n",MAJOR(dev), MINOR(dev));
        pr_info("Kernel Module Inserted Successfully...\n");
	return 0;
}

static void __exit driver_exit(void){
 unregister_chrdev_region(dev,1);
 pr_info("Kernel Module Removed Successfully...\n");
}
 
module_init(driver_init);
module_exit(driver_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("siva");
MODULE_DESCRIPTION("Simple linux driver (Dynamically allocating the Major and Minor number)");
MODULE_VERSION("1.1");
