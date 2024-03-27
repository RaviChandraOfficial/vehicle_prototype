#ifndef RQ1HEADERS_H_
#define RQ1HEADERS_H_


void Ignition_ButtonCon();
void EXTI3_Con();

void Buzz_Con();
void LED_Con();
void Button_Con();
void EXTI7415_Con();

void ON13();
void ON14();
void ON15();
void ON9();

void OFF13();
void OFF14();
void OFF15();
void OFF9();


void DelayTim5_Con();
void Delay_500ms();

void PWMTim3_Con(void);
void GPIOC_PWM_Con(void);
void GPIOC_Output_Con();
void dutycycle(unsigned int duty_cycle);

void ADC_Init_PC2(void);

void rightON();
void leftON();
void Parking();

void USART3_config();
void USART3_sendchar(uint8_t x);
void USART3_receivechar(void);

void Event_Tim4USART(void);




#endif /* RQ1HEADERS_H_ */
