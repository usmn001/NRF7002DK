
#include <stdio.h> 
#include <iostream>
#include <zephyr/kernel.h>        /* For using kernel services as we are using k_msleep() function*/
#include <zephyr/drivers/gpio.h>  /* Contains structure gpio_dt_spec, the macros GPIO_DT_SPEC_GET(), and the functions, gpio_is_ready_dt(), gpio_pin_configure_dt() and gpio_pin_toggle_dt().*/
#include <zephyr/drivers/uart.h>  /* Contains UART Driver Structs*/
#include <zephyr/logging/log.h>
#include <zephyr/timing/timing.h>
#include <string.h>

using std::cout;
#include "Sensor.hpp"


#ifdef CONFIG_UART_FUNC
#include "uartfunc.hpp"
#endif

#ifdef CONFIG_LED_FUNC
#include "led.hpp"
#endif



/* The devicetree node identifier for the "led0" & sw0 aliases defined in nrf5340_cpuapp_common.dtsi. */
#define LED0_NODE DT_ALIAS(led0) /* Line uses the devicetree macro DT_ALIAS() to get the node identifier symbol from alias led0, which will represent node led0 */
#define LED1_NODE DT_ALIAS(led1)


//#define THREAD0_PRIORITY 7
#define PROD_THRD_PRIO 6   // When using k_busy_wait use same priority of threads, lower number indicates higher priority thread.
#define CONS_THRD_PRIO 7
#define STACKSIZE 1024

/* 2200 msec = 2.2 sec */
#define PRODUCER_SLEEP_TIME_MS 20000


LOG_MODULE_REGISTER(MAIN_C,LOG_LEVEL_INF);

K_SEM_DEFINE(sem, 0, 10);    // Defining a Semaphore

/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */

typedef struct {
    uint32_t x_reading = 0;
    uint32_t y_reading = 0;
    uint32_t z_reading = 0;
} SensorReading;


K_MSGQ_DEFINE(device_message_queue, sizeof(SensorReading), 16, 4);

char tx_buf[32] = {0};

void sem_take()
{
k_sem_take(&sem,K_NO_WAIT);
uint8_t cnt = k_sem_count_get(&sem);
LOG_INF("Semaphore Taken, Count = %i\n",cnt);
}

void sem_give()
{
k_sem_give(&sem);	
uint8_t cnt = k_sem_count_get(&sem);
LOG_INF("Semaphore Given, Count = %i\n",cnt);
}



void prod_func(void)
{
	while (1) 
	{
		timing_t start_time, end_time;
    	uint64_t total_cycles;
    	uint64_t total_ns;

    	timing_init();
    	timing_start();
		
		start_time = timing_counter_get();
		
		sem_take();
		static SensorReading acc_val = {.x_reading=10,.y_reading=20,.z_reading=30};		
		int ret = k_msgq_put(&device_message_queue,&acc_val,K_FOREVER);
        if (ret)
		{
            LOG_ERR("Return value from k_msgq_put = %d",ret);
        }
        acc_val.x_reading++;
		acc_val.y_reading++;	
		acc_val.z_reading++;
		sem_give();
		end_time = timing_counter_get();
		total_cycles = timing_cycles_get(&start_time, &end_time);
		total_ns = timing_cycles_to_ns(total_cycles);
		k_msleep(PRODUCER_SLEEP_TIME_MS);
		LOG_INF("Producer execution time = %lld ms",total_ns);
		//k_busy_wait(1000000);      // Creating a delay of 1 second, , by executing a do nothing loop  
		
		

		//k_msleep(6000);          // Use this api when we have threads of different priorities, change the thread state from “Running” to “Non-runnable” until the timeout has passed, and then change it to “Runnable”.
		//k_yield();     
		/*change the thread state from “Running” to “Runnable”, which means that at the next rescheduling point, 
		  the thread that just yielded is still a candidate in the scheduler’s algorithm for making a thread active (“Running”), 
		  not efficient takes cpu time when invoking scheduling algorithm */		
	}
}



void consum_func(void)
{
	while (1) 
	{
		int64_t time_stamp;
        int64_t delta_time;
        time_stamp = k_uptime_get();
		sem_take();
		SensorReading temp;
		int ret = k_msgq_get(&device_message_queue,&temp,K_FOREVER);
        if (ret)
		{
            LOG_ERR("Return value from k_msgq_get = %d",ret);
        }
		sem_give();
		delta_time = k_uptime_delta(&time_stamp);
		LOG_INF("Consumer execution time = %lld ms",delta_time);
		LOG_INF("X = %d , Y = %d , Z = %d",temp.x_reading,temp.y_reading,temp.z_reading);

		//k_msleep(6000);      // Use this api when we have threads of different priorities, change the thread state from “Running” to “Non-runnable” until the timeout has passed, and then change it to “Runnable”.
		//k_yield(); 
		/*change the thread state from “Running” to “Runnable”, which means that at the next rescheduling point, 
		  the thread that just yielded is still a candidate in the scheduler’s algorithm for making a thread active (“Running”), 
		  not efficient takes cpu time when invoking scheduling algorithm */
	}
}

static void timer0_handler(struct k_timer *dummy)
{

	/*Interrupt Context - Sysetm Timer ISR */

		gpio_pin_toggle_dt(&led0);
		k_busy_wait(500000);	
		gpio_pin_toggle_dt(&led1);
	    k_busy_wait(500000);
	

	
}

K_THREAD_DEFINE(prod_thread,STACKSIZE,prod_func,NULL,NULL,NULL,PROD_THRD_PRIO,0,0);
K_THREAD_DEFINE(consum_thread,STACKSIZE,consum_func,NULL,NULL,NULL,CONS_THRD_PRIO,0,0);	
K_TIMER_DEFINE(timer0, timer0_handler, NULL);


int main(void)
{
    uart_init();
	led_init();

    led0_off();
	led1_off();
	/* start periodic timer that expires once every 0.5 second  */
    k_timer_start(&timer0, K_MSEC(500), K_MSEC(500));


	return 0;
}
