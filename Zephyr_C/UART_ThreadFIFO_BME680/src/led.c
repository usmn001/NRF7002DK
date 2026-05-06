
#include <zephyr/kernel.h>        /* For using kernel services as we are using k_msleep() function*/
#include <zephyr/logging/log.h>
#include "led.h"

LOG_MODULE_REGISTER(LED_C,LOG_LEVEL_INF);




static bool led_state0 = true;
static bool led_state1 = true;



Error_Handler led_init()
{
    
	Error_Handler Status_en;
    ret_e ret;

	if (false==gpio_is_ready_dt(&led0) && false==gpio_is_ready_dt(&led1)) /* Check if the device is ready using node led0 device pointer structure value */
	{ 
		Status_en = status_error;
		LOG_INF("LED'S ARE NOT READY");
	}
	
    ret = (ret_e)gpio_pin_configure_dt(&led0, GPIO_OUTPUT_ACTIVE);/* Configure the pin as output using node led0 device pointer structure value */
	if(ret<0)
	{
		Status_en = status_error;
		LOG_INF("LED0 NOT CONFIGURED");
	}
	
	ret = (ret_e)gpio_pin_configure_dt(&led1, GPIO_OUTPUT_ACTIVE);/* Configure the pin as output using node led0 device pointer structure value */
	if(ret<0)
	{
		Status_en = status_error;
		LOG_INF("LED1 NOT CONFIGURED");
	} 
	return Status_en;       
}

void led0_on()
{
gpio_pin_set_dt(&led0,true);
}

void led0_off()
{
gpio_pin_set_dt(&led0,false);
}

void led1_on()
{
gpio_pin_set_dt(&led1,true);
}

void led1_off()
{
gpio_pin_set_dt(&led1,false);
}




