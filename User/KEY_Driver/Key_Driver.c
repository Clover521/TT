#include "KEY_Driver.h"



/***********************************************************
** ������ : Key_Init
** ��  �� : ��ʼ��4�����������ð�����ʼ������
** ��  �� : ��
** ����ֵ : ��
*************************************************************/
void Key_Init(void)
{
	
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOE,  ENABLE);
	
	//��ʼ��GPIO����ṹ��
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	//��ʼ������
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	//��ʼ��GPIO����ṹ��
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	//��ʼ������
	GPIO_Init(GPIOE, &GPIO_InitStruct);
}


/***********************************************************
** ������ : Key_Init
** ��  �� : ��ʼ��4�����������ð�����ʼ������
** ��  �� : ��
** ����ֵ : ����������
*************************************************************/
uint8_t Get_KeyValue(void)
{
	//�жϰ���KEY_UP�Ƿ��£����º�̧�𷵻�KEY_UPֵ
	if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == RESET)
	{
		delay_ms(30);
		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == RESET)
		{
			while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == RESET);
			return KEY_UP;
		}
	}
	
	//�жϰ���KEY_0�Ƿ��£����º�̧�𷵻�KEY_0ֵ
	else if(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4) == RESET)
	{
		delay_ms(30);
		if(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4) == RESET)
		{
			while(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4) == RESET);
			return KEY_0;
		}
	}
	
	//�жϰ���KEY_1�Ƿ��£����º�̧�𷵻�KEY_1ֵ
	else if(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3) == RESET)
	{
		delay_ms(30);
		if(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3) == RESET)
		{
			while(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3) == RESET);
			return KEY_1;
		}
	}
	
	//�жϰ���KEY_2�Ƿ��£����º�̧�𷵻�KEY_2ֵ
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
** ������ : Scann_Key
** ��  �� : ��ʼ��4�����������ð�����ʼ������
** ��  �� : ��
** ����ֵ : ����������
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









