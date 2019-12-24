#include "Led_Driver.h"
#include "SysTick_Driver.h"


/***********************************************************
** ������ : LED_Init
** ��  �� : ��ʼ��LED�ƣ�����LED��ʼ������
** ��  �� : ��
** ����ֵ : ��
*************************************************************/
void LED_Init(void)
{
	 GPIO_InitTypeDef GPIO_InitStruct;
	//��LED�Ƶ�ʱ��
	 RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	 GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10;
	 GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	 GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	 GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	 GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	
	 //��ʼ��
     GPIO_Init(GPIOF, &GPIO_InitStruct);
	
	 GPIO_SetBits(GPIOF, GPIO_Pin_9|GPIO_Pin_10);
}


/***********************************************************
** ������ : LED_Ctl
** ��  �� : ѡ��ƣ����ҿ��Ը��Ƶ�״̬�����ƵƵĿ���
** ��  �� : 1���Ƶ�ѡ��:RED_LED��YELLOW_LED   2���Ƶ�״̬:LED_ON ��LED_OFF
** ����ֵ : ��
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
				//������涼���ǣ���������ִ��
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



