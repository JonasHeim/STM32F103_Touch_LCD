/*
 * gpio.c
 *
 *  Created on: 28.10.2017
 *      Author: forcexx
 */

#include <gpio.h>

void gpio_init(void) {

	/*
	 *
	 * GPIO Init Struct
	 *
	 */
	GPIO_InitTypeDef gpio_init_struct;
	GPIO_StructInit(&gpio_init_struct);

	/*
	 *
	 * Clock enable Port A,B
	 *
	 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	/*
	 *
	 * LCD Interrupt
	 *
	 */

	/*
	 * Set Pin 0 of Port to Input with internal pullup
	 */
	gpio_init_struct.GPIO_Mode = GPIO_Mode_IPU;
	gpio_init_struct.GPIO_Pin = GPIO_Pin_0;
	gpio_init_struct.GPIO_Speed = GPIO_Speed_10MHz;

	GPIO_Init(GPIOB, &gpio_init_struct);

	/*
	 * Enable clock for alternate function (EXTI)
	 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

	/*
	 * Connect EXTI line 0 with Pin 0 on Port B
	 */
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource0);

	/*
	 *
	 * SPI Touchscreen
	 *
	 */

	/*
	 * Configure SPI: NSS(PA4)
	 */
	gpio_init_struct.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio_init_struct.GPIO_Pin = GPIO_Pin_4;
	gpio_init_struct.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOA, &gpio_init_struct);

	/*
	 * Configure SPI: CLK (PA5) and MOSI (PA7)
	 */
	gpio_init_struct.GPIO_Mode = GPIO_Mode_AF_PP;
	gpio_init_struct.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_7;
	gpio_init_struct.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOA, &gpio_init_struct);

	/*
	 * Configure SPI: MISO (PA6)
	 */
	gpio_init_struct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	gpio_init_struct.GPIO_Pin = GPIO_Pin_6;
	gpio_init_struct.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOA, &gpio_init_struct);

	GPIO_WriteBit(GPIOA, GPIO_Pin_4, ENABLE);

	/*
	 *
	 * USART1
	 *
	 */

	/*
	 * TX PA9
	 */
	gpio_init_struct.GPIO_Mode = GPIO_Mode_AF_PP;
	gpio_init_struct.GPIO_Pin = GPIO_Pin_9;
	GPIO_Init(GPIOA, &gpio_init_struct);

	/*
	 * Rx TA10
	 */
	gpio_init_struct.GPIO_Mode = GPIO_Mode_AIN;
	gpio_init_struct.GPIO_Pin = GPIO_Pin_10;
	GPIO_Init(GPIOA, &gpio_init_struct);

	/*
	 *
	 * SPI LCD
	 *
	 */

	/*
	 * Configure SPI: NSS(PB12)
	 */
	gpio_init_struct.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio_init_struct.GPIO_Pin = GPIO_Pin_12;
	gpio_init_struct.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOB, &gpio_init_struct);

	/*
	 * Configure SPI: CLK (PB13) and MOSI (PB15)
	 */
	gpio_init_struct.GPIO_Mode = GPIO_Mode_AF_PP;
	gpio_init_struct.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_15;
	gpio_init_struct.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOB, &gpio_init_struct);

	/*
	 * Configure SPI: MISO (PB14)
	 */
	gpio_init_struct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	gpio_init_struct.GPIO_Pin = GPIO_Pin_14;
	gpio_init_struct.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOB, &gpio_init_struct);

	/*
	 *
	 * Reset LCD Low active PB1
	 *
	 */
	gpio_init_struct.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio_init_struct.GPIO_Pin = GPIO_Pin_1;
	gpio_init_struct.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOB, &gpio_init_struct);

	/*
	 *
	 * D/C LCD PB6
	 *
	 */
	gpio_init_struct.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio_init_struct.GPIO_Pin = GPIO_Pin_6;
	gpio_init_struct.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOB, &gpio_init_struct);

}

void gpio_set_output(GPIO_TypeDef *port, uint16_t pin, BitAction val){
	GPIO_WriteBit(port, pin, val);
}

void gpio_set_jtag(FunctionalState _val){
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, _val);
}

