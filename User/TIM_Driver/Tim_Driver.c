#include "Tim_Driver.h"



/***********************************************************
** 函数名 : TIM2_Init
** 功  能 : 1秒定时一次
** 参  数 : 无
** 返回值 : 无
*************************************************************/
void TIM2_Init(void)
{
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);     //打开定时器中断
	
	TIM_TimeBaseInitStruct.TIM_Prescaler  = 16799;          //10kHZ
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_Period = 9999;
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	
	TIM_TimeBaseInit( TIM2, &TIM_TimeBaseInitStruct);
	
	//定时器的中断
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	//使能定时器
	TIM_Cmd(TIM2, ENABLE);

}
	
	

/***********************************************************
** 函数名 : NVIC_TIMx_Init
** 功  能 : 定时器中断函数，初始化定时器中断
** 参  数 : 无
** 返回值 : 无
*************************************************************/
void NVIC_TIMx_Init(void)
{

	NVIC_InitTypeDef NVIC_InitStruct;
		
	//选择中断的组号
	 NVIC_PriorityGroupConfig( NVIC_PriorityGroup_2);

	 NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
	 NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	 NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority =  1;
	 NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	
	 NVIC_Init(&NVIC_InitStruct);
 
}
	











