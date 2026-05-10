
#include <stdio.h> 
#include <zephyr/kernel.h>        /* For using kernel services as we are using k_msleep() function*/
#include <zephyr/drivers/gpio.h>  /* Contains structure gpio_dt_spec, the macros GPIO_DT_SPEC_GET(), and the functions, gpio_is_ready_dt(), gpio_pin_configure_dt() and gpio_pin_toggle_dt().*/


#include "drivers/led.hpp"
/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS   1000


/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */


int main(void)
{
	
	led led1(0);
	led1.led_init();
	while (1) 
	{
		led1.led_on();
	    k_msleep(SLEEP_TIME_MS);   /* kernel service function k_msleep() putting the main function to sleep for 1 second, resulting in the blinking behavior at 1-second intervals.*/
		led1.led_off();
		k_msleep(SLEEP_TIME_MS);
	}

	return 0;
}
