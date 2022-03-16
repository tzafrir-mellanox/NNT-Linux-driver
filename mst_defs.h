#ifndef MST_DEFS_H
#define MST_DEFS_H


#include <linux/kernel.h>
#include <linux/fs.h>


/* Passing MFT flag argument */
extern int is_mft_package;
extern struct driver_info mst_driver_info;

#define MST_DRIVER_NAME             "mst_driver"
#define MST_CLASS_NAME              "mst_class"
#define MST_DEVICE_PREFIX           "mt"
#define MST_DRIVER                  "MST Driver::"

#define CHECK_PCI_READ_ERROR(error, address) \
        if (error) { \
                mst_error ("Failed to read from address: %x\n", address); \
                goto ReturnOnFinished; \
        }

#define CHECK_PCI_WRITE_ERROR(error, address, data) \
        if (error) { \
                mst_error ("Failed to write to address: %x, data: %x\n", address, data); \
                goto ReturnOnFinished; \
        }

#define CHECK_ERROR(error) \
    if (error) { \
            goto ReturnOnFinished; \
    }

#define mst_error(format, arg...) \
    pr_err("%s function name:%s, line:%d | " format, MST_DRIVER, __func__, __LINE__, ## arg)

#define mst_debug(format, arg...) \
    pr_debug("%s function name:%s, line: %d | " format, MST_DRIVER, __func__, __LINE__, ## arg)


struct driver_info {
    int driver_major_number;
    int contiguous_device_numbers;
    struct class* class_driver;
};


#endif
