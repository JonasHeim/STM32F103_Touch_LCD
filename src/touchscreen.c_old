/*
 * touchscreen.c
 *
 *  Created on: 05.11.2017
 *      Author: forcexx
 */

#include <touchscreen.h>

Touch_CMD CMD_POS_X = { 0x0 };
Touch_CMD CMD_POS_Y = { 0x0 };

volatile Touch_POS touch_pos_x = 0x0;
volatile Touch_POS touch_pos_y = 0x0;

void touchscreen_init(void) {
	/*
	 *  Initialize SPI commands
	 */

	/* CMD_POS_X */
	CMD_POS_X.BITFIELD.S = 0x1;
	CMD_POS_X.BITFIELD.ADDR_2 = 0x1;
	CMD_POS_X.BITFIELD.ADDR_1 = 0x0;
	CMD_POS_X.BITFIELD.ADDR_0 = 0x1;
	CMD_POS_X.BITFIELD.MODE = 0x0;
	CMD_POS_X.BITFIELD.SER_DFR = 0x0;
	CMD_POS_X.BITFIELD.PD_1 = 0x0;
	CMD_POS_X.BITFIELD.PD_0 = 0x0;

	/* CMD_POS_Y */
	CMD_POS_Y.BITFIELD.S = 0x1;
	CMD_POS_Y.BITFIELD.ADDR_2 = 0x0;
	CMD_POS_Y.BITFIELD.ADDR_1 = 0x0;
	CMD_POS_Y.BITFIELD.ADDR_0 = 0x1;
	CMD_POS_Y.BITFIELD.MODE = 0x0;
	CMD_POS_Y.BITFIELD.SER_DFR = 0x0;
	CMD_POS_Y.BITFIELD.PD_1 = 0x0;
	CMD_POS_Y.BITFIELD.PD_0 = 0x0;
}

Touch_POS touch_get_pos_x(void) {
	volatile Touch_POS pos_x = 0x0;
	volatile uint16_t tmp_adc = 0x0;

	touch_send_spi_cmd(CMD_POS_X);

	tmp_adc = (uint16_t) ((dma_spi_touchscreen_rx_buffer[1] << 8)
			| dma_spi_touchscreen_rx_buffer[2]);

	pos_x = (Touch_POS) ((TOUCH_DIM_X * tmp_adc) / 0x7FFF);

	return pos_x;
}

Touch_POS touch_get_pos_x_avg(void){

	uint32_t pos_x_avg = 0x0;

	/* Do TOUCH_AVERAGE measurements and calculate the average */
	for(int i = 0; i < TOUCH_AVERAGE; i++){
		 pos_x_avg += touch_get_pos_x();
	}

	return (Touch_POS)(pos_x_avg/TOUCH_AVERAGE);

}

Touch_POS touch_get_pos_y(void) {
	volatile Touch_POS pos_y = 0x0;
	volatile uint16_t tmp_adc = 0x0;

	touch_send_spi_cmd(CMD_POS_Y);

	tmp_adc = (uint16_t) ((dma_spi_touchscreen_rx_buffer[1] << 8)
			| dma_spi_touchscreen_rx_buffer[2]);

	pos_y = (Touch_POS) ((TOUCH_DIM_Y * tmp_adc) / 0x7FFF);

	return pos_y;
}

Touch_POS touch_get_pos_y_avg(void){

	uint32_t pos_y_avg = 0x0;

	/* Do TOUCH_AVERAGE measurements and calculate the average */
	for(int i = 0; i < TOUCH_AVERAGE; i++){
		 pos_y_avg += touch_get_pos_y();
	}

	return (Touch_POS)(pos_y_avg/TOUCH_AVERAGE);

}

void touch_send_spi_cmd(Touch_CMD cmd) {

	/* Fill SPI buffer with command */
	dma_spi_touchscreen_tx_buffer[0] = cmd.CMD;

	/* Pull NSS low */
	GPIO_WriteBit(GPIOA, GPIO_Pin_4, DISABLE);

	/* Enable DMA transfer */
	dma_set_spi_tx(ENABLE);

	/* Wait for SPI transmission to end */
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY) == SET)
		;

	/* Disable DMA SPI TX channel and reset src memory address */
	dma_reset_spi_tx();

	/* Pull NSS high */
	GPIO_WriteBit(GPIOA, GPIO_Pin_4, ENABLE);

}

