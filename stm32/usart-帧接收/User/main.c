#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"
#include "LED.h"
#include "PWM.h"

uint16_t data=100;

uint8_t led_flag=0;
uint8_t state_flag=0;

uint8_t detectstate1=0;
uint8_t detectstate2=0;



uint16_t numangle=100;
//void USART_SendString(USART_TypeDef* USARTx, char *DataString);




int main(void)
{
	OLED_Init();
//	OLED_ShowString(1, 1, "RxData:");
	 PWM_Init();
	

//   LED_Init();  
	 
	UART_configure();

  NVIC_UART();
	
	while (1)
	{
//		
			PWM_SetCompare2(numangle);//用舵机的初始位置模拟门禁关闭状态

		//在串口接收中断函数Serial.c，对门禁进行控制
//		 if(detectstate1==1)
//		 {
//		 
////	    OLED_ShowString(2, 3, "facedetect!"); 	
//////			 Delay_ms(100);
////		  detectstate1=0;
//		 
//		 }
//		 
//				if(detectstate2==1)
//		 {
//		 
////      OLED_ShowString(2, 3, "detectfail!"); 
//////			 Delay_ms(100);	 
////		  detectstate2=0;

//		 }
////	

	}
}
