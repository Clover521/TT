
#include "Beep_Driver.h"


/***********************************************************
** ������ : Beep_Init
** ��  �� : ��ʼ��������������
** ��  �� : ��
** ����ֵ : ��
*************************************************************/
void Beep_Init(void)
{

	GPIO_InitTypeDef GPIO_InitStruct;
	//��LED�Ƶ�ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_DOWN;
	
	//��ʼ��
    GPIO_Init(GPIOF, &GPIO_InitStruct);
}


/***********************************************************
** ������ : LED_Ctl
** ��  �� : ѡ��ƣ����ҿ��Ը��Ƶ�״̬�����ƵƵĿ���
** ��  �� : 1���Ƶ�ѡ��:RED_LED��YELLOW_LED   2���Ƶ�״̬:LED_ON ��LED_OFF
** ����ֵ : ��
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













