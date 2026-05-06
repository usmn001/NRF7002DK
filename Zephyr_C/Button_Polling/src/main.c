
#include <stdio.h> 
#include <zephyr/kernel.h>        /* For using kernel services as we are using k_msleep() function*/
#include <zephyr/drivers/gpio.h>  /* Contains structure gpio_dt_spec, the macros GPIO_DT_SPEC_GET(), and the functions, gpio_is_ready_dt(), gpio_pin_configure_dt() and gpio_pin_toggle_dt().*/

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS   100

/* The devicetree node identifier for the "led0" & sw0 aliases defined in nrf5340_cpuapp_common.dtsi. */
#define LED0_NODE DT_ALIAS(led0) /* Line uses the devicetree macro DT_ALIAS() to get the node identifier symbol from alias led0, which will represent node led0 */
#define SW0_NODE  DT_ALIAS(sw0)  /* Line uses the devicetree macro DT_ALIAS() to get the node identifier symbol from alias sw0,  which will represent node button0 */

typedef enum {
status_ok = 0,
status_error = 1
}Error_Handler;


/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios); /* Structure containing pointer to device node leds  */
static const struct gpio_dt_spec BT0 = GPIO_DT_SPEC_GET(SW0_NODE, gpios); /* Structure containing pointer to device node buttons  */

int main(void)
{
	int ret = 0;
	bool led_state = true;
	
	Error_Handler Status_en;

	if (false==gpio_is_ready_dt(&led) && false==gpio_is_ready_dt(&BT0)) /* Check if the device is ready using node led0 device pointer structure value */
	{ 
		Status_en = status_error;
	}

	ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE); /* Configure the pin as output using node led0 device pointer structure value */
	if (ret < 0) {
		Status_en = status_error;
	}

    ret = gpio_pin_configure_dt(&BT0, GPIO_INPUT); /* Configure the pin as output using node led0 device pointer structure value */
	if (ret < 0) {
		Status_en = status_error;
	}



	while (1) 
	{
		
		bool val = gpio_pin_get_dt(&BT0);
		if(val==true)
		{
		ret = gpio_pin_toggle_dt(&led);    /* Toggle the pin state using node device pointer structure value &led */
		if (ret < 0) 
		{
			Status_en = status_error;
			break;
		}
	   
		
		k_msleep(SLEEP_TIME_MS); /* kernel service function k_msleep() putting the main function to sleep for 1 second, resulting in the blinking behavior at 1-second intervals.*/
	    }
		else if(val==false)
		{
			gpio_pin_set_dt(&led,0);			
		}

        led_state = val;
		printf("LED state: %s\n", led_state ? "ON" : "OFF");
	
	}
	return Status_en;
}
