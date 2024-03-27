/* In this file, ADC Configured */

#include<stm32f4xx.h>

void ADC_Init_PC2(void)
{
	RCC->AHB1ENR |= (1<<2);

	GPIOC->MODER &= ~(3<<4);
	GPIOC->MODER |= (3<<4); 	//Setting PC2 to Analog MOde

	//configure the ADC module
	// clock to ADC
	RCC->APB2ENR |= (1<<8);

	//conversion sequence start
	ADC1->SQR3 = (12<<0);

	//conversion sequence length
	ADC1->SQR1 = (0x00);

	//enable ADC module
	ADC1->CR2 |= (3<<0);
	//ADC1->CR1 |= 0xB;
}

