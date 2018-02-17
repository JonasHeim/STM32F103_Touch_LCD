/*
 * touchscreen.h
 *
 *  Created on: 05.11.2017
 *      Author: forcexx
 */

#ifndef TOUCHSCREEN_H_
#define TOUCHSCREEN_H_

#include <spi.h>
#include <dma.h>
#include <usart.h>

#define TOUCH_DIM_X 240
#define TOUCH_DIM_Y	320

#define TOUCH_AVERAGE	3

typedef uint16_t Touch_POS;

typedef union {
	uint8_t CMD;
	struct {
		uint8_t PD_0 :1;
		uint8_t PD_1 :1;
		uint8_t SER_DFR :1;
		uint8_t MODE :1;
		uint8_t ADDR_0 :1;
		uint8_t ADDR_1 :1;
		uint8_t ADDR_2 :1;
		uint8_t S :1;

	} BITFIELD;
} Touch_CMD;

extern Touch_CMD CMD_POS_X;
extern Touch_CMD CMD_POS_Y;

void touchscreen_init(void);
Touch_POS touch_get_pos_x(void);
Touch_POS touch_get_pos_x_avg(void);
Touch_POS touch_get_pos_y(void);
Touch_POS touch_get_pos_y_avg(void);
void touch_send_spi_cmd(Touch_CMD cmd);

extern volatile Touch_POS touch_pos_x;
extern volatile Touch_POS touch_pos_y;

#endif /* TOUCHSCREEN_H_ */
