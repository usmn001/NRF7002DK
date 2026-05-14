
#include "uart.hpp"

LOG_MODULE_REGISTER(Uart,LOG_LEVEL_INF);

Uart::Uart():uart_pst(DEVICE_DT_GET(DT_NODELABEL(uart0)))
{
    LOG_INF("DEFAULT CONSTRUCTOR IS CALLED \n");
}

ret_e Uart::init()
{
    ret_e ret = OKAY;
	if(!device_is_ready(uart_pst))
	{
		LOG_INF("UART IS NOT READY\n");
	}
   return ret;
}


ret_e Uart::send(uint8_t *tx_buf_p,size_t len_p)
{
    ret_e ret = OKAY;
    ret = (ret_e)uart_tx(uart_pst, tx_buf_p, len_p, SYS_FOREVER_US);
	if (ret!=OKAY) 
	{
		LOG_INF("UART DATA NOT TRANSMITTED SUCCESSFULLY");
		ret = NOT_OKAY;
	}
	return ret;
}







