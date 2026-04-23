# Name of your module
obj-m += dynamic_driver.o

# Kernel build directory (current system)
KDIR := /lib/modules/$(shell uname -r)/build

# Current working directory
PWD := $(shell pwd)

# Default target
all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

# Clean build files
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
