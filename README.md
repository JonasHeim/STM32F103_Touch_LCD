# Touchscreen and LCD (2.8") via SPI using the STM32F103

Built on Linux (Arch).

Toolchain:
-Eclipse
-Cross ARM GCC (arm-none-eabi-gcc 7.2.0 Arch Repository) 
-OpenOCD+GDB (v0.10.0)

To compile:
```
arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Werror -Wunused -Wuninitialized -Wall -Wextra -Wconversion -Wpointer-arith -Wpadded -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g3 -DDEBUG -DUSE_FULL_ASSERT -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu11 -Wstrict-prototypes -Wbad-function-cast -MMD -MP -MF"system/src/stm32f1-stdperiph/misc.d" -MT"<path-to-.o-file>" -c -o "<path-to-.o-file>" "<path-to-.c-file>"
```

To debug:

```
/usr/bin/openocd -c gdb_port 3333 -c telnet_port 4444 -f interface/stlink-v2.cfg -f target/stm32f1x.cfg
```

```
arm-n