
#include <stdio.h> 
#include <stdbool.h>
#include <stdint.h>
#include <zephyr/kernel.h> 
#include <zephyr/drivers/gpio.h> 


typedef enum 
{
status_ok = 0,
status_error = 1,
led_ready = 2,
led_busy = 3
}ret_en;


class led
{
private : 
    gpio_dt_spec led_light;
    bool led_state;

public : 
    led(bool led_state=false);                        // Default Constructor
    //led(const gpio_dt_spec &led);                   // Copy Constructor
    ~led(){};
    ret_en led_init();
    void led_on();
    void led_off();
};