#include "SysTick_Driver.h"




static uint32_t f_us = 0;
static uint32_t f_ms = 0;


/***********************************************************
** ������ : SysTick_Init
** ��  �� : ��ʼ��SYSTickʱ�ӣ�ѡ��ʱ��Դ,����1us��1ms�����ĸ���
** ��  �� : ϵͳ�Ĺ���Ƶ��
** ����ֵ : ��
*************************************************************/
void SysTick_Init(uint8_t SysClk)
{
	//ѡ��ʱ��Դ
	SysTick_CLKSourceConfig( SysTick_CLKSource_HCLK_Div8);
	
	f_us = SysClk/8;
	f_ms = f_us*1000;
	
}


/***********************************************************
** ������ : delay_us
** ��  �� : ����΢����ʱ����
** ��  �� : ������ʱ΢��Ĵ���
** ����ֵ : ��
*************************************************************/
void delay_us(uint32_t nus)
{
	uint32_t temp;
	
	SysTick->LOAD = nus*f_us;       //����Ԥװ��ֵ�Ĵ���
	SysTick->VAL = 0x00;            //��ռ���ֵ�Ĵ���
	SysTick->CTRL |= 0x01;          //��ʱ��
	
	do{
	
		temp = SysTick->CTRL;       //��ȡԤװ�ؼĴ��� ��ֵ
	}while((temp & 0x01) && !(temp & (1 << 16)));
  
	
	SysTick->VAL = 0x00;            //��ռ���ֵ�Ĵ���
	SysTick->CTRL |= 0x00;          //�ر�ʱ��

}


/***********************************************************
** ������ : delay_ms
** ��  �� : ���ú�����ʱ����
** ��  �� : ������ʱ����Ĵ���
** ����ֵ : ��
*************************************************************/
void delay_ms(uint32_t nms)
{
	uint32_t temp;
	
	SysTick->LOAD = nms*f_ms;       //����Ԥװ��ֵ�Ĵ���
	SysTick->VAL = 0x00;            //��ռ���ֵ�Ĵ���
	SysTick->CTRL |= 0x01;          //��ʱ��
	
	do{
	
		temp = SysTick->CTRL;       //��ȡԤװ�ؼĴ��� ��ֵ
	}while((temp & 0x01) && !(temp & (1 << 16)));

	SysTick->VAL = 0x00;            //��ռ���ֵ�Ĵ���
	SysTick->CTRL |= 0x00;          //�ر�ʱ��
	
}

