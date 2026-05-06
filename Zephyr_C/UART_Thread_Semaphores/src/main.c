
#include <stdio.h> 
#include <zephyr/kernel.h>        /* For using kernel services as we are using k_msleep() function*/
#include <zephyr/drivers/gpio.h>  /* Contains structure gpio_dt_spec, the macros GPIO_DT_SPEC_GET(), and the functions, gpio_is_ready_dt(), gpio_pin_configure_dt() and gpio_pin_toggle_dt().*/
#include <zephyr/drivers/uart.h>  /* Contains UART Driver Structs*/
#include <zephyr/logging/log.h>

#ifdef CONFIG_UART_FUNC
#include "uartfunc.h"
#endif

#ifdef CONFIG_LED_FUNC
#include "led.h"
#endif

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS   5000

/* The devicetree node identifier for the "led0" & sw0 aliases defined in nrf5340_cpuapp_common.dtsi. */
#define LED0_NODE DT_ALIAS(led0) /* Line uses the devicetree macro DT_ALIAS() to get the node identifier symbol from alias led0, which will represent node led0 */
#define LED1_NODE DT_ALIAS(led1)


//#define THREAD0_PRIORITY 7
#define THREAD1_PRIORITY 5   // When using k_busy_wait use same priority of threads, lower number indicates higher priority thread.
#define THREAD2_PRIORITY 5
#define STACKSIZE 1024

LOG_MODULE_REGISTER(MAIN_C,LOG_LEVEL_INF);

K_SEM_DEFINE(sem, 0, 10);    // Defining a Semaphore

/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */

uint8_t tx_buf[32] = {0};

void sem_take()
{
k_sem_take(&sem,K_NO_WAIT);
uint8_t cnt = k_sem_count_get(&sem);
printk("Semaphore Taken, Count = %i\n",cnt);
}

void sem_give()
{
k_sem_give(&sem);	
uint8_t cnt = k_sem_count_get(&sem);
printk("Semaphore Given, Count = %i\n",cnt);
}


void thread_func1(void)
{
	while (1) 
	{
		uint64_t time_stamp;
        int64_t delta_time;
        time_stamp = k_uptime_get();
		led0_on();
		sem_take();
		uint8_t msg[]="THREAD1 : HAPPY NEW YEAR 2026\n";
		memset(tx_buf,0,sizeof(msg));
		strcpy(tx_buf,msg);
		uart_send(tx_buf,strlen(msg));		
		sem_give();
		k_busy_wait(1000000);      // Creating a delay of 1 second, , by executing a do nothing loop  
		led0_off();
		k_busy_wait(1000000);      // Creating a delay of 1 second, by executing a do nothing loop  
		delta_time = k_uptime_delta(&time_stamp);	

		//k_msleep(6000);          // Use this api when we have threads of different priorities, change the thread state from “Running” to “Non-runnable” until the timeout has passed, and then change it to “Runnable”.
		//k_yield();     
		/*change the thread state from “Running” to “Runnable”, which means that at the next rescheduling point, 
		  the thread that just yielded is still a candidate in the scheduler’s algorithm for making a thread active (“Running”), 
		  not efficient takes cpu time when invoking scheduling algorithm */		
	}
}



void thread_func2(void)
{
	while (1) {
		uint64_t time_stamp;
        int64_t delta_time;
        time_stamp = k_uptime_get();
		led1_on();
		char msg[]="THREAD2 : HAPPY NEW YEAR 2026\n";
		sem_take();
		strcpy(tx_buf,msg);
		uart_send(tx_buf,strlen(msg));
		sem_give();

		k_busy_wait(1000000);  // Creating a delay of 1 second, by executing a do nothing loop
		led1_off();
		k_busy_wait(1000000);  // Creating a delay of 1 second, by executing a do nothing loop
		delta_time = k_uptime_delta(&time_stamp);

		//k_msleep(6000);      // Use this api when we have threads of different priorities, change the thread state from “Running” to “Non-runnable” until the timeout has passed, and then change it to “Runnable”.
		//k_yield(); 
		/*change the thread state from “Running” to “Runnable”, which means that at the next rescheduling point, 
		  the thread that just yielded is still a candidate in the scheduler’s algorithm for making a thread active (“Running”), 
		  not efficient takes cpu time when invoking scheduling algorithm */
	}
}


K_THREAD_DEFINE(thread1_id,STACKSIZE,thread_func1,NULL,NULL,NULL,THREAD1_PRIORITY,0,0);
K_THREAD_DEFINE(thread2_id,STACKSIZE,thread_func2,NULL,NULL,NULL,THREAD2_PRIORITY,0,0);	


int main(void)
{
    uart_init();
	led_init();

    led0_off();
	led1_off();

	return 0;
}
