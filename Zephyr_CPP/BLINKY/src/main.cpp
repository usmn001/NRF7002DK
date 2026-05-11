
#include <stdio.h> 
#include <zephyr/kernel.h>        /* For using kernel services as we are using k_msleep() function*/
#include <zephyr/drivers/gpio.h>  /* Contains structure gpio_dt_spec, the macros GPIO_DT_SPEC_GET(), and the functions, gpio_is_ready_dt(), gpio_pin_configure_dt() and gpio_pin_toggle_dt().*/


#include "drivers/led.hpp"
#include "drivers/uart.hpp"
/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS   1000


/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */


int main(void)
{
	
	Led led1(0);
	Uart uart1;
	led1.init();
	uart1.init();
	led1.set_delay(1000);
	while (1) 
	{
		led1.on();
		led1.off();   
	}

	return 0;
}
