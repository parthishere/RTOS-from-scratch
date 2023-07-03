#ifndef __UART_H__
#define __UART_H__

#define stm32f070xb

#include "stm32f070xb.h"

void uart2_init(void);
void uart2_send(int8_t data);;
void uart2_recive(void);

#endif
