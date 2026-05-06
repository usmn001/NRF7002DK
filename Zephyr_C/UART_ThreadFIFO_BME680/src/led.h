
#ifndef LED_FUNC_H
#define LED_FUNC_H



#include <zephyr/drivers/gpio.h>  /* Contains structure gpio_dt_spec, the macros GPIO_DT_SPEC_GET(), and the functions, gpio_is_ready_dt(), gpio_pin_configure_dt() and gpio_pin_toggle_dt().*/


/* The devicetree node identifier for the "led0" & sw0 aliases defined in nrf5340_cpuapp_common.dtsi. */
#define LED0_NODE DT_ALIAS(led0) /* Line uses the devicetree macro DT_ALIAS() to get the node identifier symbol from alias led0, which will represent node led0 */
#define LED1_NODE DT_ALIAS(led1)

typedef enum
{
OKAY = 1,
NOT_OKAY = 0
}ret_e;

typedef enum {
status_ok = 0,
status_error = 1
}Error_Handler;

static const struct gpio_dt_spec led0 = GPIO_DT_SPEC_GET(LED0_NODE, gpios); /* Structure containing pointer to device node leds  */
static const struct gpio_dt_spec led1 = GPIO_DT_SPEC_GET(LED1_NODE, gpios); /* Structure containing pointer to device node leds  */


Error_Handler led_init();
void led0_on();
void led0_off();
void led1_on();
void led1_off();			  
#endif







