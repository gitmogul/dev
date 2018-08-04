///////////////////////////////////////////////////////////////////////////////
//
//
//
///////////////////////////////////////////////////////////////////////////////
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/timer.h>

#define TIMER_INTERVAL_MS 1000
 
/////////////////////////////////////////////////////////////////////////////// 
static struct timer_list _timer;
 

//////////////////////////////////////////////////////////////////////////////
static void timer_callback( struct timer_list* p_timer_list )
{
    pr_info( "%s\n", __FUNCTION__ );

    // we need to restart the timer or else it will be one shot
    mod_timer( p_timer_list, jiffies + msecs_to_jiffies(TIMER_INTERVAL_MS) );
    return;
}

 
//////////////////////////////////////////////////////////////////////////////
static int __init init_timer_module( void )
{
    int ret;
 
    pr_info( "%s\n", __FUNCTION__ );
 
    timer_setup( &_timer, timer_callback, 0 );
    ret = mod_timer( &_timer, jiffies + msecs_to_jiffies(TIMER_INTERVAL_MS) );
    if( ret )
        pr_info( "Error: creating timer %i\n", ret );
 
    return ret;
}
 

//////////////////////////////////////////////////////////////////////////////
static void __exit exit_timer_module( void )
{
    int ret;
 
    pr_info( "%s\n", __FUNCTION__ );
    ret = del_timer( &_timer );
    if (ret)
         pr_info( "timer is still in use...\n" );
 
    return;
}

module_init( init_timer_module );
module_exit( exit_timer_module );
MODULE_LICENSE("GPL");
