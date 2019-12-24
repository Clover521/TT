#include "Tim_Driver.h"



/***********************************************************
** ������ : TIM2_Init
** ��  �� : 1�붨ʱһ��
** ��  �� : ��
** ����ֵ : ��
*************************************************************/
void TIM2_Init(void)
{
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);     //�򿪶�ʱ���ж�
	
	TIM_TimeBaseInitStruct.TIM_Prescaler  = 16799;          //10kHZ
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_Period = 9999;
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	
	TIM_TimeBaseInit( TIM2, &TIM_TimeBaseInitStruct);
	
	//��ʱ�����ж�
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	//ʹ�ܶ�ʱ��
	TIM_Cmd(TIM2, ENABLE);

}
	
	

/***********************************************************
** ������ : NVIC_TIMx_Init
** ��  �� : ��ʱ���жϺ�������ʼ����ʱ���ж�
** ��  �� : ��
** ����ֵ : ��
*************************************************************/
void NVIC_TIMx_Init(void)
{

	NVIC_InitTypeDef NVIC_InitStruct;
		
	//ѡ���жϵ����
	 NVIC_PriorityGroupConfig( NVIC_PriorityGroup_2);

	 NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
	 NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	 NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority =  1;
	 NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	
	 NVIC_Init(&NVIC_InitStruct);
 
}
	











