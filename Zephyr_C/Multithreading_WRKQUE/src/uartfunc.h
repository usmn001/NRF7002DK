#ifndef UART_FUNC_H
#define UART_FUNC_H

#define RECEIVE_TIMEOUT 10
void uart_init();
void uart_send(uint8_t *tx_buf,size_t len);
#endif