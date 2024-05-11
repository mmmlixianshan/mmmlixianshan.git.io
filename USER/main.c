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




extern int stopconfig; //引用lk.c定义的stopconfig，才能在main.c内使用stopconfig该变量
int sensor[9]={0,0,0,0,0,0,0,0,0};   //定义一个数组，用于储存红外传感器返回的值，因为有九个传感器，所以定义数组内元素个数为9
int Prestopconfig=0;//定义一个变量，放到lk.c文件read_sensor函数里识别终点线的语句中
int line=0;

int main(void)
{
	SystemInit();  //系统时钟的初始化
//	delay_init();  //延时时钟的初始化
	LED1_Init();	 //STM32f103c8t6最小系统板上的LED灯的初始化
	lunzi_Init();  //电机运行的状态的初始化（电机的前进或者后退）
  hongwai_Init();  //九个红外传感器连接最小系统板上的管脚IO口的初始化
//	 LED1_Init();
	 
	 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断分组，也就是程序先后执行的优先级
	 TIM2_PWM_Init(7199,0);  //PWM波的初始化，用于小车电机调速，传入7199和0，使得PWM的频率为10Khz    f=72000000/((7199+1)*(0+1))=10000
	
	 TIM3_Init_Init(99,7199);	  //中断服务函数的初始化，也就是PWM波的初始化，这里的周期为10ms，也就是每10ms会执行一次control.c文件里TIM3_IRQHandler函数里的操作
	 exti_Init();		
 

    
			while(1) 
		{	
			read_sensor(); //读取红外传感器返回值的函数初始化

			

			
			
		}
		
			 }
			 
			  


			
		



	
		


	
	

