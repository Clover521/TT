#ifndef __SYSTICK_DRIVER_H_
#define __SYSTICK_DRIVER_H_

#include "stm32f4xx.h"


void SysTick_Init(uint8_t SysClk);
void delay_us(uint32_t nus);
void delay_ms(uint32_t nms);


#endif


