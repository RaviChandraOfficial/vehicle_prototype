/* In this file, HeadLight Configurations are Done ---> PC6 */

#include "stm32f4xx.h"

//This Function Configured Timer-3 Channel-1 as PWM Mode
void PWMTim3_Con(void)
{
	RCC -> APB1ENR|=(1<<1);
	TIM3 -> CNT   =0;
	TIM3 -> PSC   =0;
	TIM3 -> ARR   =16000-1;
	TIM3 -> CR1   |=(1<<7);
	TIM3 -> CR1   |=(1<<0);
	TIM3 -> CCER  |=(3<<0);
	TIM3 -> CCMR1 &=~(7<<4);
	TIM3 -> CCMR1 |=(6<<4);
	TIM3 -> EGR   |=(1<<0);
}

//This Function Configured PC6 as Alternate Mode
void GPIOC_PWM_Con(void)
{
	RCC-> AHB1ENR |= (1<<2);
	GPIOC -> MODER &=~(3<<12);
	GPIOC -> MODER |=(2<<12);
	GPIOC -> AFR[0] &=~(15<<24);	//AF7
	GPIOC -> AFR[0] |=(2<<24);		//AF7
}

//This Function Configured PC6 as OUTPUT Mode
void GPIOC_Output_Con(){
	RCC-> AHB1ENR |= (1<<2);
	GPIOC -> MODER &=~(3<<12);
	GPIOC -> MODER |=(1<<12);

	GPIOC->ODR |= (1<<6);
}

//This Function Sets the Duty Cycle for PWM
void dutycycle(unsigned int duty_cycle){

	TIM3->CCR1=(unsigned int)((TIM3->ARR *duty_cycle)/100);

	}


