#include "pwm.h"
#include "led1.h"


//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��  �����PWM���� tim4
//void TIM4_PWM_Init(u16 arr,u16 psc)//��������main�д���arr��psc����ֵ 
//{
//	GPIO_InitTypeDef GPIO_InitStructure;
//	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;  //��ʱ��TIM�ṹ�嶨��
//	TIM_OCInitTypeDef  TIM_OCInitStructure;  //��ʱ��TIMͨ���ṹ�嶨�壬ÿ����ʱ�����ĸ�ͨ��

//	
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);// ʹ�ܶ�ʱ���ĵ�ʱ��
// 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//ʹ��GPIO B��ʱ�� 
//	                                                    
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;//PB6�ܽŵĳ�ʼ�����ܽŶ�Ӧ���ù��ܣ�TIM4_CH1(��ʱ���ĵ�ͨ��һ)
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //��ΪҪ�õ��ܽŵĸ��ù��ܣ����������ǹܽ�ģʽ�Ǹ����������
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOB, &GPIO_InitStructure);//PB6
//	
//	
//	TIM_TimeBaseStructure.TIM_Period = arr;//; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	
//	TIM_TimeBaseStructure.TIM_Prescaler =psc;//����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
//	TIM_TimeBaseStructure.TIM_ClockDivision = 0;//����ʱ�ӷָ�:TDTS = Tck_tim
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
//	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx����Ӧģʽ����

//  
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
//	TIM_OCInitStructure.TIM_Pulse =0; //���ô�װ�벶��ȽϼĴ���������ֵ
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
//	TIM_OC1Init(TIM4, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ��TIM4_CH1��ʱ���ĵ�ͨ��һ
//         
//	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);//ʹ��TIM4�� CCR1 �ϵ�Ԥװ�ؼĴ���

//  TIM_Cmd(TIM4, ENABLE);  //����TIM4
//}

void TIM2_PWM_Init(u16 arr,u16 psc)//��ʱ��2����pwm�������ת�� TIM2 CH3->PA2,CH4->PA3����
{  
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);// 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);  //

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; //�ܽŶ�Ӧ��ȫ���ù���ΪTIM2_CH3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOB10
	
	 //���ø�����Ϊ�����������,���TIM2_CH4��PWM���岨��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3; //TIM2_CH4
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOB11

	TIM_TimeBaseStructure.TIM_Period = arr;//; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ
	TIM_TimeBaseStructure.TIM_Prescaler =psc;//����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx����Ӧģʽ����

 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_Pulse =0; //���ô�װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
	TIM_OC3Init(TIM2, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ��TIM2_CH3


  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_Pulse =0; //���ô�װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը� 
	TIM_OC4Init(TIM2, &TIM_OCInitStructure); //����TIM_OCInitStruct��ָ���Ĳ�����ʼ��TIM2_CH4

	TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);  //CH3Ԥװ��ʹ��	 
	
	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);  //CH4Ԥװ��ʹ��	 

	TIM_ARRPreloadConfig(TIM2, ENABLE); //ʹ��TIM2��ARR�ϵ�Ԥװ�ؼĴ���
		
  TIM_Cmd(TIM2, ENABLE);  //����TIM2ʱ��

}//��ʼ�����������˶�״̬��pwm�������


void TIM3_Init_Init(u16 arr,u16 psc)//��ʱ��3����10ms�Ķ�ʱ�жϣ�ÿ10ms���붨ʱ�ж���ִ��pid
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;  //�ж����ȼ��Ľṹ�嶨��

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //TIM3��ʱ��ʹ��

	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx����Ӧ��ģʽ����
 
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);  //ʹ��TIM3�ж�
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3�жϷ�����������
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =1;  //�����ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;  //�����ȼ�2��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //ʹ��IRQ�ж�ͨ��
	NVIC_Init(&NVIC_InitStructure);  //����NVIC_InitStruct��ָ���Ĳ�����ʼ��NVIC�Ĵ���

	TIM_Cmd(TIM3, ENABLE);  //����TIM3
 
	
}







	
