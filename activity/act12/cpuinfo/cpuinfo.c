#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <asm/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("WinJaroonPat");
MODULE_DESCRIPTION("CPU Info Character Device");

#define DEVICENAME "cpuinfo"
static int dev_major;
static int dev_open = 0;
static char *f_ptr;
static char f_data[256];  // Buffer to hold the CPU info string

// Function to execute the CPUID instruction (renamed to avoid conflict)
static inline void my_native_cpuid(unsigned int *eax, unsigned int *ebx,
                                    unsigned int *ecx, unsigned int *edx)
{
    asm volatile("cpuid"
                 : "=a" (*eax),
                   "=b" (*ebx),
                   "=c" (*ecx),
                   "=d" (*edx)
                 : "0" (*eax), "2" (*ecx)
                 : "memory");
}

// Read and populate the f_data buffer with CPU info
static void get_cpu_info(void)
{
    unsigned eax, ebx, ecx, edx;

    // Vendor ID
    eax = 0;
    my_native_cpuid(&eax, &ebx, &ecx, &edx);
    snprintf(f_data, sizeof(f_data), "Vendor ID: %c%c%c%c%c%c%c%c%c%c%c%c\n",
             (ebx) & 0xFF, (ebx >> 8) & 0xFF, (ebx >> 16) & 0xFF, (ebx >> 24) & 0xFF,
             (edx) & 0xFF, (edx >> 8) & 0xFF, (edx >> 16) & 0xFF, (edx >> 24) & 0xFF,
             (ecx) & 0xFF, (ecx >> 8) & 0xFF, (ecx >> 16) & 0xFF, (ecx >> 24) & 0xFF);

    // Features and other information
    eax = 1;  // Processor info and feature bits
    my_native_cpuid(&eax, &ebx, &ecx, &edx);
    snprintf(f_data + strlen(f_data), sizeof(f_data) - strlen(f_data),
             "Stepping: %d\nModel: %d\nFamily: %d\nProcessor Type: %d\nExtended Model: %d\nExtended Family: %d\n",
             eax & 0xF, (eax >> 4) & 0xF, (eax >> 8) & 0xF, (eax >> 12) & 0x3,
             (eax >> 16) & 0xF, (eax >> 20) & 0xFF);

    // Serial number
    eax = 3;  // Processor serial number
    my_native_cpuid(&eax, &ebx, &ecx, &edx);
    snprintf(f_data + strlen(f_data), sizeof(f_data) - strlen(f_data),
             "Serial Number: 0x%08x%08x\n", edx, ecx);
}

// Function prototypes
static int device_open(struct inode *, struct file *);
static int device_release(struct inode *inode, struct file *file);
static ssize_t device_read(struct file *, char *, size_t, loff_t *);

// File operations struct
static struct file_operations dev_fops = {
    .read = device_read,
    .open = device_open,
    .release = device_release
};

// Initialization function
int init_module(void)
{
    printk(KERN_INFO "CPUINFO: Device loaded\n");
    dev_major = register_chrdev(0, DEVICENAME, &dev_fops);
    if (dev_major < 0) {
        printk(KERN_ALERT "CPUINFO: Failed to register character device\n");
        return dev_major;
    }
    printk(KERN_INFO "CPUINFO: Major number is %d\n", dev_major);
    printk(KERN_INFO "To create a device file:\n");
    printk(KERN_INFO "\t'mknod /dev/%s c %d 0'.\n", DEVICENAME, dev_major);
    return 0;
}

// Cleanup function
void cleanup_module(void)
{
    printk(KERN_INFO "CPUINFO: Device unloaded\n");
    unregister_chrdev(dev_major, DEVICENAME);
}

// Open function
static int device_open(struct inode *inode, struct file *file)
{
    if (dev_open)
        return -EBUSY;

    dev_open++;
    f_ptr = f_data;
    get_cpu_info();  // Populate f_data with CPU info
    try_module_get(THIS_MODULE);
    return 0;
}

// Release function
static int device_release(struct inode *inode, struct file *file)
{
    dev_open--;
    module_put(THIS_MODULE);
    return 0;
}

// Read function
static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset)
{
    int bytes_read = 0;

    if (*f_ptr == 0) {
        return 0;  // No more data to read
    }

    while (length && *f_ptr) {
        put_user(*(f_ptr++), buffer++);
        length--;
        bytes_read++;
    }

    return bytes_read;
}

