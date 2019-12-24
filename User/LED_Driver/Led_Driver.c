#include "Led_Driver.h"
#include "SysTick_Driver.h"


/***********************************************************
** 函数名 : LED_Init
** 功  能 : 初始化LED灯，配置LED初始化变量
** 参  数 : 无
** 返回值 : 无
*************************************************************/
void LED_Init(void)
{
	 GPIO_InitTypeDef GPIO_InitStruct;
	//打开LED灯的时钟
	 RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	 GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10;
	 GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	 GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	 GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	 GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	
	 //初始化
     GPIO_Init(GPIOF, &GPIO_InitStruct);
	
	 GPIO_SetBits(GPIOF, GPIO_Pin_9|GPIO_Pin_10);
}


/***********************************************************
** 函数名 : LED_Ctl
** 功  能 : 选择灯，并且可以给灯的状态来控制灯的开关
** 参  数 : 1、灯的选择:RED_LED、YELLOW_LED   2、灯的状态:LED_ON 、LED_OFF
** 返回值 : 无
*************************************************************/
void LED_Ctl(uint8_t LED_Type,uint8_t LED_State)
{
 
	switch(LED_Type)
	{
		case RED_LED:
			
			if(LED_State == LED_ON)
			{
				GPIO_ResetBits(GPIOF, GPIO_Pin_9);
			}else{
				GPIO_SetBits(GPIOF, GPIO_Pin_9);
			}
		break;
		
		case GREEN_LED:
			
			if(LED_State == LED_ON)
			{
				GPIO_ResetBits(GPIOF, GPIO_Pin_10);
			}else{
				GPIO_SetBits(GPIOF, GPIO_Pin_10);
			}
		break;

		default :
				//如果上面都不是，就来这里执行
		break;
	}

}


void LED_TEST(void)
{
	
	LED_Ctl(RED_LED, LED_ON);
	delay_ms(1000);
	LED_Ctl(GREEN_LED, LED_ON);
	delay_ms(1000);
	LED_Ctl(RED_LED, LED_OFF);
	delay_ms(1000);
	LED_Ctl(RED_LED, LED_OFF);
	delay_ms(1000);
}



