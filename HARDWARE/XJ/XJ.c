#include "XJ.h"//ѭ���õ���mini���ӵ�PA4~7
#include "stm32f10x.h"
void XJ_Init(void)
{
		GPIO_InitTypeDef GPIO_InitStructure;
	  //NVIC_InitTypeDef NVIC_InitStructer;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC,ENABLE);

	  //RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
		/*GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;//����Ϊ�������룬�Ա��ȡ���������ϵĵ�ƽ
		GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2;
		GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
		GPIO_Init(GPIOA,&GPIO_InitStructure);*/
		
	  GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;//����Ϊ�������룬�Ա��ȡ���������ϵĵ�ƽ
		GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
		GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
		GPIO_Init(GPIOB,&GPIO_InitStructure);
	
		GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;//����Ϊ�������룬�Ա��ȡ���������ϵĵ�ƽ
		GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3|GPIO_Pin_1|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8;
		GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
		GPIO_Init(GPIOC,&GPIO_InitStructure);
		
	
	  

		/*NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

		NVIC_InitStructer.NVIC_IRQChannelPreemptionPriority=0;
		NVIC_InitStructer.NVIC_IRQChannelSubPriority=2;
		NVIC_InitStructer.NVIC_IRQChannelCmd=ENABLE;

		NVIC_Init(&NVIC_InitStructer);*/
			
		/*GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;//����Ϊ�������룬�Ա��ȡ���������ϵĵ�ƽ
		GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;
		GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
		GPIO_Init(GPIOC,&GPIO_InitStructure);
		GPIO_SetBits(GPIOB,GPIO_Pin_8);*/
	
	//������ѭ�����ӵ����Ŷ�����Ϊ�ߵ�ƽ������⵽�͵�ƽʱ�������⵽���ߡ�


	
	
	
	
}






