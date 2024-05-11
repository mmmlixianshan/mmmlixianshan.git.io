#include "stm32f10x.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "pwm.h"
#include "lunzi.h"
#include "led1.h"
#include "stdio.h"
#include "control.h"
#include "lk.h"
#include "exti.h"




extern int stopconfig; //����lk.c�����stopconfig��������main.c��ʹ��stopconfig�ñ���
int sensor[9]={0,0,0,0,0,0,0,0,0};   //����һ�����飬���ڴ�����⴫�������ص�ֵ����Ϊ�оŸ������������Զ���������Ԫ�ظ���Ϊ9
int Prestopconfig=0;//����һ���������ŵ�lk.c�ļ�read_sensor������ʶ���յ��ߵ������
int line=0;

int main(void)
{
	SystemInit();  //ϵͳʱ�ӵĳ�ʼ��
//	delay_init();  //��ʱʱ�ӵĳ�ʼ��
	LED1_Init();	 //STM32f103c8t6��Сϵͳ���ϵ�LED�Ƶĳ�ʼ��
	lunzi_Init();  //������е�״̬�ĳ�ʼ���������ǰ�����ߺ��ˣ�
  hongwai_Init();  //�Ÿ����⴫����������Сϵͳ���ϵĹܽ�IO�ڵĳ�ʼ��
//	 LED1_Init();
	 
	 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����жϷ��飬Ҳ���ǳ����Ⱥ�ִ�е����ȼ�
	 TIM2_PWM_Init(7199,0);  //PWM���ĳ�ʼ��������С��������٣�����7199��0��ʹ��PWM��Ƶ��Ϊ10Khz    f=72000000/((7199+1)*(0+1))=10000
	
	 TIM3_Init_Init(99,7199);	  //�жϷ������ĳ�ʼ����Ҳ����PWM���ĳ�ʼ�������������Ϊ10ms��Ҳ����ÿ10ms��ִ��һ��control.c�ļ���TIM3_IRQHandler������Ĳ���
	 exti_Init();		
 

    
			while(1) 
		{	
			read_sensor(); //��ȡ���⴫��������ֵ�ĺ�����ʼ��

			

			
			
		}
		
			 }
			 
			  


			
		



	
		


	
	

