#include "RCC_Driver.h"



//void SystemClock_Init(void)
//{
///******************************************************************************/
///*            PLL (clocked by HSE) used as System clock source                */
///******************************************************************************/
//  __IO uint32_t StartUpCounter = 0, HSEStatus = 0;
//  
//  
//  RCC->CR |= ((uint32_t)RCC_CR_HSEON);  //ʹ��HSEʱ��
// 
//  do
//  {
//    HSEStatus = RCC->CR & RCC_CR_HSERDY;
//    StartUpCounter++;
//  } while((HSEStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));  //�ȴ�HSE��ʱ���ȶ�
// 
//  if ((RCC->CR & RCC_CR_HSERDY) != RESET)
//  {
//    HSEStatus = (uint32_t)0x01;  //��ʾHSE�����ɹ�
//  }
//  else
//  {
//    HSEStatus = (uint32_t)0x00;  //��ʾHSE����ʧ��
//  }
// 
//  if (HSEStatus == (uint32_t)0x01) 
//  {
//    /* Enable high performance mode, System frequency up to 168 MHz */
//    RCC->APB1ENR |= RCC_APB1ENR_PWREN; //ʹ�ܵ�Դ�ӿ�ʱ��
//    PWR->CR |= PWR_CR_PMODE;  //��ѹ�������ѹ����ѡ��
// 
//    /* HCLK = SYSCLK / 1*/
//    RCC->CFGR |= RCC_CFGR_HPRE_DIV1;  //����AHBx��Ƶ����ֵ,���������Ƶ����Ƶ�õ� AHBx=SYSCLK / RCC_CFGR_HPRE_DIV1
//      
//    /* PCLK2 = HCLK / 2*/
//    RCC->CFGR |= RCC_CFGR_PPRE2_DIV2; //����APB2��Ƶ����ֵ,���������Ƶ����Ƶ�õ� APB2 = AHBx / RCC_CFGR_PPRE2_DIV2
//    
//    /* PCLK1 = HCLK / 4*/
//    RCC->CFGR |= RCC_CFGR_PPRE1_DIV4; //����APB1��Ƶ����ֵ,���������Ƶ����Ƶ�ĵ� APB1 = AHBx / RCC_CFGR_PPRE1_DIV4
// 
//    /* Configure the main PLL */
//	 //������PLL��ʱ����Դ����������ΪHSE. ������PLL��Ƶ����ֵ,Ҳ����PLL_M,PLL_N,PLL_P,PLL_Q. 
//    RCC->PLLCFGR = PLL_M | (PLL_N << 6) | (((PLL_P >> 1) -1) << 16) | (RCC_PLLCFGR_PLLSRC_HSE) | (PLL_Q << 24); 
//                   
// 
//    /* Enable the main PLL */
//    RCC->CR |= RCC_CR_PLLON;  //������PLL
// 
//    /* Wait till the main PLL is ready */
//    while((RCC->CR & RCC_CR_PLLRDY) == 0) //�ȴ���PLLʱ�Ӿ���
//    {
//    }
//   
//    /* Configure Flash prefetch, Instruction cache, Data cache and wait state */
//    FLASH->ACR = FLASH_ACR_ICEN |FLASH_ACR_DCEN |FLASH_ACR_LATENCY_5WS;
// 
//    /* Select the main PLL as system clock source */
//    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));  //ѡ��PLL��Ϊϵͳʱ��SYSCLK��Դ
//    RCC->CFGR |= RCC_CFGR_SW_PLL;
// 
//    /* Wait till the main PLL is used as system clock source */
//    while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS ) != RCC_CFGR_SWS_PLL);  //�ȴ�PLL��Ϊ��ʱ����Դ
// 
//  }
//  else
//  { /* If HSE fails to start-up, the application will have wrong clock
//         configuration. User can add here some code to deal with this error */
//  }
// }

 
 
 
 
 
 
 
void RCC_Config(void)
{
    RCC_DeInit();    //RCC�Ĵ�����ʼ��
    RCC_HSEConfig(RCC_HSE_ON);    //ʹ���ⲿʱ��
    if(RCC_WaitForHSEStartUp() == SUCCESS)     //�ȴ��ⲿʱ������
    {
        RCC_PLLCmd(DISABLE);    //����PLLǰӦ�ȹر���PLL
        RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);    //ѡ��PLLʱ��Ϊϵͳʱ��
        RCC_HCLKConfig(RCC_SYSCLK_Div1);    //HCLK(AHB)ʱ��Ϊϵͳʱ��1����
        RCC_PCLK1Config(RCC_HCLK_Div4);    //PCLK(APB1)ʱ��ΪHCLKʱ��8��Ƶ
        RCC_PCLK2Config(RCC_HCLK_Div2);    //PCLK(APB2)ʱ��Ϊϵͳʱ��2��Ƶ
        RCC_PLLConfig(RCC_PLLSource_HSE, 25, 336, 4, 7);    //PLLʱ������,�ⲿ����Ϊ8MHz,ϵͳʱ��168MHz
        RCC_PLLCmd(ENABLE);    //PLLʱ�ӿ���
		
        while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);    //�ȴ�PLLʱ��׼����
		
		  /* Select the main PLL as system clock source */
		RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));  //ѡ��PLL��Ϊϵͳʱ��SYSCLK��Դ
		RCC->CFGR |= RCC_CFGR_SW_PLL;
 
		/* Wait till the main PLL is used as system clock source */
		while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS ) != RCC_CFGR_SWS_PLL);  //�ȴ�PLL��Ϊ��ʱ����Դ
    }

}

