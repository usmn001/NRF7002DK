
#include <stdio.h> 
#include <zephyr/kernel.h>        /* For using kernel services as we are using k_msleep() function*/
#include <zephyr/drivers/gpio.h>  /* Contains structure gpio_dt_spec, the macros GPIO_DT_SPEC_GET(), and the functions, gpio_is_ready_dt(), gpio_pin_configure_dt() and gpio_pin_toggle_dt().*/

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS   1000

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
static struct gpio_callback BT0_CB_DATA; /* BT0_CB_DATA callback variable  hold information such as the pin number and the function to be called when an interrupt occurs    */

static bool led_state = true;

void BT0_Pressed_ISR(const struct gpio_dt_spec *device,struct gpio_callback * cb,uint32_t pins)
{
    led_state = false;
	gpio_pin_set_dt(&led,led_state);
}


int main(void)
{
	int ret = 0;
	
	Error_Handler Status_en;

	if (false==gpio_is_ready_dt(&led) && false==gpio_is_ready_dt(&BT0)) /* Check if the device is ready using node led0 device pointer structure value */
	{ 
		Status_en = status_error;
	}

	ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE); /* Configure the pin as output using node led0 device pointer structure value */
	if (ret < 0) 
	{
		Status_en = status_error;
	}

	ret = gpio_pin_configure_dt(&BT0, GPIO_INPUT );/* Configure the pin associated with BT0 device pointer structure as input */
	
	if (ret < 0) 
	{
	 Status_en = status_error;
	}

	
    ret = gpio_pin_interrupt_configure_dt(&BT0, GPIO_INT_EDGE_TO_ACTIVE); /*Configuring the BT0 Device Pointer Pointing To Pin 8 Of GPIO Port 1 As Interrupt */
	if (ret < 0) 
	{	
	Status_en = status_error;
	}
	

    gpio_init_callback(&BT0_CB_DATA,BT0_Pressed_ISR,BIT(BT0.pin)); /*Initializing struct gpio_callback, 
	                                                         where BT0_CB_DATA is instance of struct gpio_callback, 
															 BT0_Pressed_ISR is interrupt service routine, 
															 BIT Macro is configring & registering the port GPIO Port 1 Pin For Interrupt Handling*/
	
	gpio_add_callback(BT0.port,&BT0_CB_DATA);                /*Adding & Regsitering Device Pointer Port and struct BT0_CB_DATA */

	while (1) 
	{		
		led_state = true;
		gpio_pin_set_dt(&led,led_state);   /*Writing 1 to pin associated with device pointer struct led*/
		k_msleep(SLEEP_TIME_MS); /* kernel service function k_msleep() putting the main function to sleep for 1 second, resulting in the blinking behavior at 1-second intervals.*/  
		printf("LED state: %s\n", led_state ? "ON" : "OFF");	
	}
	return Status_en;
}
