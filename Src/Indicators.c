/* In this file, Indicators Configurations are Done */

#include<stm32f4xx.h>
#include <RQ1Headers.h>

//This Function used for Right Indicator ON
void rightON()
{
	ON9();
	ON14();
	//We have 500delay function. If we call the same function twice we'll get 1Sec Delay
	for(int y=0;y<2;y++){
		Delay_500ms();
	}
	OFF9();
	OFF14();
	//We have 500delay function. If we call the same function twice we'll get 1Sec Delay
	for(int y=0;y<2;y++){
		Delay_500ms();
	}
}

//This Function used for Left Indicator ON
void leftON()
{
	ON9();
	ON13();
	//We have 500delay function. If we call the same function twice we'll get 1Sec Delay
	for(int y=0;y<2;y++){
		Delay_500ms();
	}

	OFF9();
	OFF13();
	//We have 500delay function. If we call the same function twice we'll get 1Sec Delay
	for(int y=0;y<2;y++){
		Delay_500ms();
	}
}

//This Function used for Parking Indicator ON
void Parking()
{
			ON14();
			ON13();
			ON9();
			//For parking we only need 500ms delay
			Delay_500ms();
			OFF14();
			OFF13();
			OFF9();
			Delay_500ms();
}
