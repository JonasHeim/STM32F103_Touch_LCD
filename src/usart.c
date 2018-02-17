/*
 * usart.c
 *
 *  Created on: 31.10.2017
 *      Author: forcexx
 */

#include <usart.h>

void usart_init() {

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

	USART_InitTypeDef usart_init_struct;
	USART_StructInit(&usart_init_struct);

	usart_init_struct.USART_BaudRate = 115200;
	usart_init_struct.USART_HardwareFlowControl =
	USART_HardwareFlowControl_None;
	usart_init_struct.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	usart_init_struct.USART_Parity = USART_Parity_No;
	usart_init_struct.USART_StopBits = USART_StopBits_1;
	usart_init_struct.USART_WordLength = USART_WordLength_8b;

	USART_Init(USART1, &usart_init_struct);

	USART_Cmd(USART1, ENABLE);
}

void usart_print(char* string) {
	if (string) {
		while (*string) {
			USART_SendData(USART1, (uint16_t) *string);
			while (!USART_GetFlagStatus(USART1, USART_FLAG_TXE)) {

			}
			string++;
		}
	}
}

