#include "Led_Driver.h"
#include "stm32f4xx.h"
#include "RCC_Driver.h"
#include "Beep_Driver.h"
#include "SysTick_Driver.h"
#include "Key_Driver.h"
#include "Usart_Driver.h"
#include "Tim_Driver.h"


void delay_xs(uint32_t ns)
{
	uint32_t i,j;
	
	for(i = 0; i < 0xFFF;i++)
		for(j = 0;j < ns;j++);
}

/***********************************************************
** 函数名 : Borad_Init
** 功  能 : 板子的外设初始化函数
** 参  数 : 无
** 返回值 : 无
*************************************************************/
void Borad_Init(void)
{
	RCC_Config();
	LED_Init();
	Beep_Init();
	SysTick_Init(168);
	Key_Init();
	NVIC_USARTX_Init();
	USARTX_Init(USART1, 115200);
	NVIC_TIMx_Init();
	TIM2_Init();



}



int main(void)
{
	Borad_Init();           //板子硬件初始化
	
	while(1)
	{
		
		printf("h");
		UsartX_PutStr( USART1, "world\n");
		delay_ms(1000);

	}
		
}












	
