#ifndef __USART_DRIVER_H_
#define __USART_DRIVER_H_

#include "stm32f4xx.h"
#include <stdio.h>



void USARTX_Init(USART_TypeDef* USARTx, uint32_t BaudRate);
int fputc(int ch, FILE * fp);
void UsartX_Putc(USART_TypeDef* USARTx, uint8_t ch);
void UsartX_PutStr(USART_TypeDef* USARTx, uint8_t *str);
void NVIC_USARTX_Init(void);



#endif















