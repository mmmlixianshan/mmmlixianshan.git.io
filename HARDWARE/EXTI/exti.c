#include "exti.h"
#include "stm32f10x.h"
//#include "key.h"
#include "led1.h"
#include "delay.h"
#include "lunzi.h"
void exti_Init(void)
{
	
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
  GPIO_InitTypeDef GPIO_InitStucture;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO|RCC_APB2Periph_GPIOA,ENABLE);//ʹ��GPIOA��Ӧ��ʱ�ӣ�ͬʱ��������ʱ�ӣ����Ÿ��ã�
//  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource15);//GPIOA.15�ж���ӳ��
 
	GPIO_InitStucture.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStucture.GPIO_Pin=GPIO_Pin_15;
	GPIO_InitStucture.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStucture);//��ʼ��GPIOA.15Ϊ����
	//���Ѿ���KEY_Init();������
	
//	GPIO_InitStucture.GPIO_Mode=GPIO_Mode_Out_PP;
//	GPIO_InitStucture.GPIO_Pin=GPIO_Pin_13;
//	GPIO_InitStucture.GPIO_Speed=GPIO_Speed_50MHz;
//	GPIO_Init(GPIOC,&GPIO_InitStucture);//��ʼ��GPIOA.15Ϊ����
//	GPIO_SetBits(GPIOC,GPIO_Pin_13);
	
	
	
	EXTI_InitStructure.EXTI_Line=EXTI_Line15;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;//�½��ش���	
	EXTI_Init(&EXTI_InitStructure);//���ô����жϵ��������
		
//	NVIC_InitStructure.NVIC_IRQChannel=EXTI9_5_IRQn; //ʹ��ͨ��5
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00; //????? 2,    
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;  //???? 1 
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;   //????????    
//	NVIC_Init(&NVIC_InitStructure);   
	
	NVIC_InitStructure.NVIC_IRQChannel= EXTI15_10_IRQn;  
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;     
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; 
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;    
	NVIC_Init(&NVIC_InitStructure);   
	
}

void EXTI15_10_IRQHandler(void) 
	{   
		Delay_ms(70);
    if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_15) == 0)
		{
		if(EXTI_GetITStatus(EXTI_Line15)!=RESET)
		{			
					
			GPIO_ResetBits(GPIOC, GPIO_Pin_13);
			stop();
			Delay_ms(200);
//			forward();
//			Delay_ms(5000);
			leftback();
			Delay_ms(750);
     	forward();
	    Delay_ms(500);
			right();
			Delay_ms(1085);
		  forward();
			Delay_ms(500);
			right();
			Delay_ms(1080);
			forward();
			Delay_ms(60);
      left();
			Delay_ms(850);
			
//		stop();
//			Delay_ms(5000);		
			EXTI_ClearITPendingBit(EXTI_Line15); 
			
		}			
	}
		
	} 












 
//void EXTI9_5_IRQHandler(void)
//{   


//	if(EXTI_GetITStatus(EXTI_Line9)!=RESET) 
//	{
//	
//		
//		
//		
//		EXTI_ClearITPendingBit(EXTI_Line9);   
//	
//	}
//	
//	
//	} 











/*void EXTI0_IRQHandler(void) 
	{   
		delay_ms(10);  
if(WK_UP==1) 
	{     
		LED0=!LED0;   
		LED1=!LED1; 
  } 
	EXTI_ClearITPendingBit(EXTI_Line0);  
	}  
	 
	 
 
 
void EXTI9_5_IRQHandler(void)
{   


	delay_ms(10);   
		if(KEY0==0)
  {  
	LED0=!LED0; 
	}
		EXTI_ClearITPendingBit(EXTI_Line5);   
	} 
 
 
 
 
void EXTI15_10_IRQHandler(void) 
	{   delay_ms(10);    //??  
		if(KEY1==0)
			{  
				LED1=!LED1; 
			} 
			EXTI_ClearITPendingBit(EXTI_Line15); 
			
			
	} 
	*/
	
	
	


