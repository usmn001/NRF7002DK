
#include <stdio.h> 
#include <zephyr/kernel.h>        /* For using kernel services as we are using k_msleep() function*/
#include <zephyr/drivers/gpio.h>  /* Contains structure gpio_dt_spec, the macros GPIO_DT_SPEC_GET(), and the functions, gpio_is_ready_dt(), gpio_pin_configure_dt() and gpio_pin_toggle_dt().*/
#include <zephyr/drivers/uart.h>  /* Contains UART Driver Structs*/
#include <zephyr/logging/log.h>

#ifdef CONFIG_MYFUNCTION
#include "myfunction.h"
#endif

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS   5000

/* The devicetree node identifier for the "led0" & sw0 aliases defined in nrf5340_cpuapp_common.dtsi. */
#define LED0_NODE DT_ALIAS(led0) /* Line uses the devicetree macro DT_ALIAS() to get the node identifier symbol from alias led0, which will represent node led0 */
#define LED1_NODE DT_ALIAS(led1)


LOG_MODULE_REGISTER(MAIN_C,LOG_LEVEL_INF);

typedef enum {
status_ok = 0,
status_error = 1
}Error_Handler;


/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */
static const struct gpio_dt_spec led0 = GPIO_DT_SPEC_GET(LED0_NODE, gpios); /* Structure containing pointer to device node leds  */
static const struct gpio_dt_spec led1 = GPIO_DT_SPEC_GET(LED1_NODE, gpios); /* Structure containing pointer to device node leds  */

const struct device *uart = DEVICE_DT_GET(DT_NODELABEL(uart0));   /* Getting UART Device Pointer */


static bool led_state0 = true;
static bool led_state1 = true;
static uint8_t tx_buf[] =   {"nRF Connect SDK Fundamentals Course\r\n"
                             "Press 1-3 on your keyboard to toggle LEDS 1-3 on your development kit\r\n"};

#define RECEIVE_TIMEOUT 10
static uint8_t rx_buf[2]={0};

static void uart_cb(const struct device *dev, struct uart_event *evt, void *user_data)
{
	switch (evt->type) {

	case UART_RX_RDY:
		if ((evt->data.rx.len) == 1) 
		{

			if (evt->data.rx.buf[evt->data.rx.offset] == '1') 
			{
				gpio_pin_toggle_dt(&led0);
				led_state0=gpio_pin_get_dt(&led0);
				LOG_INF("TURNED LED0 %s",led_state0 ? "ON": "OFF");
			} 
			else if (evt->data.rx.buf[evt->data.rx.offset] == '2') 
			{
				gpio_pin_toggle_dt(&led1);
				led_state1=gpio_pin_get_dt(&led1);
				LOG_INF("TURNED LED1 %s",led_state1 ? "ON": "OFF");
			}
		}
		break;
	case UART_RX_DISABLED:
		uart_rx_enable(dev, rx_buf, sizeof rx_buf, RECEIVE_TIMEOUT);
		break;

	default:
		break;
	}
}


int main(void)
{
	int ret = 0;
	
	Error_Handler Status_en;

	if (false==gpio_is_ready_dt(&led0) && false==gpio_is_ready_dt(&led1)) /* Check if the device is ready using node led0 device pointer structure value */
	{ 
		Status_en = status_error;
		LOG_INF("LED'S ARE NOT READY");
	}
	
    ret = gpio_pin_configure_dt(&led0, GPIO_OUTPUT_ACTIVE);/* Configure the pin as output using node led0 device pointer structure value */
	if(ret<0)
	{
		Status_en = status_error;
		LOG_INF("LED0 NOT CONFIGURED");
	}
	
	ret = gpio_pin_configure_dt(&led1, GPIO_OUTPUT_ACTIVE);/* Configure the pin as output using node led0 device pointer structure value */
	if(ret<0)
	{
		Status_en = status_error;
		LOG_INF("LED1 NOT CONFIGURED");
	}
    
	
	if(!device_is_ready(uart))
	{
		LOG_INF("UART IS NOT READY\n");
	}
    
   
	ret = uart_callback_set(uart, uart_cb, NULL);
	if (ret!=0) 
	{
		LOG_INF("UART CALLBACK NOT REGISTERED SUCCESSFULLY");
	}
	

    ret = uart_rx_enable(uart ,rx_buf,sizeof rx_buf,RECEIVE_TIMEOUT);
	if (ret!=0) 
	{
		LOG_INF("UART RX NOT ENABLED SUCCESSFULLY");
	}

	
	ret = uart_tx(uart, tx_buf, sizeof(tx_buf), SYS_FOREVER_US);
	if (ret!=0) 
	{
		LOG_INF("UART DATA NOT TRANSMITTED SUCCESSFULLY");
	}
	
	gpio_pin_set_dt(&led0,false);
	gpio_pin_set_dt(&led1,false);
	
	
	
	while (1) 
	{		
		
	    ret = uart_tx(uart, tx_buf, sizeof(tx_buf), SYS_FOREVER_US);
		if (ret!=0) 
		{
			LOG_INF("UART DATA NOT TRANSMITTED SUCCESSFULLY");
		}
	   k_msleep(SLEEP_TIME_MS); /* kernel service function k_msleep() putting the main function to sleep for 1 second, resulting in the blinking behavior at 1-second intervals.*/  
	
	}
	return Status_en;
}
