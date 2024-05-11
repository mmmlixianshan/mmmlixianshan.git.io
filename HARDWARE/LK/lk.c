#include "lk.h"
#include "sys.h"
#include "delay.h"
#include "lunzi.h"
extern int sensor[9];//引用主函数main定义的数组，才能在本文件内使用sensor[x]该变量

extern int Prestopconfig;//引用主函数main定义的Prestopconfig，才能在本文件内使用Prestopconfig该变量
extern int line;

int error=0;//小车的位置偏移量 误差(error),位置偏移越大，误差越大，偏移越小，误差越小

int a=0;//小车基础速度的标志变量，a越小时，基础速度越大
int stopconfig=0; //检测终点线的标志变量  //当检测到终点线时，该变量的数值会改变

void hongwai_Init(void)
{
	  GPIO_InitTypeDef GPIO_InitStructure;
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//使能GPIOA的时钟
  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//使能GPIOB的时钟
//		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//使能复用功能的时钟
	
	  GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;//IO管脚模式配置为浮空输入，这样就能获取传感器传回来的数字信号(高低电平)
	  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_10;
	  GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	  GPIO_Init(GPIOA,&GPIO_InitStructure);//PA4,PA5,PA6,PA7管脚的初始化
	
	  GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;//浮空输入模式
	  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_8|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_9;
	  GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	  GPIO_Init(GPIOB,&GPIO_InitStructure);//PB0,PB1,PB3,PB4,PB5管脚的初始化
//	  
//	  GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//推挽输出模式
//	  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;
//	  GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
//	  GPIO_Init(GPIOB,&GPIO_InitStructure);//PB8管脚的初始化，TB6612电机驱动板的使能端
	
//	  GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);//关闭STM32f103c8t6的JTAGD功能，使PB3和PB4用作普通的IO管脚//必须开启复用功能的时钟才能关闭该功能
}

void read_sensor(void)//红外传感器识别到黑线返回数字信号低电平0，未识别到黑线返回高电平1
{
	      /*将位置从最左按顺序到最右的传感器返回的数字信号依次存入数组sensor[0至8]里*/
//				sensor[0]=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4);//最左的传感器
//				sensor[1]=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5);
				sensor[0]=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6);//最左边传感器
				sensor[1]=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7);
				sensor[2]=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0);
				sensor[3]=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1);//中央的传感器
				sensor[4]=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6);//中央的传感器
				sensor[5]=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7);
				sensor[6]=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8);
				sensor[7]=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9);//最右传感器
				sensor[8]=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_10);
//				sensor[8]=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5);//最右的传感器
	
	

				
	      if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==0)&&(sensor[4]==0&&sensor[5]==1)&&(sensor[6]==1&&sensor[7]==1))
				{	/*识别到黑线在中间11110 0111*/	
				  error=0;a=0;
				} 
				 				
				else if((sensor[0]==0&&sensor[1]==0)&&(sensor[2]==0&&sensor[3]==0)&&(sensor[4]==0&&sensor[5]==0)&&(sensor[6]==0&&sensor[7]==0))
				{/*中间线0000 0000*/
					error=0;a=0;
//			    forward();
//				  stop();

//	        Delay_ms(2000);
				}			
				
				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==0&&sensor[3]==0)&&(sensor[4]==1&&sensor[5]==1)&&(sensor[6]==1&&sensor[7]==1))
				{/*小车位置有点偏右1100 1111*/
					error=-3;a=1;//误差为-1，舵机和轮子差速进行微小控制  //a=0,基础速度最大
				}
				
				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==1)&&(sensor[4]==0&&sensor[5]==0)&&(sensor[6]==1&&sensor[7]==1))
				{/*小车位置有点偏右1111 0011*/
					error=3;a=1;//误差为-1，舵机和轮子差速进行微小控制  //a=0,基础速度最大
				}
				
				
				else if((sensor[0]==1&&sensor[1]==0)&&(sensor[2]==0&&sensor[3]==1)&&(sensor[4]==1&&sensor[5]==1)&&(sensor[6]==1&&sensor[7]==1))
				{/*小车位置偏右1001 1111*/
					error=-5;a=2;
				}	
				
				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==1)&&(sensor[4]==1&&sensor[5]==0)&&(sensor[6]==0&&sensor[7]==1))
				{/*小车位置偏右1111 1001*/
					error=5;a=2;
				}	
				
				else if((sensor[0]==0&&sensor[1]==0)&&(sensor[2]==1&&sensor[3]==1)&&(sensor[4]==1&&sensor[5]==1)&&(sensor[6]==1&&sensor[7]==1))
				{/*偏右0011 1111*/
					error=-9;a=5;
				}				
								
				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==1)&&(sensor[4]==1&&sensor[5]==1)&&(sensor[6]==0&&sensor[7]==0))
				{/*偏左 锐角1111 1100*/
					error=9;a=5;
				}
				
				
				
				

				
				
				else if((sensor[0]==0&&sensor[1]==0)&&(sensor[2]==0&&sensor[3]==0)&&(sensor[4]==0&&sensor[5]==1)&&(sensor[6]==1&&sensor[7]==1))
				{/*小车位置偏右0000 0111*/
					error=-7;a=3;
//					if(line==0)
//					{					
//					 line=0;
//					}
				}
				
				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==0)&&(sensor[4]==0&&sensor[5]==0)&&(sensor[6]==0&&sensor[7]==0))
				{/*小车位置偏右3.9 1110 0000*/
					error=7;a=3;
//					if(line==0)
//					{					
//					 line=0;
//					}
				}
			

				//弯道情况
