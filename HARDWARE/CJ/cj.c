
#include "cj.h"
#include "stm32f10x.h"
#include "delay.h"
#include "usart.h"
#include "stdio.h"
//unsigned int overcount=0;



/*void NVIC_Config(void)//ʹ�õ���TIM2
{
NVIC_InitTypeDef NVIC_InitStructer;

NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

NVIC_InitStructer.NVIC_IRQChannelPreemptionPriority=2;
NVIC_InitStructer.NVIC_IRQChannelSubPriority=2;
NVIC_InitStructer.NVIC_IRQChannel=TIM2_IRQn;
NVIC_InitStructer.NVIC_IRQChannelCmd=ENABLE;

NVIC_Init(&NVIC_InitStructer);
}*/

/*void CH_SR05_Init(void)//��������һ���ⲿ�豸
{
GPIO_InitTypeDef GPIO_InitStructer;
TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructer;
TIM_ICInitTypeDef  TIM2_ICInitStructure;
	
RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE);
RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

GPIO_InitStructer.GPIO_Speed=GPIO_Speed_50MHz;
GPIO_InitStructer.GPIO_Mode=GPIO_Mode_Out_PP;
GPIO_InitStructer.GPIO_Pin=GPIO_Pin_14;
GPIO_Init(GPIOA, &GPIO_InitStructer);//PA14�ܽ�ʹ��=Trig
GPIO_ResetBits(GPIOA,GPIO_Pin_14);

			GPIO_InitStructer.GPIO_Mode=GPIO_Mode_IPD;
			GPIO_InitStructer.GPIO_Pin=GPIO_Pin_13;
			GPIO_Init(GPIOA, & GPIO_InitStructer);//PA13�ܽ�ʹ��=Echo
			GPIO_ResetBits(GPIOA,GPIO_Pin_13);
	
TIM_DeInit(TIM2);
TIM_TimeBaseInitStructer.TIM_Period=999;//��ʱ����Ϊ1000
TIM_TimeBaseInitStructer.TIM_Prescaler=71; //��Ƶϵ��Ϊ72
TIM_TimeBaseInitStructer.TIM_ClockDivision=TIM_CKD_DIV1;//����Ƶ
TIM_TimeBaseInitStructer.TIM_CounterMode=TIM_CounterMode_Up;
TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructer);//ͨ�ö�ʱ��2������

    TIM2_ICInitStructure.TIM_Channel = TIM_Channel_1; //CC1S=01 	ѡ������� IC1ӳ�䵽TI1��
  	TIM2_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	//�����ز���
  	TIM2_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //ӳ�䵽TI1��
  	TIM2_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 //���������Ƶ,����Ƶ 
  	TIM2_ICInitStructure.TIM_ICFilter = 0x00;//IC1F=0000 ���������˲��� ���˲�
  	TIM_ICInit(TIM2, &TIM2_ICInitStructure);
		
TIM_ClearFlag(TIM2,TIM_FLAG_Update);
TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);//���������ж�
NVIC_Config();
TIM_Cmd(TIM2,DISABLE);
*/


/*float Senor_Using(void)//����Ҫ����������������ķ���ֵΪfloat�ͣ�
{
	
	
	float length=0,sum=0;
	u16 tim=0;
	unsigned int i=0;


	while(i!=5)
{

	PAout(14)=1; //
	delay_us(20); //���������ƽ
	PAout(14)=0;

	while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_13)==0);//���⵽�͵�ƽ������һֱ������ѭ������⵽�ߵ�ƽ�ͼ���ִ��
	TIM_SetCounter(TIM2,0);
	overcount=0;
	TIM_Cmd(TIM2,ENABLE);
	i+=1;
	while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_13)==1);//��⵽�͵�ƽ������ѭ��
	TIM_Cmd(TIM2,DISABLE);//
	tim=overcount*1000;
	tim+=TIM_GetCounter(TIM2);//ȡ��TIM2 �ж�ʱ���ļ���ֵ
		TIM2->CNT=0; 
	delay_ms(50);
	length=((float)tim/58.0);//

	sum=length+sum;
}
	length=sum/5.0;
	return length; //����5�β�����ƽ��ֵ

}*/


/*void TIM2_IRQHandler(void) //??,????????,??????????,??????????
{
if(TIM_GetITStatus(TIM2,TIM_IT_Update)!=RESET)
  {
TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
overcount++;

  }
}*/



