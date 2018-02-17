/*
 * lcd.h
 *
 *  Created on: 08.12.2017
 *      Author: forcexx
 */

#ifndef LCD_H_
#define LCD_H_

#include <gpio.h>

extern GPIO_TypeDef* LCD_RESET_PORT;
extern uint16_t LCD_RESET_PIN;

extern GPIO_TypeDef* LCD_DC_PORT;
extern uint16_t LCD_DC_PIN;

typedef enum {COMMAND, DATA} LCD_Mode;

/*
 * Initialize LCD
 */
void lcd_init(void);

/*
 * Set LCD reset pin
 */
void lcd_reset(BitAction _val);

/*
 * Set the mode of SPI transmission
 */
void lcd_set_mode(LCD_Mode _mode);


#endif /* LCD_H_ */
