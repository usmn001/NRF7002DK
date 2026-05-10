

#include "led.hpp"
#define LED0_NODE DT_ALIAS(led0);   /* Line uses the devicetree macro DT_ALIAS() to get the node identifier symbol LED0_NODE, which will represent LED1 (node led_0).  */


led::led(bool led_state_c):led_light(GPIO_DT_SPEC_GET(DT_ALIAS(led0), gpios)),led_state{led_state_c}           // Default Constructor
{

}

/*led::led(const gpio_dt_spec &led):led_light(led)           // Copy Constructor
{
  
}*/

ret_en led::led_init()
{
    ret_en ret_stat = led_ready; 
    int ret;
    if (!gpio_is_ready_dt(&led_light))  /* Check if the device is ready using node led0 device pointer structure value */                  
    { 
		 ret_stat = led_busy;
	}
   
    ret = gpio_pin_configure_dt(&led_light, GPIO_OUTPUT_ACTIVE); /* Configure the pin as output using node led0 device pointer structure value */
	if (ret < 0) 
    {
		ret_stat = status_error;
	}
    return ret_stat;
}

void led::led_on()
{
gpio_pin_set_dt(&led_light,true);
}

void led::led_off()
{
gpio_pin_set_dt(&led_light,false);
}

