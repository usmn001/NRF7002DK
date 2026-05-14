

#include "led.hpp"                  /* led0 alias is defined here /home/musman/ncs/nrfSDK/zephyr/boards/nordic/nrf7002dk/nrf5340_cpuapp_common.dtsi*/ 
#define LED0_NODE DT_ALIAS(led0);   /* Line uses the devicetree macro DT_ALIAS() to get the node identifier symbol LED0_NODE, which will represent LED1 (node led_0).  */

LOG_MODULE_REGISTER(LED0,LOG_LEVEL_INF);

Led::Led(bool led_state_c):led_light(GPIO_DT_SPEC_GET(DT_ALIAS(led0), gpios)),led_state{led_state_c}           // Default Constructor
{

}

/*led::led(const gpio_dt_spec &led):led_light(led)           // Copy Constructor
{
  
}*/

ret_en Led::init()
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

void Led::on()
{
gpio_pin_set_dt(&led_light,true);
led_state=true;
LOG_INF("LED STATE : %s ",led_state ? "true":"false");
k_msleep(delay);    /* kernel service function k_msleep() putting the main function to sleep for 1 second, resulting in the blinking behavior at 1-second intervals.*/
}

void Led::off()
{
gpio_pin_set_dt(&led_light,false);
led_state=false;
LOG_INF("LED STATE %s ",led_state ? "true":"false");
k_msleep(delay);    /* kernel service function k_msleep() putting the main function to sleep for 1 second, resulting in the blinking behavior at 1-second intervals.*/
}

void Led::set_delay(uint16_t delay_p)
{
    delay = delay_p;
}

