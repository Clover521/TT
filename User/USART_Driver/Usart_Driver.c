#include "Usart_Driver.h"




/***********************************************************
** ������ : USARTX_Init
** ��  �� : ��ʼ�����ڶ�Ӧ��GPIO�ڣ��ͳ�ʼ������
** ��  �� : 1��ѡ�񴮿�(USART1 - USART5)  2��������(38400�� 9600�� 115200)
** ����ֵ : ��
*************************************************************/
void USARTX_Init(USART_TypeDef* USARTx, uint32_t BaudRate)
{
	
	GPIO_InitTypeDef GPIO_InitStruct;
	USART_InitTypeDef USART_InitStruct;
	
	//��ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	
	//���Ÿ���ʹ��
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);
	
	//���ų�ʼ��
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	//��ʼ������
	USART_InitStruct.USART_BaudRate = BaudRate;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_Mode = USART_Mode_Rx|USART_Mode_Tx;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_Init(USARTx, &USART_InitStruct);
	
	//��ձ�־λ
	USART_ClearFlag(USARTx, USART_FLAG_TC);
	//�򿪴��ڽ����ж�
	USART_ITConfig(USART1 , USART_IT_RXNE,  ENABLE);
	
	//ʹ�ܴ���
	USART_Cmd(USARTx, ENABLE);
}


/***********************************************************
** ������ : fputc
** ��  �� : �ض���printf�ӿڣ���ʹ���߿���printf��ӡ��Ϣ
** ��  �� : 1���������ֵ  2���ַ���
** ����ֵ : ���������
*************************************************************/
int fputc(int ch, FILE * fp)
{
	
	USART_SendData(USART1, ch);
	while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
	
	return ch;
}


/***********************************************************
** ������ : UsartX_Putc
** ��  �� : �Ӵ��ڷ���һ���ַ�������
** ��  �� : 1��ѡ�񴮿�(USART1 - USART5)  2�����͵��ַ�
** ����ֵ : ��
*************************************************************/
void UsartX_Putc(USART_TypeDef* USARTx, uint8_t ch)
{
	USART_SendData(USARTx, ch);
	while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
}


/***********************************************************
** ������ : UsartX_PutStr
** ��  �� : �Ӵ��ڷ���һ���ַ���������
** ��  �� : 1��ѡ�񴮿�(USART1 - USART5)  2�����͵��ַ���
** ����ֵ : ��
*************************************************************/
void UsartX_PutStr(USART_TypeDef* USARTx, uint8_t *str)
{

	while(*str)
	{
		UsartX_Putc(USARTx, *str++);
	}
}




/***********************************************************
** ������ : NVIC_USARTX_Init
** ��  �� : �����жϺ�������ʼ�������ж�
** ��  �� : ��
** ����ֵ : ��
*************************************************************/
void NVIC_USARTX_Init(void)
{

	NVIC_InitTypeDef NVIC_InitStruct;
		
	//ѡ���жϵ����
	 NVIC_PriorityGroupConfig( NVIC_PriorityGroup_2);

	 NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
	 NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	 NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority =  1;
	 NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
	
	 NVIC_Init(&NVIC_InitStruct);
 
}












