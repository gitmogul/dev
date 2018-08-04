///////////////////////////////////////////////////////////////////////////////
//
//
//
///////////////////////////////////////////////////////////////////////////////
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/hrtimer.h>

#define TIMER_INTERVAL_MS 1000
 
/////////////////////////////////////////////////////////////////////////////// 
static struct hrtimer _hrtimer;
 

//////////////////////////////////////////////////////////////////////////////
static enum hrtimer_restart timer_callback( struct hrtimer* p_hrtimer )
{
    ktime_t now;
    pr_info( "%s\n", __FUNCTION__ );

    // we need to modify the next fire jiffies....else beware :-)
    now = hrtimer_cb_get_time(p_hrtimer);
    hrtimer_forward( p_hrtimer, now, TIMER_INTERVAL_MS*1E6L );
    return HRTIMER_RESTART;
}

 
//////////////////////////////////////////////////////////////////////////////
static int __init init_timer_module( void )
{
    int ret = 0;
    ktime_t ktime;
 
    pr_info( "%s\n", __FUNCTION__ );
 
    // convert to nano seconds
    ktime = ktime_set( 0, TIMER_INTERVAL_MS * 1E6L );
    hrtimer_init( &_hrtimer, CLOCK_MONOTONIC, HRTIMER_MODE_REL );
    _hrtimer.function = &timer_callback;

    hrtimer_start( &_hrtimer, ktime, HRTIMER_MODE_REL );
    return ret;
}
 

//////////////////////////////////////////////////////////////////////////////
static void __exit exit_timer_module( void )
{
    int ret;
 
    pr_info( "%s\n", __FUNCTION__ );
    ret = hrtimer_cancel( &_hrtimer );
    return;
}

module_init( init_timer_module );
module_exit( exit_timer_module );
MODULE_LICENSE("GPL");
