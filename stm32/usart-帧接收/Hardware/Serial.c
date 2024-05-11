#include "stm32f10x.h"                  // Device header
#include "LED.h"
#include "OLED.h"
static uint8_t num=0;
uint16_t datareceive[10]={0};
uint8_t sum=0;
uint8_t i;
extern uint16_t numangle;


//uint8_t state_flag;
extern uint8_t led_flag;
extern uint8_t state_flag;

extern uint8_t detectstate1;
extern uint8_t detectstate2;

void USART_SendString(USART_TypeDef* USARTx, char *DataString)
{
	int i = 0;
	USART_ClearFlag(USARTx,USART_FLAG_TC);										//发送字符前清空标志位（否则缺失字符串的第一个字符）
	while(DataString[i] != '\0')												//字符串结束符
	{
		USART_SendData(USARTx,DataString[i]);									//每次发送字符串的一个字符
		while(USART_GetFlagStatus(USARTx,USART_FLAG_TC) == 0);					//等待数据发送成功
		USART_ClearFlag(USARTx,USART_FLAG_TC);									//发送字符后清空标志位
		i++;
	}
}


void UART_configure(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	//USART2_RX	  PA3       
	//USART2_TX	  PA2       
	GPIO_InitTypeDef GPIO_InitStructure;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode =USART_Mode_Rx|USART_Mode_Tx;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART2, &USART_InitStructure);
	USART_Cmd(USART2, ENABLE);


}

void NVIC_UART(void)
{
	
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);		

}


void  USART2_IRQHandler(void)//接收电脑传回的数据帧
{

	if(USART_GetFlagStatus(USART2,USART_IT_RXNE)==SET)
	{
	  		
	  datareceive[num++]=USART_ReceiveData(USART2);
		
	}
 

	//	0xAA帧首 0x0D 0x0E帧尾  第二帧为发送的帧的个数num   
		if( datareceive[0]==0xAA&& datareceive[1]==num&& datareceive[num-1]==0x0E&& datareceive[num-2]==0x0D)
		{
			num=0;
		  USART_SendString( USART2, "OK! ");
			
			if(datareceive[2]==0xb1&&datareceive[3]==0x12)
			{
				detectstate1=1;
        OLED_ShowString(2, 3, "facedetect!"); //识别用户成功
        numangle=300;		//舵机转动，门禁解锁
			}

				
			else 
			{
        OLED_ShowString(2, 3, "detectfail!"); 
				detectstate2=1;//识别识别
				numangle=100;		//门禁还是处于关闭状态	
				
			}

		}
		
  USART_ClearITPendingBit(USART2,USART_IT_RXNE);	

	
}





