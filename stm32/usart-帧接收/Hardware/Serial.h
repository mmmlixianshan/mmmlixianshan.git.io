#ifndef __SERIAL_H
#define __SERIAL_H

//void Serial_Init(void);
void UART_configure(void);
void NVIC_UART(void);
void USART_SendString(USART_TypeDef* USARTx, char *DataString);
#endif
