#include "lunzi.h"
#include "stm32f10x.h"
#include "pwm.h"

void lunzi_Init(void)//����Ӧ��IO�ڽ��г�ʼ��,PA0-3
{

	  GPIO_InitTypeDef GPIO_InitStructure;
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//ʹ��GPIOA��ʱ��
  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//ʹ��GPIOB��ʱ��
	
		GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//���ģʽΪ�����������ƽ�ɸ߿ɵ�
	  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_4|GPIO_Pin_5;//PA0 PA1 PA4 PA5 �ܽ�IO��
	  GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//�ܽŴ����ٶ�
	  GPIO_Init(GPIOA,&GPIO_InitStructure);
}

void stop(void)//С�����������ת����ΪԽ���յ���ʱ������ֹͣ���������С������Ϊ����ͣ�����������Զ�ʱ��ķ�ת���ܵ������ԣ��Ӷ�ʹС��Ѹ��ͣ����
{
	  /*�ĸ��ܽ����ò�ͬ�ĵ�ƽ(1Ϊ�ߵ�ƽ0Ϊ�͵�ƽ)����ΪTB6612���߼����룬���Կ��Ƶ��ת��״̬�� */
	  /*����ȷ����ĸ��ܽ�IO�ֱ����ó�0 1 0 1�������ת����ô���������ó�1 0 1 0ʱ�������ת*/
	
		TIM_SetCompare3(TIM2,0);//������� TIM2->CH3
	  TIM_SetCompare4(TIM2,0);//������� TIM2->CH4
		GPIO_ResetBits(GPIOA,GPIO_Pin_0);//PA0�͵�ƽ   0
		GPIO_SetBits(GPIOA,GPIO_Pin_1);//PA1�ߵ�ƽ	     1
		GPIO_ResetBits(GPIOA,GPIO_Pin_4);//PA2�͵�ƽ	   0
		GPIO_SetBits(GPIOA,GPIO_Pin_5);//PA3�ߵ�ƽ     1
}
void forward(void)//С�����������ת
{

    TIM_SetCompare3(TIM2,2500);//������� TIM2->CH3
	  TIM_SetCompare4(TIM2,2500);//������� TIM2->CH4
	  GPIO_SetBits(GPIOA,GPIO_Pin_0);//PA0�ߵ�ƽ	     1
		GPIO_ResetBits(GPIOA,GPIO_Pin_1);//PA1�͵�ƽ   0
		GPIO_SetBits(GPIOA,GPIO_Pin_4);//PA2�ߵ�ƽ	     1
		GPIO_ResetBits(GPIOA,GPIO_Pin_5);//PA3�͵�ƽ   0

}

void right(void)//С�����������ת
{

    TIM_SetCompare3(TIM2,2500);//������� TIM2->CH3
	  TIM_SetCompare4(TIM2,2500);//������� TIM2->CH4
	  GPIO_SetBits(GPIOA,GPIO_Pin_0);//PA0�ߵ�ƽ	     1
		GPIO_ResetBits(GPIOA,GPIO_Pin_1);//PA1�͵�ƽ   0
		GPIO_ResetBits(GPIOA,GPIO_Pin_4);//PA2�ߵ�ƽ	     1
		GPIO_ResetBits(GPIOA,GPIO_Pin_5);//PA3�͵�ƽ   0

}

void leftback(void)//С�����������ת
{

    TIM_SetCompare3(TIM2,2500);//������� TIM2->CH3
	  TIM_SetCompare4(TIM2,2500);//������� TIM2->CH4
	  GPIO_ResetBits(GPIOA,GPIO_Pin_0);//PA0�ߵ�ƽ	     1
		GPIO_SetBits(GPIOA,GPIO_Pin_1);//PA1�͵�ƽ   0
		GPIO_ResetBits(GPIOA,GPIO_Pin_4);//PA2�ߵ�ƽ	     1
		GPIO_ResetBits(GPIOA,GPIO_Pin_5);//PA3�͵�ƽ   0

}


void left(void)//С�����������ת
{

    TIM_SetCompare3(TIM2,2500);//������� TIM2->CH3
	  TIM_SetCompare4(TIM2,2500);//������� TIM2->CH4
	  GPIO_ResetBits(GPIOA,GPIO_Pin_0);//PA0�ߵ�ƽ	     1
		GPIO_ResetBits(GPIOA,GPIO_Pin_1);//PA1�͵�ƽ   0
		GPIO_SetBits(GPIOA,GPIO_Pin_4);//PA2�ߵ�ƽ	     1
		GPIO_ResetBits(GPIOA,GPIO_Pin_5);//PA3�͵�ƽ   0

}

void rightback(void)//С�����������ת
{

    TIM_SetCompare3(TIM2,2500);//������� TIM2->CH3
	  TIM_SetCompare4(TIM2,2500);//������� TIM2->CH4
	  GPIO_ResetBits(GPIOA,GPIO_Pin_0);//PA0�ߵ�ƽ	     1
		GPIO_ResetBits(GPIOA,GPIO_Pin_1);//PA1�͵�ƽ   0
		GPIO_ResetBits(GPIOA,GPIO_Pin_4);//PA2�ߵ�ƽ	     1
		GPIO_SetBits(GPIOA,GPIO_Pin_5);//PA3�͵�ƽ   0

}
