/*
 * interrupt.c
 *
 *  Created on: 28.10.2017
 *      Author: forcexx
 */

#include <interrupt.h>
#include <touchscreen.h>
#include <gpio.h>

uint8_t toggle_flag = 0x0;

void interrupt_init(void) {

	/*
	 * External Interrupt
	 */
	EXTI_InitTypeDef exti_init_struct;
	EXTI_StructInit(&exti_init_struct);

	/*
	 * Enable external Interrupt on line 0
	 * Trigger on rising and falling edge
	 */
	exti_init_struct.EXTI_Line = EXTI_Line0;
	exti_init_struct.EXTI_LineCmd = ENABLE;
	exti_init_struct.EXTI_Mode = EXTI_Mode_Interrupt;
	exti_init_struct.EXTI_Trigger = EXTI_Trigger_Falling;

	EXTI_Init(&exti_init_struct);

	/*
	 * NVIC
	 */
	NVIC_InitTypeDef nvic_init_struct;

	/*
	 * Enable external interrupt line 0
	 * Priority 0
	 */
	nvic_init_struct.NVIC_IRQChannel = EXTI0_IRQn;
	nvic_init_struct.NVIC_IRQChannelCmd = ENABLE;
	nvic_init_struct.NVIC_IRQChannelPreemptionPriority = 0;
	nvic_init_struct.NVIC_IRQChannelSubPriority = 0;

	NVIC_Init(&nvic_init_struct);

	/*
	 * Enable Timer TIM2 interrupt
	 * Priority 0
	 */
	nvic_init_struct.NVIC_IRQChannel = TIM2_IRQn;
	nvic_init_struct.NVIC_IRQChannelCmd = ENABLE;
	nvic_init_struct.NVIC_IRQChannelPreemptionPriority = 0;
	nvic_init_struct.NVIC_IRQChannelSubPriority = 0;

	NVIC_Init(&nvic_init_struct);
}

void EXTI0_IRQHandler(void) {

	if (EXTI_GetITStatus(EXTI_Line0) != RESET) {

		/* Get X-Position of Touchscreen */
		//touch_pos_x = touch_get_pos_x_avg();

		/* Get X-Position of Touchscreen */
		//touch_pos_y = touch_get_pos_y_avg();

		/* Delete interrupt flag for line 0 */
		EXTI_ClearITPendingBit(EXTI_Line0);

	}
}

void TIM2_IRQHandler(void) {
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) {

		touch_pos_x = touch_get_pos_x_avg();
		touch_pos_y = touch_get_pos_y_avg();

		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}

