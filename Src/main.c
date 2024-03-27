#include <stm32f4xx.h>
#include <stdint.h>
#include <RQ1Headers.h>

uint32_t count=0; 							//For Ignition Count
uint32_t right=0; 							//For Right Indicator
uint32_t left=0;  							//For Left Indicator
uint32_t head=0;  							//For HeadLight Button Count
uint32_t Fuel;	  							//For Fuel Indication
uint32_t Dummy;	  							//To store the sensor value of ADC
char rx_data;	  							//To store USART received data

int main(){
	Ignition_ButtonCon(); 					//Calling the ignition button configuration
	EXTI3_Con(); 							//Calling the External Interrupt configuration of PB3/Switch-2 EXTI

	while(1){

/* This While loop will execute continously and every time we need to check
 * Ignition status and fuel status. So if Count value=1 and Fuel greater than 0
 * then we will get all required operations
 */

		if(count==1){
			ADC1->CR2 |= (1<<30); 				//To start the conversion of ADC SWSTART

			while(!(ADC1->SR & (1<<1))){}		//wait for conversation to be complete



			//read converted result
			Dummy=(ADC1->DR); 					//Storing sensor data into Dummy Variable
			Fuel = (Dummy * 100)/4095; 			//Calculating the sensor value into percentage


		}

		if(count==1 && Fuel>0 && right==1 && left==0){ //Checking Right Indicator Status

			rightON(); 							//Calling Right Indicator ON Function

		}

		if(count==1 && Fuel>0 && right==0 && left==1){ //Checking Left Indicator Status

			leftON(); 							//Calling Left Indicator ON Function
		}

			if(count==1 && Fuel>0 && head==1){ //Checking Head Light Condition for Low Beam
				GPIOC_PWM_Con(); 				//Calling the Configuration of GPIOC in alternate mode
				dutycycle(10); 					//Setting the DutyCycle to 10% , so we will get Low Beam
			}

			if(count==1 && Fuel>0 && head==2 ){//Checking Head Light Condition for High Beam
				GPIOC_PWM_Con(); 				//Calling the Configuration of GPIOC in alternate mode
				dutycycle(90); 					//Setting the DutyCycle to 90% , so we will get Low Beam
			}

			if(count==1 && Fuel>0 && head==3 && right==0 && left==0){ //Checking Parking Condition for Parking
				Parking(); 						//Calling the Parking ON Function
			}

			if(count==1 && Fuel>0 && head>=4){ //We need only head count for 3 times. So other than 3 we need to keep head to 0
				GPIOC_Output_Con(); 			//Calling the Configuration of GPIOC in Output Mode
				head=0; 						//Setting head count 0
			}
	}
	return 0;
}


//EXTI3 Interrupt Handler, This Handler for PB3, i.e: Ignition
void EXTI3_IRQHandler(void)
{
	count++; 									//Count value incremented by 1
	if(count == 1) 								//Checking Count/Ignition Condition. If it is ON/1 all operations will done
	{
		LED_Con(); 								//Calling the LED Configuration Function
		Buzz_Con(); 							//Calling the Buzzer Configuration Function
		Button_Con();							//Calling the Button Configuration Function
		EXTI7415_Con();							//Calling the External Interrupt Configuration Function to Configure the remaing switches as interrupts
		PWMTim3_Con();							//Calling Timer3 Configuration for PWM
		DelayTim5_Con();						//Calling Timer5 Delay Configuration
		ADC_Init_PC2();							//Calling ADC Initialization Configuration
		ON15();									//Turning ON the LED2
		USART3_config();						//Calling USART3 Configuration Function
		Event_Tim4USART();						//Calling Timer4 Configuration for acting as EVENT
		rx_data = '\0';							//Storing NULL value in rx_data variable
	}
	if(count == 2)								//If count=2, it means OFF condtion
	{
		OFF15();								//Turing OFF the LED2
		count=0;								//Making count value as 0
		right=0;								//Making right value as 0
		left=0;									//Making left value as 0
		head=0;									//Making head value as 0
		GPIOC_Output_Con();						//Calling the Configuration of GPIOC in Output Mode
		rx_data = '\0';							//Storing NULL value in rx_data variable
		NVIC_DisableIRQ(EXTI15_10_IRQn); 		//Disabling EXTI15 Interrupt
		NVIC_DisableIRQ(TIM4_IRQn);				//Disabling TIM4 Interrupt

	}

	EXTI->PR |= (1<<3); 						//Clearing Pending Register 3rd bit, To clear the EXTI3 interrupt pending status

}

//EXTI3 Interrupt Handler, This Handler for PB4, i.e: Left Indicator
void EXTI4_IRQHandler(void)
{
	left++; 									//left value incremented by 1
	if(left>=2){								//If the left value grater the 1 it'll become 0.
		left=0;									//Making left value as 0
	}

	EXTI->PR |= (1<<4);							//Clearing Pending Register 4th bit, To clear the EXTI4 interrupt pending status

}

//EXTI7 Interrupt Handler, This Handler for PB7, i.e: Right Indicator
void EXTI9_5_IRQHandler(void)
{
	right++;									//right value incremented by 1
	if(right>=2){								//If the right value grater the 1 it'll become 0.
			right=0;							//Making right value as 0
		}

	EXTI->PR |= (1<<7);							//Clearing Pending Register 7th bit, To clear the EXTI7 interrupt pending status

}

//EXTI15 Interrupt Handler, This Handler for PA15, i.e: Head light Indicator
void EXTI15_10_IRQHandler(void)
{
	head++;										//head value incremented by 1

	if(head>=4){								//If the head value grater the 3 it'll become 0.
		GPIOC_Output_Con();						//Calling the Configuration of GPIOC in Output Mode
		head=0;									//Making head value as 0
	}
	EXTI->PR |= (1<<15);						//Clearing Pending Register 15th bit, To clear the EXTI15 interrupt pending status

}

//TIM4 Interrupt Handler. In this Handler Character 'j' sending From USART3 Tx to Rx
void TIM4_IRQHandler(void)
{

	 while(!(TIM4->SR &(1<<0))){} 				//Checking UIF Status of Timer4
	 TIM4->SR &= ~(1<<0); 		 				//Clearing UIF of Timer4

		USART3_sendchar('j'); 					//Sending 'j' through USART3
		USART3_receivechar();					//Calling USART3 Receive Function


}

//This Below function generates 500ms delay
void Delay_500ms()
{
	 while(!(TIM5->SR &(1<<0))){} 				//Checking UIF Status of Timer5
	 TIM5->SR &= ~(1<<0);		  				//Clearing UIF of Timer5
}
