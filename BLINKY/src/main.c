
#include <stdio.h> 
#include <zephyr/kernel.h>        /* For using kernel services as we are using k_msleep() function*/
#include <zephyr/drivers/gpio.h>  /* Contains structure gpio_dt_spec, the macros GPIO_DT_SPEC_GET(), and the functions, gpio_is_ready_dt(), gpio_pin_configure_dt() and gpio_pin_toggle_dt().*/

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS   1000

/* The devicetree node identifier for the "led0" alias. */
#define LED0_NODE DT_ALIAS(led0) /* Line uses the devicetree macro DT_ALIAS() to get the node identifier symbol LED0_NODE, which will represent LED1 (node led_0).  */

/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios); /* Structure containing pointer to device node led parameters */

int main(void)
{
	int ret;
	bool led_state = true;

	if (!gpio_is_ready_dt(&led)) { /* Check if the device is ready using node led0 device pointer structure value */
		return 0;
	}

	ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE); /* Configure the pin as output using node led0 device pointer structure value */
	if (ret < 0) {
		return 0;
	}

	while (1) {
		ret = gpio_pin_toggle_dt(&led);    /* Toggle the pin state using node device pointer structure value &led */
		if (ret < 0) {
			return 0;
		}

		led_state = !led_state;
		printf("LED state: %s\n", led_state ? "ON" : "OFF");
		k_msleep(SLEEP_TIME_MS); /* kernel service function k_msleep() putting the main function to sleep for 1 second, resulting in the blinking behavior at 1-second intervals.*/
	}
	return 0;
}
