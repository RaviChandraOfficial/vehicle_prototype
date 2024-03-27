/* In this file, Timer4 event Configuration are Done */

#include<stm32f4xx.h>

 void Event_Tim4USART(void)
 {
	 RCC->APB1ENR|=(1<<2);
	 TIM4->CR1 |=(1<<0);
	 TIM4->CNT=0;
	 TIM4->PSC=16000-1;
	 TIM4->ARR=500-1;
	 TIM4->DIER|=(1<<0);			//Enabling DIER

	 NVIC_EnableIRQ(TIM4_IRQn);		//Enabling Timer4 Interrupt
}

