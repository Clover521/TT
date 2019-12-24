#ifndef __LED_DRIVER_H_
#define __LED_DRIVER_H_

#include "stm32f4xx.h"


#define LED_ON 0
#define LED_OFF 1

typedef enum{
	
	RED_LED = 1,
	GREEN_LED,
}LED_TYPE;


void LED_Init(void);
void LED_Ctl(uint8_t LED_Type,uint8_t LED_State);
void LED_TEST(void);

#endif


