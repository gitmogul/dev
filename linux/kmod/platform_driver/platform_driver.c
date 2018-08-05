#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/slab.h>

#include <linux/platform_device.h>

///////////////////////////////////////////////////////////////////////////////
#define NUM_SHADOW_DEVICES 3
#define AUTHOR      "gitmogul"
#define DESCRIPTION "Platform driver example"
#define VERSION     "1.0"

struct _shadow_device_data {
    // random stuff
    int bus;
    int address;
    int flags;
};

static struct _shadow_device_data shadow_device_data[NUM_SHADOW_DEVICES] = {
    {
        .bus = 0,
        .address = 0,
        .flags = 0xff
    },
    {
        .bus = 0,
        .address = 1,
        .flags = 0xff
    },
    {
        .bus = 0,
        .address = 2,
        .flags = 0xff
    }
};

///////////////////////////////////////////////////////////////////////////////
static void shadow_device_release( struct device *p_device )
{
    struct _shadow_driver_data* p_driver_data = dev_get_drvdata( p_device );

    pr_info( "%s\n", __FUNCTION__ );

    kzfree( p_driver_data );
    p_driver_data = NULL;
    return;
}

///////////////////////////////////////////////////////////////////////////////
static int shadow_device_suspend( struct device *p_device )
{
    struct _shadow_driver_data* p_driver_data = dev_get_drvdata( p_device );

    pr_info( "%s\n", __FUNCTION__ );
    if( p_driver_data );
    return 0;
}

///////////////////////////////////////////////////////////////////////////////
static int shadow_device_resume( struct device *p_device )
{
    struct _shadow_driver_data* p_driver_data = dev_get_drvdata( p_device );

    pr_info( "%s\n", __FUNCTION__);
    if( p_driver_data );
    return 0;
}

static struct platform_device shadow_device[NUM_SHADOW_DEVICES] = {
    {
        .name = "shadow-device",
        .id	= 0,
        .dev = {
            .platform_data = &shadow_device_data[0],
    		.release = shadow_device_release,
	    }
    },
    {
        .name = "shadow-device",
        .id	= 1,
        .dev = {
            .platform_data = &shadow_device_data[1],
    		.release = shadow_device_release,
	    }
    },
    {
        .name = "shadow-device",
        .id	= 2,
        .dev = {
            .platform_data = &shadow_device_data[2],
    		.release = shadow_device_release,
	    }
    },
};

struct _shadow_driver_data {
    int flags;
};
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
static const struct dev_pm_ops shadow_dev_pm_ops = {
    .suspend = shadow_device_suspend,
    .resume	= shadow_device_resume,
};

///////////////////////////////////////////////////////////////////////////////
static int shadow_driver_probe( struct platform_device* p_device )
{
    struct _shadow_driver_data* p_driver_data;
    struct _shadow_device_data* p_device_data;

    pr_info( "%s, device id %i\n", __FUNCTION__, p_device->id );

    p_device_data = dev_get_platdata( &p_device->dev );
    p_driver_data = kzalloc( sizeof(struct _shadow_driver_data), GFP_KERNEL );
    if( p_driver_data == NULL )
        return -ENOMEM;

    platform_set_drvdata( p_device, p_driver_data );
    return 0;
}

///////////////////////////////////////////////////////////////////////////////
static int shadow_driver_remove( struct platform_device *p_device )
{
    struct _shadow_driver_data* p_driver_data = platform_get_drvdata( p_device );
    struct _shadow_device_data* p_device_data = dev_get_platdata( &p_device->dev );

    pr_info(  "%s, device id %i\n", __FUNCTION__, p_device->id );
    // free any resources here...
    if( p_driver_data );
    if( p_device_data );

    return 0;
}

///////////////////////////////////////////////////////////////////////////////
static struct platform_driver shadow_device_driver = {
    .probe = shadow_driver_probe,
    .remove = shadow_driver_remove,
    .driver = {
        .name	= "shadow-device",
        .owner	= THIS_MODULE,
        .pm	= &shadow_dev_pm_ops,
    },
};

///////////////////////////////////////////////////////////////////////////////
static int __init shadow_driver_init( void )
{
    int ret = 0;
    int index;

    pr_info( "%s\n",  __FUNCTION__ );

    // first register the driver
    platform_driver_register( &shadow_device_driver );

    // iterate through the device list and register the devices    
    for( index = 0; index < NUM_SHADOW_DEVICES; index++ ) {
        platform_device_register( &shadow_device[index] );
    }

    return ret; 
}

///////////////////////////////////////////////////////////////////////////////
static void __exit shadow_driver_exit( void )
{
    int index;

    pr_info( "%s\n", __FUNCTION__ );
    for( index = 0; index < NUM_SHADOW_DEVICES; index++ ) {
        platform_device_unregister( &shadow_device[index] );
    }

    platform_driver_unregister( &shadow_device_driver );
    return;
}

///////////////////////////////////////////////////////////////////////////////
MODULE_LICENSE("GPL");
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_VERSION(VERSION);

module_init(shadow_driver_init);
module_exit(shadow_driver_exit);
///////////////////////////////////////////////////////////////////////////////

