/*
 * gpio.h
 *
 *  Created on: 28.10.2017
 *      Author: forcexx
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stm32f10x_gpio.h>

/*
 * Initializes GPIO
 */
void gpio_init(void);

/*
 *  set output value of given pin
 */
void gpio_set_output(GPIO_TypeDef *port, uint16_t pin, BitAction val);

void gpio_set_jtag(FunctionalState _val);

#endif /* GPIO_H_ */
