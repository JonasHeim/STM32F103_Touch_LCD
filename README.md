# Touchscreen and LCD (2.4") via SPI using the STM32F103

Demonstration project using a 2.4" LCD with integrated touchscreen.
The [STM32F103C8T6](http://www.st.com/en/microcontrollers/stm32f103c8.html) (ARM Cortex-M3) is used within a small development board.
The touchscreen is interfaced via a [XPT2046](https://www.buydisplay.com/download/ic/XPT2046.pdf) touchscreen-controller using SPI communication.
The LCD is interfaced via the [ILI9341](https://cdn-shop.adafruit.com/datasheets/ILI9341.pdf) LCD driver using SPI communication.

*Please beware:*
This project uses the [STM32 Standard Peripheral Library](http://www.st.com/en/embedded-software/stm32-standard-peripheral-libraries.html?querycriteria=productId=LN1939), which is deprecated.


## Toolchain:
- [Eclipse CDT](https://www.eclipse.org/cdt/downloads.php)
- Cross ARM GCC (arm-none-eabi-gcc 7.2.0, Arch Repository) 
- [OpenOCD+GDB (v0.10.0)](https://gnu-mcu-eclipse.github.io/debug/openocd/)

Built on Arch-Linux (4.14.13-1-ARCH).

Bottom view of LCD module:
--------------------------
![LCD bottom view](img/LCD_Touch_Bottom.jpg)

Evaluation system on a breadboard:
--------------------------
![breadboard view](img/LCD_Touch_Eval.jpg)
