
#include <stdio.h> 
#include <zephyr/kernel.h>        /* For using kernel services as we are using k_msleep() function*/
#include <zephyr/drivers/gpio.h>  /* Contains structure gpio_dt_spec, the macros GPIO_DT_SPEC_GET(), and the functions, gpio_is_ready_dt(), gpio_pin_configure_dt() and gpio_pin_toggle_dt().*/
#include <string>

#include "drivers/led.hpp"
#include "drivers/uart.hpp"
#include "drivers/Temp_Sens.hpp"
#include "drivers/Pres_Sens.hpp"
/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS   1000


/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */

int main(void)
{
    float temp_buf{0.0f};
	float pres_buf{0.0f};
	Led led1(0);
	Uart uart1;
	led1.init();
	uart1.init();
	led1.set_delay(1000);
   

	auto& s1 = BME680::Temp_Sens::instance(); 
    auto &s2 = BME680::Pres_Sens::instance();
	while (1) 
	{  
		s1.CONFIG_MODE();
		s1.I2C_READ_SENS(&temp_buf);
		s2.I2C_READ_SENS(&pres_buf);
		printk("Temperature %.2f Celsius, Pressure : %.2f Pa \n", static_cast<double>(temp_buf),static_cast<double>(pres_buf));
		k_msleep(SLEEP_TIME_MS);
	}

	return 0;
}
