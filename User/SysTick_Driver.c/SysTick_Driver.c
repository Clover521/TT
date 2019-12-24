#include "SysTick_Driver.h"




static uint32_t f_us = 0;
static uint32_t f_ms = 0;


/***********************************************************
** 函数名 : SysTick_Init
** 功  能 : 初始化SYSTick时钟，选择时钟源,配置1us、1ms计数的个数
** 参  数 : 系统的工作频率
** 返回值 : 无
*************************************************************/
void SysTick_Init(uint8_t SysClk)
{
	//选择时钟源
	SysTick_CLKSourceConfig( SysTick_CLKSource_HCLK_Div8);
	
	f_us = SysClk/8;
	f_ms = f_us*1000;
	
}


/***********************************************************
** 函数名 : delay_us
** 功  能 : 配置微秒延时函数
** 参  数 : 传入延时微妙的次数
** 返回值 : 无
*************************************************************/
void delay_us(uint32_t nus)
{
	uint32_t temp;
	
	SysTick->LOAD = nus*f_us;       //填入预装载值寄存器
	SysTick->VAL = 0x00;            //清空计数值寄存器
	SysTick->CTRL |= 0x01;          //打开时钟
	
	do{
	
		temp = SysTick->CTRL;       //获取预装载寄存器 的值
	}while((temp & 0x01) && !(temp & (1 << 16)));
  
	
	SysTick->VAL = 0x00;            //清空计数值寄存器
	SysTick->CTRL |= 0x00;          //关闭时钟

}


/***********************************************************
** 函数名 : delay_ms
** 功  能 : 配置毫秒延时函数
** 参  数 : 传入延时毫秒的次数
** 返回值 : 无
*************************************************************/
void delay_ms(uint32_t nms)
{
	uint32_t temp;
	
	SysTick->LOAD = nms*f_ms;       //填入预装载值寄存器
	SysTick->VAL = 0x00;            //清空计数值寄存器
	SysTick->CTRL |= 0x01;          //打开时钟
	
	do{
	
		temp = SysTick->CTRL;       //获取预装载寄存器 的值
	}while((temp & 0x01) && !(temp & (1 << 16)));

	SysTick->VAL = 0x00;            //清空计数值寄存器
	SysTick->CTRL |= 0x00;          //关闭时钟
	
}