//				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==0)&&(sensor[4]==0&&sensor[5]==0)&&(sensor[6]==1&&sensor[7]==0))
//				{/*偏左1110 0010*/
//					error=7;a=3;
////					if(line==0)
////					{					
////					 line=0;
////					}
//				}			
				
					else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==0)&&(sensor[4]==0&&sensor[5]==1)&&(sensor[6]==1&&sensor[7]==0))
				{/*小车位置偏左1110 0110*/
					error=15;a=2;
					
				}			
				
//				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==0)&&(sensor[4]==0&&sensor[5]==1)&&(sensor[6]==0&&sensor[7]==0))
//				{/*偏左 锐角1110 0100*/
//					error=9;a=5;
////					right();
////					Delay_ms(700);
//				}		
				
				
//				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==0)&&(sensor[4]==1&&sensor[5]==1)&&(sensor[6]==0&&sensor[7]==0))
//				{/*小车位置偏左1110 1100*/
//					error=9;a=2;
//					
//				}
				
				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==0)&&(sensor[4]==1&&sensor[5]==1)&&(sensor[6]==1&&sensor[7]==0))
				{/*小车位置偏左1110 1110*/
					error=15;a=2;
					
				}
	
				

//				else if((sensor[0]==0&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==0)&&(sensor[4]==0&&sensor[5]==1)&&(sensor[6]==1&&sensor[7]==1))
//				{/*小车位置偏左0110 0111*/
//					error=-10;a=2;
//					
//				}
         						
				
//				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==0&&sensor[3]==0)&&(sensor[4]==1&&sensor[5]==1)&&(sensor[6]==1&&sensor[7]==0))
//				{/*偏左 锐角1100 1110*/
//					error=9;a=5;
//					
//				}				
				
									
				
	
				
				//1个传感器的情况
//				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==0)&&(sensor[4]==1&&sensor[5]==1)&&(sensor[6]==1&&sensor[7]==1))
//				{/*偏右*/
//					error=-3;a=1;

//				}
				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==1)&&(sensor[4]==0&&sensor[5]==1)&&(sensor[6]==1&&sensor[7]==1))
				{/*偏右*/
					error=3;a=1;

				}
				
//				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==0&&sensor[3]==1)&&(sensor[4]==1&&sensor[5]==1)&&(sensor[6]==1&&sensor[7]==1))
//				{/*偏右*/
//					error=-5;a=2;

//				}
				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==1)&&(sensor[4]==1&&sensor[5]==0)&&(sensor[6]==1&&sensor[7]==1))
				{/*偏左*/
					error=5;a=2;

				}
//				else if((sensor[0]==1&&sensor[1]==0)&&(sensor[2]==1&&sensor[3]==1)&&(sensor[4]==1&&sensor[5]==1)&&(sensor[6]==1&&sensor[7]==1))
//				{/*偏右*/
//					error=-7;a=3;

//				}
				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==1)&&(sensor[4]==1&&sensor[5]==1)&&(sensor[6]==0&&sensor[7]==1))
				{/*偏左*/
					error=5;a=3;

				}
				else if((sensor[0]==0&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==1)&&(sensor[4]==1&&sensor[5]==1)&&(sensor[6]==1&&sensor[7]==1))
				{/*偏右*/
					error=-9;a=5;

				}
				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==1)&&(sensor[4]==1&&sensor[5]==1)&&(sensor[6]==1&&sensor[7]==0))
				{/*偏左*/
					error=9;a=5;

				}
				
				
				
			
		
       
}
