/*
 * timer.c
 *
 *  Created on: 11.11.2017
 *      Author: forcexx
 */


#include <timer.h>

void timer_init(void){

	/*
	 * Timer TIM2, GPIO, cyclic interrupt
	 */

	RCC_APB1PeriphClockCmd(RCC_APB1ENR_TIM2EN, ENABLE);

	TIM_TimeBaseInitTypeDef tim_timebaseinit_struct;
	TIM_TimeBaseStructInit(&tim_timebaseinit_struct);

	tim_timebaseinit_struct.TIM_ClockDivision = TIM_CKD_DIV4;
	tim_timebaseinit_struct.TIM_CounterMode = TIM_CounterMode_Up;
	tim_timebaseinit_struct.TIM_Period = 0xFFFF;
	tim_timebaseinit_struct.TIM_Prescaler = 0x3;
	tim_timebaseinit_struct.TIM_RepetitionCounter = 0x0;

	TIM_TimeBaseInit(TIM2, &tim_timebaseinit_struct);

	/* Enable interrupt */
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);

}

void timer_set_touch(TIM_TypeDef* timer, FunctionalState state){
	TIM_Cmd(timer, state);
}

