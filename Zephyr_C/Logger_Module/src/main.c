
#include <stdio.h> 
#include <zephyr/kernel.h>        /* For using kernel services as we are using k_msleep() function*/
#include <zephyr/drivers/gpio.h>  /* Contains structure gpio_dt_spec, the macros GPIO_DT_SPEC_GET(), and the functions, gpio_is_ready_dt(), gpio_pin_configure_dt() and gpio_pin_toggle_dt().*/
#include <zephyr/logging/log.h>   /* Adding Header File For Logger Module*/

#ifdef CONFIG_MYFUNCTION
#include "myfunction.h"
#endif


/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS   1000

/* The devicetree node identifier for the "led0" & sw0 aliases defined in nrf5340_cpuapp_common.dtsi. */
#define LED0_NODE DT_ALIAS(led0) /* Line uses the devicetree macro DT_ALIAS() to get the node identifier symbol from alias led0, which will represent node led0 */
#define SW0_NODE  DT_ALIAS(sw0)  /* Line uses the devicetree macro DT_ALIAS() to get the node identifier symbol from alias sw0,  which will represent node button0 */

LOG_MODULE_REGISTER(MAIN_C_MODULE,LOG_LEVEL_DBG);   /*REGISTERING THE MODULE FOR LOGGING AND WITH SEVERITY LEVEL*/



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

static long int MAX_NUMBER = 10;



void BT0_Pressed_ISR(const struct gpio_dt_spec *device,struct gpio_callback * cb,uint32_t pins)
{
    led_state = false;
	gpio_pin_set_dt(&led,led_state);
	
	long int factorial=1;
	LOG_INF("Calculating the factorials of numbers from 1 to %ld:\n",MAX_NUMBER);
	for(uint8_t i = 1;i<=MAX_NUMBER;i++)
	{
		factorial = factorial * i;
		// For printing facorial of all numbers in the range i to MAX_NUMBER
		LOG_INF("Factorial Of Number %i is %ld\n",i,factorial);
	}
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
    
	LOG_INF("nRF Connect SDK Fundamentals - Lesson 4 - Exercise 1\n");
	char data[5] = "HELLO";
	while (1) 
	{		
		led_state = true;
		gpio_pin_set_dt(&led,led_state);   /*Writing 1 to pin associated with device pointer struct led*/
		k_msleep(SLEEP_TIME_MS); /* kernel service function k_msleep() putting the main function to sleep for 1 second, resulting in the blinking behavior at 1-second intervals.*/  
		LOG_INF("LED state: %s", led_state ? "ON" : "OFF");	
	    LOG_WRN("DUMPING HEX DATA : ");
		LOG_HEXDUMP_INF(data,sizeof(data),"Sample Data = ");
	}
	return Status_en;
}
