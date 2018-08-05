///////////////////////////////////////////////////////////////////////////////
//
// Comments:
// sudo insmod hello_world.ko PRINT_COUNT=5
// This will result in the hello world greeting printed 5 times
//
// To see the value of PRINT_COUNT after the driver is inserted
// sudo cat /sys/modules/hello_world/parameters/PRINT_COUNT
// To change it after the module is inserted...
// echo -n "10" > /sys.modules/hello_word/parameters/PRINT_COUNT 
//
///////////////////////////////////////////////////////////////////////////////
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>


//////////////////////////////////////////////////////////////////////////////
#define AUTHOR      "gitmogul"
#define DESCRIPTION "Hello world example"
#define VERSION     "1.0"

int PRINT_COUNT = 1;
module_param( PRINT_COUNT, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
 
//////////////////////////////////////////////////////////////////////////////
static int __init init_hello_world( void )
{
    int ret = 0;
    int count = 0;

    pr_info( "%s\n", __FUNCTION__ );
    for( count = 0; count < PRINT_COUNT; count++ ) {
        pr_info( "%s\n", "KE PASA MANG !!!" );
    }
 
    return ret;
}
 

//////////////////////////////////////////////////////////////////////////////
static void __exit exit_hello_world( void )
{
    int count;

    pr_info( "%s\n", __FUNCTION__ );
    for( count = 0; count < PRINT_COUNT; count++ ) {
        pr_info( "ADIOS MANG !!!\n" );
    }
    return;
}

///////////////////////////////////////////////////////////////////////////////
module_init( init_hello_world );
module_exit( exit_hello_world );

MODULE_LICENSE("GPL");
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_VERSION(VERSION);
///////////////////////////////////////////////////////////////////////////////

