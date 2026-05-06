
#include <zephyr/kernel.h>        /* For using kernel services as we are using k_msleep() function*/
#include <zephyr/drivers/gpio.h>  /* Contains structure gpio_dt_spec, the macros GPIO_DT_SPEC_GET(), and the functions, gpio_is_ready_dt(), gpio_pin_configure_dt() and gpio_pin_toggle_dt().*/
#include <zephyr/drivers/uart.h>  /* Contains UART Driver Structs*/
#include <zephyr/logging/log.h>

#include "uartfunc.h"

LOG_MODULE_REGISTER(UART_C,LOG_LEVEL_INF);

/* The devicetree node identifier for the "led0" & sw0 aliases defined in nrf5340_cpuapp_common.dtsi. */
#define LED0_NODE DT_ALIAS(led0) /* Line uses the devicetree macro DT_ALIAS() to get the node identifier symbol from alias led0, which will represent node led0 */
#define LED1_NODE DT_ALIAS(led1)



static bool led_state0 = true;
static bool led_state1 = true;

typedef enum 
{
OKAY = 0,
NOT_OKAY = 1
}ret_e;

static const struct gpio_dt_spec led0 = GPIO_DT_SPEC_GET(LED0_NODE, gpios); /* Structure containing pointer to device node leds  */
static const struct gpio_dt_spec led1 = GPIO_DT_SPEC_GET(LED1_NODE, gpios); /* Structure containing pointer to device node leds  */
const struct device *uart = DEVICE_DT_GET(DT_NODELABEL(uart0));   /* Getting UART Device Pointer */



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

void uart_init()
{
    if(!device_is_ready(uart))
	{
		LOG_INF("UART IS NOT READY\n");
	}
   
}

void uart_rx_init()
{
    ret_e ret;
	ret = uart_callback_set(uart, uart_cb, NULL);
	
	if (ret==OKAY) 
	{
		ret = uart_rx_enable(uart ,rx_buf,sizeof rx_buf,RECEIVE_TIMEOUT);
        if (ret!=NOT_OKAY) 
		{
			LOG_INF("UART RX NOT ENABLED SUCCESSFULLY");
		} 
	}
}



void uart_send(uint8_t *tx_buf,size_t len)
{
    ret_e ret;
    ret = uart_tx(uart, tx_buf, len, SYS_FOREVER_US);
	if (ret!=OKAY) 
	{
		LOG_INF("UART DATA NOT TRANSMITTED SUCCESSFULLY");
	}
}






