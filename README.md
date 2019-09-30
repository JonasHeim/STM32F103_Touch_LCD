# Touchscreen and LCD (2.4") via SPI using the STM32F103

## ! Work in progress !

Demonstration project using a 2.4" LCD with integrated touchscreen.
The [STM32F103C8T6](http://www.st.com/en/microcontrollers/stm32f103c8.html) (ARM Cortex-M3) is used within a small development board.
The touchscreen is interfaced via a [XPT2046](https://www.buydisplay.com/download/ic/XPT2046.pdf) touchscreen-controller using SPI communication.
The LCD is interfaced via the [ILI9341](https://cdn-shop.adafruit.com/datasheets/ILI9341.pdf) LCD driver using SPI communication.

## Toolchain:
- [VSCode](https://www.eclipse.org/cdt/downloads.php) - optional - Build and Flash tasks are avaiable
- GNU (Cross-)ARM GCC (arm-none-eabi-gcc 9.2.0, Arch Repository) 
- [OpenOCD+GDB (v0.10.0)](https://gnu-mcu-eclipse.github.io/debug/openocd/)

Built on Arch-Linux.

## Connections from MCU to LCD (on J2)

| LCD Pin | MCU Pin | Description | 
| -------- | ------- | ------- |
| VCC | 3.3 | Power 3.3V | 
| GND | GND | Ground |
| CS | B15 | SPI Chip Select |
| Reset | B1 | LCD Controller Reset |
| D/C | B6 | Data/Command |
| SDI (MOSI) | B12 | SPI Data to LCD |
| SCK | B13 | SPI Clock |
| LED | 390 Ohm Resistor to VCC | LCD Background light |
| SDO (MISO) | B14 | SPI Data to MCU |

## Connections from MCU to LCD Touchscreen (on J2)

| Touch Pin | MCU Pin | Description | 
| -------- | ------- | ------- |
| T_CLK | A5 (SPI1_SCK) | Touchscreen SPI Clock |
| T_CS | A4 (SPI1_NSS) | Touchscreen Chip Select | 
| T_DIN | A7 (SPI1_MOSI) | Touchscreen SPI Data to Touchscreen controller | 
| T_DO | A6 (SPI1_MISO) | Touchscreen SPI Data to MCU | 
| T_IRQ | B0 (GPIO) | Touchscreen Touch-Interrupt | 

Bottom view of LCD module:
--------------------------
![LCD bottom view](img/LCD_Touch_Bottom.jpg)

Evaluation system on a breadboard:
--------------------------
![breadboard view](img/LCD_Touch_Eval.jpg)
