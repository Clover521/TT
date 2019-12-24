#include "Usart_Driver.h"




/***********************************************************
** 函数名 : USARTX_Init
** 功  能 : 初始化串口对应的GPIO口，和初始化串口
** 参  数 : 1、选择串口(USART1 - USART5)  2、波特率(38400、 9600、 115200)
** 返回值 : 无
*************************************************************/
void USARTX_Init(USART_TypeDef* USARTx, uint32_t BaudRate)
{
	
	GPIO_InitTypeDef GPIO_InitStruct;
	USART_InitTypeDef USART_InitStruct;
	
	//打开时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	
	//引脚复用使能
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);
	
	//引脚初始化
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	//初始化串口
	USART_InitStruct.USART_BaudRate = BaudRate;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_Mode = USART_Mode_Rx|USART_Mode_Tx;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_Init(USARTx, &USART_InitStruct);
	
	//清空标志位
	USART_ClearFlag(USARTx, USART_FLAG_TC);
	//打开串口接收中断
	USART_ITConfig(USART1 , USART_IT_RXNE,  ENABLE);
	
	//使能串口
	USART_Cmd(USARTx, ENABLE);
}


/***********************************************************
** 函数名 : fputc
** 功  能 : 重定义printf接口，让使用者可用printf打印信息
** 参  数 : 1、传入的数值  2、字符流
** 返回值 : 输入的数据
*************************************************************/
int fputc(int ch, FILE * fp)
{
	
	USART_SendData(USART1, ch);
	while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
	
	return ch;
}


/***********************************************************
** 函数名 : UsartX_Putc
** 功  能 : 从串口发送一个字符的数据
** 参  数 : 1、选择串口(USART1 - USART5)  2、发送的字符
** 返回值 : 无
*************************************************************/
void UsartX_Putc(USART_TypeDef* USARTx, uint8_t ch)
{
	USART_SendData(USARTx, ch);
	while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
}


/***********************************************************
** 函数名 : UsartX_PutStr
** 功  能 : 从串口发送一个字符串的数据
** 参  数 : 1、选择串口(USART1 - USART5)  2、发送的字符串
** 返回值 : 无
*************************************************************/
void UsartX_PutStr(USART_TypeDef* USARTx, uint8_t *str)
{

	while(*str)
	{
		UsartX_Putc(USARTx, *str++);
	}
}




/***********************************************************
** 函数名 : NVIC_USARTX_Init
** 功  能 : 串口中断函数，初始化串口中断
** 参  数 : 无
** 返回值 : 无
*************************************************************/
void NVIC_USARTX_Init(void)
{

	NVIC_InitTypeDef NVIC_InitStruct;
		
	//选择中断的组号
	 NVIC_PriorityGroupConfig( NVIC_PriorityGroup_2);

	 NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
	 NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	 NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority =  1;
	 NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
	
	 NVIC_Init(&NVIC_InitStruct);
 
}












