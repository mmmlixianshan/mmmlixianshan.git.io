#include "lk.h"
#include "sys.h"
#include "delay.h"
#include "lunzi.h"
extern int sensor[9];//����������main��������飬�����ڱ��ļ���ʹ��sensor[x]�ñ���

extern int Prestopconfig;//����������main�����Prestopconfig�������ڱ��ļ���ʹ��Prestopconfig�ñ���
extern int line;

int error=0;//С����λ��ƫ���� ���(error),λ��ƫ��Խ�����Խ��ƫ��ԽС�����ԽС

int a=0;//С�������ٶȵı�־������aԽСʱ�������ٶ�Խ��
int stopconfig=0; //����յ��ߵı�־����  //����⵽�յ���ʱ���ñ�������ֵ��ı�

void hongwai_Init(void)
{
	  GPIO_InitTypeDef GPIO_InitStructure;
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//ʹ��GPIOA��ʱ��
  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//ʹ��GPIOB��ʱ��
//		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//ʹ�ܸ��ù��ܵ�ʱ��
	
	  GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;//IO�ܽ�ģʽ����Ϊ�������룬�������ܻ�ȡ�������������������ź�(�ߵ͵�ƽ)
	  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_10;
	  GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	  GPIO_Init(GPIOA,&GPIO_InitStructure);//PA4,PA5,PA6,PA7�ܽŵĳ�ʼ��
	
	  GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;//��������ģʽ
	  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_8|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_9;
	  GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	  GPIO_Init(GPIOB,&GPIO_InitStructure);//PB0,PB1,PB3,PB4,PB5�ܽŵĳ�ʼ��
//	  
//	  GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//�������ģʽ
//	  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;
//	  GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
//	  GPIO_Init(GPIOB,&GPIO_InitStructure);//PB8�ܽŵĳ�ʼ����TB6612����������ʹ�ܶ�
	
//	  GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);//�ر�STM32f103c8t6��JTAGD���ܣ�ʹPB3��PB4������ͨ��IO�ܽ�//���뿪�����ù��ܵ�ʱ�Ӳ��ܹرոù���
}

void read_sensor(void)//���⴫����ʶ�𵽺��߷��������źŵ͵�ƽ0��δʶ�𵽺��߷��ظߵ�ƽ1
{
	      /*��λ�ô�����˳�����ҵĴ��������ص������ź����δ�������sensor[0��8]��*/
//				sensor[0]=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4);//����Ĵ�����
//				sensor[1]=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5);
				sensor[0]=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6);//����ߴ�����
				sensor[1]=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7);
				sensor[2]=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0);
				sensor[3]=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1);//����Ĵ�����
				sensor[4]=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6);//����Ĵ�����
				sensor[5]=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7);
				sensor[6]=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8);
				sensor[7]=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9);//���Ҵ�����
				sensor[8]=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_10);
//				sensor[8]=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5);//���ҵĴ�����
	
	

				
	      if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==0)&&(sensor[4]==0&&sensor[5]==1)&&(sensor[6]==1&&sensor[7]==1))
				{	/*ʶ�𵽺������м�11110 0111*/	
				  error=0;a=0;
				} 
				 				
				else if((sensor[0]==0&&sensor[1]==0)&&(sensor[2]==0&&sensor[3]==0)&&(sensor[4]==0&&sensor[5]==0)&&(sensor[6]==0&&sensor[7]==0))
				{/*�м���0000 0000*/
					error=0;a=0;
//			    forward();
//				  stop();

//	        Delay_ms(2000);
				}			
				
				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==0&&sensor[3]==0)&&(sensor[4]==1&&sensor[5]==1)&&(sensor[6]==1&&sensor[7]==1))
				{/*С��λ���е�ƫ��1100 1111*/
					error=-3;a=1;//���Ϊ-1����������Ӳ��ٽ���΢С����  //a=0,�����ٶ����
				}
				
				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==1)&&(sensor[4]==0&&sensor[5]==0)&&(sensor[6]==1&&sensor[7]==1))
				{/*С��λ���е�ƫ��1111 0011*/
					error=3;a=1;//���Ϊ-1����������Ӳ��ٽ���΢С����  //a=0,�����ٶ����
				}
				
				
				else if((sensor[0]==1&&sensor[1]==0)&&(sensor[2]==0&&sensor[3]==1)&&(sensor[4]==1&&sensor[5]==1)&&(sensor[6]==1&&sensor[7]==1))
				{/*С��λ��ƫ��1001 1111*/
					error=-5;a=2;
				}	
				
				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==1)&&(sensor[4]==1&&sensor[5]==0)&&(sensor[6]==0&&sensor[7]==1))
				{/*С��λ��ƫ��1111 1001*/
					error=5;a=2;
				}	
				
				else if((sensor[0]==0&&sensor[1]==0)&&(sensor[2]==1&&sensor[3]==1)&&(sensor[4]==1&&sensor[5]==1)&&(sensor[6]==1&&sensor[7]==1))
				{/*ƫ��0011 1111*/
					error=-9;a=5;
				}				
								
				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==1)&&(sensor[4]==1&&sensor[5]==1)&&(sensor[6]==0&&sensor[7]==0))
				{/*ƫ�� ���1111 1100*/
					error=9;a=5;
				}
				
				
				
				

				
				
				else if((sensor[0]==0&&sensor[1]==0)&&(sensor[2]==0&&sensor[3]==0)&&(sensor[4]==0&&sensor[5]==1)&&(sensor[6]==1&&sensor[7]==1))
				{/*С��λ��ƫ��0000 0111*/
					error=-7;a=3;
//					if(line==0)
//					{					
//					 line=0;
//					}
				}
				
				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==0)&&(sensor[4]==0&&sensor[5]==0)&&(sensor[6]==0&&sensor[7]==0))
				{/*С��λ��ƫ��3.9 1110 0000*/
					error=7;a=3;
//					if(line==0)
//					{					
//					 line=0;
//					}
				}
			

				//������
