/* In this file, The all Ports used in Program are configured */

#include <stm32f4xx.h>

//Buzzer Configuration ---> Setting PC9 as OUTPUT MODE
void Buzz_Con()
{
	RCC->AHB1ENR |= (1<<2);
	GPIOC->MODER &= ~(3<<18);
	GPIOC->MODER |= (1<<18);

}

//LEDs Configuration ---> Setting PB13,PB14,PB15 as OUTPUT MODE
void LED_Con()
{
	RCC->AHB1ENR |= (15<<0); 					//Clock Enabled for PORT A,B,C,D

	GPIOB->MODER |= (21<<26);

	GPIOB->ODR |= (7<<13);  					//Turing OFF PB13,PB14,PB15
}

//Ignition Switch Configuration ---> Setting PB3 as INPUT MODE
void Ignition_ButtonCon()
{
	RCC->AHB1ENR |= (1<<1);
	GPIOB->MODER &= ~(3<<6);
}

//Switches Configuration ---> Setting PB7,PB4,PA15 as INPUT MODE
void Button_Con()
{

	GPIOB->MODER &= ~((3<<8)|(3<<14));
	GPIOA->MODER &= ~(3<<30);
}

//Configuration of PB3 as EXTI3
void EXTI3_Con()
{
	RCC->APB2ENR |= (1<<14); 					//Enabling clock to SYSCFG

	__disable_irq() ;							//Disabling the Global Interrupts

	SYSCFG->EXTICR[0] |= (1<<12);				//Configuring PB3 as EXTI3
	EXTI->IMR |= (1<<3);						//Un-Masking the EXTI3
	EXTI->FTSR |= (1<<3);						//Making EXTI3 as Falling Edge
	NVIC_EnableIRQ(EXTI3_IRQn);					//Enabling the EXTI3 using NVIC
	__enable_irq() ;							//Enabling the Global Interrupts
}

//Configuration of PB4,PB7,PA15 as EXTI4,EXTI7,EXTI15
void EXTI7415_Con()
{
	RCC->APB2ENR |= (1<<14); 					//Enabling clock to SYSCFG

	__disable_irq() ;							//Disabling the Global Interrupts

	SYSCFG->EXTICR[1] |= (1<<12); 				//Configuring PB4 as EXTI4
	SYSCFG->EXTICR[1] |= (1<<0); 				//Configuring PB7 as EXTI7
	SYSCFG->EXTICR[3] &= ~(15<<12); 			//Configuring PA15 as EXTI15

	EXTI->IMR |= (1<<4) | (1<<7) | (1<<15);		//Un-Masking EXTI4,EXTI7,EXTI15 as Falling Edge
	EXTI->FTSR |= (1<<4) | (1<<7) | (1<<15);	//Making EXTI4,EXTI7,EXTI15 as Falling Edge

	NVIC_EnableIRQ(EXTI9_5_IRQn);				//Enabling the EXTI7 using NVIC
	NVIC_EnableIRQ(EXTI4_IRQn);					//Enabling the EXTI4 using NVIC
	NVIC_EnableIRQ(EXTI15_10_IRQn);				//Enabling the EXTI15 using NVIC
	__enable_irq() ;							//Enabling the Global Interrupts
}

//LED4 ON Function
void ON13()
{
	GPIOB->ODR &= ~(1<<13);
}

//LED4 ON Function
void OFF13()
{
	GPIOB->ODR |= (1<<13);
}

//LED4 ON Function
void ON14()
{
	GPIOB->ODR &= ~(1<<14);
}

//LED4 ON Function
void OFF14()
{
	GPIOB->ODR |= (1<<14);
}

//LED4 ON Function
void ON15()
{
	GPIOB->ODR &= ~(1<<15);
}

//LED4 ON Function
void OFF15()
{
	GPIOB->ODR |= (1<<15);
}

//Buzzer ON Function
void ON9()
{
	GPIOC->ODR |= (1<<9);
}

//Buzzer ON Function
void OFF9()
{
	GPIOC->ODR &= ~(1<<9);
}


//Configuration of Timer5 to generate 500ms delay
void DelayTim5_Con(){

RCC->APB1ENR|=(1<<3); 						//Enabling RCC to Timer5
TIM5->CR1 |=(1<<0);							//Count Start
TIM5->CNT=0;								//Setting Count value as 0
TIM5->PSC=16000-1;							//Setting Prescaler value
TIM5->ARR=500-1;							//Setting ARR Value

}


