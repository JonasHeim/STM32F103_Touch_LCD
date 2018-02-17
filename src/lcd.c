/*
 * lcd.c
 *
 *  Created on: 08.12.2017
 *      Author: forcexx
 */

#include <lcd.h>

GPIO_TypeDef* LCD_RESET_PORT = GPIOB;
uint16_t LCD_RESET_PIN = GPIO_Pin_1;

GPIO_TypeDef* LCD_DC_PORT = GPIOB;
uint16_t LCD_DC_PIN = GPIO_Pin_6;

void lcd_init(){

	/* Pull up LCD reset */
	lcd_reset(Bit_SET);

	/* wait 1ms */
	delay_ms(1);

	/* Pull down LCD reset */
	lcd_reset(Bit_RESET);

	/* wait 10ms */
	delay_ms(10);

	/* Pull up LCD reset */
	lcd_reset(Bit_SET);

	/* wait 50ms */
	delay_ms(50);

}

void lcd_reset(BitAction _val){
	gpio_set_output(LCD_RESET_PORT, LCD_RESET_PIN, _val);
}

void lcd_set_mode(LCD_Mode _mode){
	if(_mode == COMMAND){
		/* set to command mode */
		gpio_set_output(LCD_DC_PORT, LCD_DC_PIN, DISABLE);
	}
	else if(_mode == DATA){
		/* set to data mode */
		gpio_set_output(LCD_DC_PORT, LCD_DC_PIN, ENABLE);
	}
}