//				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==0)&&(sensor[4]==0&&sensor[5]==0)&&(sensor[6]==1&&sensor[7]==0))
//				{/*ƫ��1110 0010*/
//					error=7;a=3;
////					if(line==0)
////					{					
////					 line=0;
////					}
//				}			
				
					else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==0)&&(sensor[4]==0&&sensor[5]==1)&&(sensor[6]==1&&sensor[7]==0))
				{/*С��λ��ƫ��1110 0110*/
					error=15;a=2;
					
				}			
				
//				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==0)&&(sensor[4]==0&&sensor[5]==1)&&(sensor[6]==0&&sensor[7]==0))
//				{/*ƫ�� ���1110 0100*/
//					error=9;a=5;
////					right();
////					Delay_ms(700);
//				}		
				
				
//				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==0)&&(sensor[4]==1&&sensor[5]==1)&&(sensor[6]==0&&sensor[7]==0))
//				{/*С��λ��ƫ��1110 1100*/
//					error=9;a=2;
//					
//				}
				
				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==0)&&(sensor[4]==1&&sensor[5]==1)&&(sensor[6]==1&&sensor[7]==0))
				{/*С��λ��ƫ��1110 1110*/
					error=15;a=2;
					
				}
	
				

//				else if((sensor[0]==0&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==0)&&(sensor[4]==0&&sensor[5]==1)&&(sensor[6]==1&&sensor[7]==1))
//				{/*С��λ��ƫ��0110 0111*/
//					error=-10;a=2;
//					
//				}
         						
				
//				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==0&&sensor[3]==0)&&(sensor[4]==1&&sensor[5]==1)&&(sensor[6]==1&&sensor[7]==0))
//				{/*ƫ�� ���1100 1110*/
//					error=9;a=5;
//					
//				}				
				
									
				
	
				
				//1�������������
//				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==0)&&(sensor[4]==1&&sensor[5]==1)&&(sensor[6]==1&&sensor[7]==1))
//				{/*ƫ��*/
//					error=-3;a=1;

//				}
				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==1)&&(sensor[4]==0&&sensor[5]==1)&&(sensor[6]==1&&sensor[7]==1))
				{/*ƫ��*/
					error=3;a=1;

				}
				
//				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==0&&sensor[3]==1)&&(sensor[4]==1&&sensor[5]==1)&&(sensor[6]==1&&sensor[7]==1))
//				{/*ƫ��*/
//					error=-5;a=2;

//				}
				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==1)&&(sensor[4]==1&&sensor[5]==0)&&(sensor[6]==1&&sensor[7]==1))
				{/*ƫ��*/
					error=5;a=2;

				}
//				else if((sensor[0]==1&&sensor[1]==0)&&(sensor[2]==1&&sensor[3]==1)&&(sensor[4]==1&&sensor[5]==1)&&(sensor[6]==1&&sensor[7]==1))
//				{/*ƫ��*/
//					error=-7;a=3;

//				}
				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==1)&&(sensor[4]==1&&sensor[5]==1)&&(sensor[6]==0&&sensor[7]==1))
				{/*ƫ��*/
					error=5;a=3;

				}
				else if((sensor[0]==0&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==1)&&(sensor[4]==1&&sensor[5]==1)&&(sensor[6]==1&&sensor[7]==1))
				{/*ƫ��*/
					error=-9;a=5;

				}
				else if((sensor[0]==1&&sensor[1]==1)&&(sensor[2]==1&&sensor[3]==1)&&(sensor[4]==1&&sensor[5]==1)&&(sensor[6]==1&&sensor[7]==0))
				{/*ƫ��*/
					error=9;a=5;

				}
				
				
				
			
		
       
}
