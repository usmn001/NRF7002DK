
#include <stdio.h> 
#include <stdbool.h>
#include <stdint.h>
#include <zephyr/kernel.h> 
#include <zephyr/drivers/gpio.h> 
#include <zephyr/logging/log.h>

typedef enum 
{
status_ok = 0,
status_error = 1,
led_ready = 2,
led_busy = 3
}ret_en;


class Led
{
private : 
    gpio_dt_spec led_light;
    bool led_state;
    uint16_t delay;

public : 
    Led(bool led_state=false);                        // Default Constructor
    //led(const gpio_dt_spec &led);                   // Copy Constructor
    ~Led(){};
    ret_en init();
    void on();
    void off();
    void set_delay(uint16_t delay_p);

};