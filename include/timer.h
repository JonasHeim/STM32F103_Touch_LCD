/*
 * timer.h
 *
 *  Created on: 11.11.2017
 *      Author: forcexx
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <stm32f10x_tim.h>

/*
 * Initializes timer modules
 */
void timer_init(void);


void timer_set_touch(TIM_TypeDef* timer, FunctionalState state);

#endif /* TIMER_H_ */
