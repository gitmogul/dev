///////////////////////////////////////////////////////////////////////////////
//
//
//
///////////////////////////////////////////////////////////////////////////////
#include <linux/kernel.h>
#include <linux/module.h>


//////////////////////////////////////////////////////////////////////////////
#define AUTHOR      "gitmogul"
#define DESCRIPTION "Hello world example"
#define VERSION     "1.0"

 
//////////////////////////////////////////////////////////////////////////////
static int __init init_hello_world( void )
{
    int ret = 0;

    pr_info( "%s\n", __FUNCTION__ );
    pr_info ("KE PASA MANG !!!\n" );
 
    return ret;
}
 

//////////////////////////////////////////////////////////////////////////////
static void __exit exit_hello_world( void )
{
    pr_info( "%s\n", __FUNCTION__ );
    pr_info ("ADIOS MANG !!!\n" );
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

