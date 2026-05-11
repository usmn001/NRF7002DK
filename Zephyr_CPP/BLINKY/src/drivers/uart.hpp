#pragma once
#include <zephyr/kernel.h>        /* For using kernel services as we are using k_msleep() function*/
#include <zephyr/drivers/uart.h>  /* Contains UART Driver Structs*/
#include <zephyr/logging/log.h>



typedef enum 
{
OKAY = 0,
NOT_OKAY = 1
}ret_e;


class Uart
{
private :
const struct device *uart_pst;


public : 
Uart(); // Default constructor
Uart(const Uart &ref);                   // Copy Constructor
ret_e init();
ret_e send(uint8_t *tx_buf_p,size_t len_p);
};




