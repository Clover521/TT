#include "RCC_Driver.h"



//void SystemClock_Init(void)
//{
///******************************************************************************/
///*            PLL (clocked by HSE) used as System clock source                */
///******************************************************************************/
//  __IO uint32_t StartUpCounter = 0, HSEStatus = 0;
//  
//  
//  RCC->CR |= ((uint32_t)RCC_CR_HSEON);  //使能HSE时钟
// 
//  do
//  {
//    HSEStatus = RCC->CR & RCC_CR_HSERDY;
//    StartUpCounter++;
//  } while((HSEStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));  //等待HSE的时钟稳定
// 
//  if ((RCC->CR & RCC_CR_HSERDY) != RESET)
//  {
//    HSEStatus = (uint32_t)0x01;  //表示HSE启动成功
//  }
//  else
//  {
//    HSEStatus = (uint32_t)0x00;  //表示HSE启动失败
//  }
// 
//  if (HSEStatus == (uint32_t)0x01) 
//  {
//    /* Enable high performance mode, System frequency up to 168 MHz */
//    RCC->APB1ENR |= RCC_APB1ENR_PWREN; //使能电源接口时钟
//    PWR->CR |= PWR_CR_PMODE;  //调压器输出电压级别选择
// 
//    /* HCLK = SYSCLK / 1*/
//    RCC->CFGR |= RCC_CFGR_HPRE_DIV1;  //设置AHBx分频器的值,经过这个分频器分频得到 AHBx=SYSCLK / RCC_CFGR_HPRE_DIV1
//      
//    /* PCLK2 = HCLK / 2*/
//    RCC->CFGR |= RCC_CFGR_PPRE2_DIV2; //设置APB2分频器的值,经过这个分频器分频得到 APB2 = AHBx / RCC_CFGR_PPRE2_DIV2
//    
//    /* PCLK1 = HCLK / 4*/
//    RCC->CFGR |= RCC_CFGR_PPRE1_DIV4; //设置APB1分频器的值,经过这个分频器分频的到 APB1 = AHBx / RCC_CFGR_PPRE1_DIV4
// 
//    /* Configure the main PLL */
//	 //设置主PLL的时钟来源，这里设置为HSE. 设置主PLL分频器的值,也就是PLL_M,PLL_N,PLL_P,PLL_Q. 
//    RCC->PLLCFGR = PLL_M | (PLL_N << 6) | (((PLL_P >> 1) -1) << 16) | (RCC_PLLCFGR_PLLSRC_HSE) | (PLL_Q << 24); 
//                   
// 
//    /* Enable the main PLL */
//    RCC->CR |= RCC_CR_PLLON;  //启动主PLL
// 
//    /* Wait till the main PLL is ready */
//    while((RCC->CR & RCC_CR_PLLRDY) == 0) //等待主PLL时钟就绪
//    {
//    }
//   
//    /* Configure Flash prefetch, Instruction cache, Data cache and wait state */
//    FLASH->ACR = FLASH_ACR_ICEN |FLASH_ACR_DCEN |FLASH_ACR_LATENCY_5WS;
// 
//    /* Select the main PLL as system clock source */
//    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));  //选择PLL作为系统时钟SYSCLK来源
//    RCC->CFGR |= RCC_CFGR_SW_PLL;
// 
//    /* Wait till the main PLL is used as system clock source */
//    while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS ) != RCC_CFGR_SWS_PLL);  //等待PLL成为主时钟来源
// 
//  }
//  else
//  { /* If HSE fails to start-up, the application will have wrong clock
//         configuration. User can add here some code to deal with this error */
//  }
// }

 
 
 
 
 
 
 
void RCC_Config(void)
{
    RCC_DeInit();    //RCC寄存器初始化
    RCC_HSEConfig(RCC_HSE_ON);    //使用外部时钟
    if(RCC_WaitForHSEStartUp() == SUCCESS)     //等待外部时钟启动
    {
        RCC_PLLCmd(DISABLE);    //配置PLL前应先关闭主PLL
        RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);    //选择PLL时钟为系统时钟
        RCC_HCLKConfig(RCC_SYSCLK_Div1);    //HCLK(AHB)时钟为系统时钟1分配
        RCC_PCLK1Config(RCC_HCLK_Div4);    //PCLK(APB1)时钟为HCLK时钟8分频
        RCC_PCLK2Config(RCC_HCLK_Div2);    //PCLK(APB2)时钟为系统时钟2分频
        RCC_PLLConfig(RCC_PLLSource_HSE, 25, 336, 4, 7);    //PLL时钟配置,外部晶振为8MHz,系统时钟168MHz
        RCC_PLLCmd(ENABLE);    //PLL时钟开启
		
        while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);    //等待PLL时钟准备好
		
		  /* Select the main PLL as system clock source */
		RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));  //选择PLL作为系统时钟SYSCLK来源
		RCC->CFGR |= RCC_CFGR_SW_PLL;
 
		/* Wait till the main PLL is used as system clock source */
		while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS ) != RCC_CFGR_SWS_PLL);  //等待PLL成为主时钟来源
    }

}

