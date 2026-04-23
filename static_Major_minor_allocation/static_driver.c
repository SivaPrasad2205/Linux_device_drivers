#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/module.h>
#include<linux/init.h>

//creating the dev with our custom amjor and minor numbers
dev_t dev=MKDEV(236,0);

//module init function

static int __init first_driver_init(void){
	register_chrdev_region(dev,1,"simple_sattic_driver");
	pr_info("Major =%d Minor = %d \n",MAJOR(dev),MINOR(dev));
	pr_info("kernel module inserted successfully...\n");
	return 0;
}
static void __exit driver_exit(void){
	unregister_chrdev_region(dev,1);
	pr_info("kernel Module removed successfully..\n");
}
module_init(first_driver_init);
module_exit(driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Siva");
MODULE_DESCRIPTION("Simple linux driver (Statically allocating the Major and Minor number)");
MODULE_VERSION("1.0");
