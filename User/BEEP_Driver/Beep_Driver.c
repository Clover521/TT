
#include "Beep_Driver.h"


/***********************************************************
** 函数名 : Beep_Init
** 功  能 : 初始化蜂鸣器的配置
** 参  数 : 无
** 返回值 : 无
*************************************************************/
void Beep_Init(void)
{

	GPIO_InitTypeDef GPIO_InitStruct;
	//打开LED灯的时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_DOWN;
	
	//初始化
    GPIO_Init(GPIOF, &GPIO_InitStruct);
}


/***********************************************************
** 函数名 : LED_Ctl
** 功  能 : 选择灯，并且可以给灯的状态来控制灯的开关
** 参  数 : 1、灯的选择:RED_LED、YELLOW_LED   2、灯的状态:LED_ON 、LED_OFF
** 返回值 : 无
*************************************************************/
void BEEP_Ctl(uint8_t BEEP_State)
{
	if(BEEP_State == BEEP_ON)
	{
		GPIO_SetBits(GPIOF, GPIO_Pin_8);
	}else{
		GPIO_ResetBits(GPIOF, GPIO_Pin_8);
	}

}













