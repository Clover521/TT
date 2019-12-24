#ifndef __KEY_DRIVER_H_
#define __KEY_DRIVER_H_


#include "stm32f4xx.h"
#include "SysTick_Driver.h"
#include "Led_Driver.h"

typedef enum{

	KEY_0 = 1,
	KEY_1,
	KEY_2,
	KEY_UP,
	
	NO_KEY,
}KEY_TYpe;

void Key_Init(void);
uint8_t Get_KeyValue(void);
void Scann_Key(uint8_t Key_Type);


#endif


