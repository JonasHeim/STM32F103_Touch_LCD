#include <interrupt.h>
#include <gpio.h>
#include <spi.h>
#include <dma.h>
#include <usart.h>
#include <stdio.h>
#include <touchscreen.h>
#include <timer.h>
#include <lcd.h>
#include <delay.h>

void lcd_test_routine(void);

int main(void) {

	gpio_init();
	usart_init();
	dma_init();
	spi_init();
	touchscreen_init();
	timer_init();
	interrupt_init();
	lcd_init();

	/* Enable cyclic timer for reading touch position */
	timer_set_touch(TIM2, ENABLE);

	/* LCD SPI CS initially high */
	gpio_set_output(GPIOB, GPIO_Pin_12, Bit_SET);

	//char buffer[25];

	while (1) {

		//sprintf(buffer, "X: %d, Y: %d\r\n", touch_pos_x, touch_pos_y);

		//usart_print(buffer);

		//lcd_test_routine();

		delay_ms(20);

		/* #########################################
		 * ##########  Read LCD information  #######
		 * ######################################### */

		/* LCD SPI CS low */
		gpio_set_output(GPIOB, GPIO_Pin_12, Bit_RESET);

		lcd_set_mode(COMMAND);

		SPI_I2S_SendData(SPI2, 0x04);
		/* Wait for SPI transmission to end */
		while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) == SET)
			;

		lcd_set_mode(DATA);

		SPI_I2S_SendData(SPI2, 0xFF);
		/* Wait for SPI transmission to end */
		while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) == SET)
			;

		SPI_I2S_SendData(SPI2, 0xFF);
		/* Wait for SPI transmission to end */
		while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) == SET)
			;

		SPI_I2S_SendData(SPI2, 0xFF);
		/* Wait for SPI transmission to end */
		while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) == SET)
			;

		SPI_I2S_SendData(SPI2, 0xFF);
		/* Wait for SPI transmission to end */
		while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) == SET)
			;

		/* LCD SPI CS high */
		gpio_set_output(GPIOB, GPIO_Pin_12, Bit_SET);

	}
}

void lcd_test_routine(void){
	/* #########################################
	 * ###############  RESET  #################
	 * ######################################### */

	/* LCD SPI CS low */
	gpio_set_output(GPIOB, GPIO_Pin_12, Bit_RESET);

	lcd_set_mode(COMMAND);

	SPI_I2S_SendData(SPI2, 0x01);
	/* Wait for SPI transmission to end */
	while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) == SET)
		;

	/* LCD SPI CS high */
	gpio_set_output(GPIOB, GPIO_Pin_12, Bit_SET);

	/* #########################################
	 * #############  SLEEP_OUT  ###############
	 * ######################################### */

	/* LCD SPI CS low */
	gpio_set_output(GPIOB, GPIO_Pin_12, Bit_RESET);

	lcd_set_mode(COMMAND);

	SPI_I2S_SendData(SPI2, 0x11);
	/* Wait for SPI transmission to end */
	while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) == SET)
		;

	/* LCD SPI CS high */
	gpio_set_output(GPIOB, GPIO_Pin_12, Bit_SET);

	/* #########################################
	 * #############  DISPLAY_ON  ##############
	 * ######################################### */

	/* LCD SPI CS low */
	gpio_set_output(GPIOB, GPIO_Pin_12, Bit_RESET);

	lcd_set_mode(COMMAND);

	SPI_I2S_SendData(SPI2, 0x29);
	/* Wait for SPI transmission to end */
	while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) == SET)
		;

	/* LCD SPI CS high */
	gpio_set_output(GPIOB, GPIO_Pin_12, Bit_SET);

	/* #########################################
	 * #############  READ_BRIGHTNESS  ##########
	 * ######################################### */

	/* LCD SPI CS low */
	gpio_set_output(GPIOB, GPIO_Pin_12, Bit_RESET);

	lcd_set_mode(COMMAND);

	SPI_I2S_SendData(SPI2, 0x52);
	/* Wait for SPI transmission to end */
	while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) == SET)
		;

	lcd_set_mode(DATA);

	SPI_I2S_SendData(SPI2, 0xFF);
	/* Wait for SPI transmission to end */
	while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) == SET)
		;

	SPI_I2S_SendData(SPI2, 0x7F);
			/* Wait for SPI transmission to end */
			while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) == SET)
				;

	/* LCD SPI CS high */
	gpio_set_output(GPIOB, GPIO_Pin_12, Bit_SET);

	/* #########################################
	 * #############  SET_BRIGHTNESS  ##########
	 * ######################################### */

	/* LCD SPI CS low */
	gpio_set_output(GPIOB, GPIO_Pin_12, Bit_RESET);

	lcd_set_mode(COMMAND);

	SPI_I2S_SendData(SPI2, 0x51);
	/* Wait for SPI transmission to end */
	while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) == SET)
		;

	lcd_set_mode(DATA);

	SPI_I2S_SendData(SPI2, 0x7F);
	/* Wait for SPI transmission to end */
	while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) == SET)
		;


	/* LCD SPI CS high */
	gpio_set_output(GPIOB, GPIO_Pin_12, Bit_SET);

	/* #########################################
	 * #############  READ_BRIGHTNESS  ##########
	 * ######################################### */

	/* LCD SPI CS low */
	gpio_set_output(GPIOB, GPIO_Pin_12, Bit_RESET);

	lcd_set_mode(COMMAND);

	SPI_I2S_SendData(SPI2, 0x52);
	/* Wait for SPI transmission to end */
	while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) == SET)
		;

	lcd_set_mode(DATA);

	SPI_I2S_SendData(SPI2, 0xFF);
	/* Wait for SPI transmission to end */
	while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) == SET)
		;

	SPI_I2S_SendData(SPI2, 0x7F);
			/* Wait for SPI transmission to end */
			while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) == SET)
				;

	/* LCD SPI CS high */
	gpio_set_output(GPIOB, GPIO_Pin_12, Bit_SET);
}
