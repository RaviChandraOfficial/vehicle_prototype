/* In this file, UASRT-3 Configurations are Done */

#include<stm32f4xx.h>

extern char rx_data;

//UASRT3 Configuration and PC10 as Tx , PC11 as Rx configuration
void USART3_config()
{
	RCC->AHB1ENR |= (1<<2);

	GPIOC->MODER &= ~(0xF<<20);
	GPIOC->MODER |= (0xA<<20);

	GPIOC->AFR[1] &= ~(0xFF<<8);
	GPIOC->AFR[1] |= (0x77<<8);


	RCC->APB1ENR |= (1<<18);
	USART3->CR1 |= (1<<13);
	USART3->CR1 &= ~(1<<12);
	USART3->BRR = 0x683;
	USART3->CR1 |= (3<<2);
}

//This function transfers j character to USART-DR
void USART3_sendchar(uint8_t x)
{
	USART3->DR = x;
	while(!(USART3->SR & (1<<6)));		//Checking TC bit
}

void USART3_receivechar(void)
{
	while(!(USART3->SR & (1<<5)));		//Checking RXNE bit
	rx_data = USART3->DR;				//Storing Received Data to rx_data
}
