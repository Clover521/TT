#ifndef __BEEP_DRIVER_H_
#define __BEEP_DRIVER_H_

#include "stm32f4xx.h"

#define BEEP_ON 0
#define BEEP_OFF 1


void Beep_Init(void);
void BEEP_Ctl(uint8_t BEEP_State);

#endif















