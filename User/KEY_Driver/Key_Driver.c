#include "KEY_Driver.h"



/***********************************************************
** 函数名 : Key_Init
** 功  能 : 初始化4个按键，配置按键初始化变量
** 参  数 : 无
** 返回值 : 无
*************************************************************/
void Key_Init(void)
{
	
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOE,  ENABLE);
	
	//初始化GPIO输入结构体
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	//初始化按键
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	//初始化GPIO输入结构体
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	//初始化按键
	GPIO_Init(GPIOE, &GPIO_InitStruct);
}


/***********************************************************
** 函数名 : Key_Init
** 功  能 : 初始化4个按键，配置按键初始化变量
** 参  数 : 无
** 返回值 : 按键的类型
*************************************************************/
uint8_t Get_KeyValue(void)
{
	//判断按键KEY_UP是否按下，按下后抬起返回KEY_UP值
	if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == RESET)
	{
		delay_ms(30);
		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == RESET)
		{
			while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == RESET);
			return KEY_UP;
		}
	}
	
	//判断按键KEY_0是否按下，按下后抬起返回KEY_0值
	else if(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4) == RESET)
	{
		delay_ms(30);
		if(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4) == RESET)
		{
			while(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4) == RESET);
			return KEY_0;
		}
	}
	
	//判断按键KEY_1是否按下，按下后抬起返回KEY_1值
	else if(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3) == RESET)
	{
		delay_ms(30);
		if(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3) == RESET)
		{
			while(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3) == RESET);
			return KEY_1;
		}
	}
	
	//判断按键KEY_2是否按下，按下后抬起返回KEY_2值
	else if(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_2) == RESET)
	{
		delay_ms(30);
		if(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_2) == RESET)
		{
			while(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_2) == RESET);
			return KEY_2;
		}
	}else
	{
		return NO_KEY;
	}
}


/***********************************************************
** 函数名 : Scann_Key
** 功  能 : 初始化4个按键，配置按键初始化变量
** 参  数 : 无
** 返回值 : 按键的类型
*************************************************************/
void Scann_Key(uint8_t Key_Type)
{
	switch(Key_Type)
	{
		case KEY_0:
				
			LED_Ctl(RED_LED, LED_ON);
		break;
		
		case KEY_1:

			LED_Ctl(RED_LED, LED_OFF);
		break;
		
		case KEY_2:
			LED_Ctl(GREEN_LED, LED_ON);
		break;
		
		case KEY_UP:
			
			LED_Ctl(GREEN_LED, LED_OFF);
		break;
		
		default:
			
		break;
	}
}









