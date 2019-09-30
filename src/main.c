/**
  ******************************************************************************
  * @file    ADC/ADC_Regular_injected_groups/Src/main.c
  * @author  MCD Application Team
  * @version V1.5.0
  * @date    14-April-2017
  * @brief   This example provides a short description of how to use the ADC
  *          peripheral to perform conversions using the 2 ADC groups: 
  *          group regular for ADC conversions on main stream and 
  *          group injected for ADC conversions limited on specific events
  *          (conversions injected within main conversions stream). Other 
  *          peripherals used: DMA, TIM (ADC group regular conversions 
  *          triggered  by TIM, ADC group regular conversion data
  *          transfered by DMA).
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* UART logging macro */
//#define BSP_LOG(x)  BSP_COM_Print(&UART1_Handle, x)
#define BSP_LOG(x)

void SystemClock_Config(void);

const UART_InitTypeDef UART1_Init = 
{
  .BaudRate     = 9600,
  .WordLength   = UART_WORDLENGTH_8B,
  .StopBits     = UART_STOPBITS_1,
  .Parity       = UART_PARITY_NONE,
  .Mode         = UART_MODE_TX_RX,
  .HwFlowCtl    = UART_HWCONTROL_NONE,
  .OverSampling = UART_OVERSAMPLING_16,
};

const SPI_InitTypeDef SPI1_Init =
{
  

};

uint8_t uart1_tx_buffer[100];
uint8_t uart1_rx_buffer[100];

UART_HandleTypeDef UART1_Handle;
SPI_HandleTypeDef SPI1_Handle;

/* FreeRTOS stuff */
void task_2(void*);
#define STACK_SIZE 200
StackType_t xStack_2[ STACK_SIZE ];

StaticTask_t xTaskBuffer_2;

int main(void)
{
  UART1_Handle.Init         = UART1_Init;
  UART1_Handle.pTxBuffPtr   = uart1_tx_buffer;
  UART1_Handle.TxXferSize   = 100;
  UART1_Handle.TxXferCount  = 1;
  UART1_Handle.pRxBuffPtr   = uart1_rx_buffer;
  UART1_Handle.RxXferSize   = 100;
  UART1_Handle.RxXferCount  = 1;


  SystemClock_Config();
  if(HAL_OK != HAL_Init())
  {
    while(1){};
  }

  PWR_PVDTypeDef pwrpvdstruct = {
    .PVDLevel = PWR_PVDLEVEL_7,
    .Mode = PWR_PVD_MODE_IT_RISING_FALLING,
  };

  __HAL_RCC_PWR_CLK_ENABLE();

  HAL_PWR_ConfigPVD(&pwrpvdstruct);

  HAL_NVIC_SetPriority(PVD_IRQn, 1, 1);
  HAL_NVIC_EnableIRQ(PVD_IRQn);

  HAL_PWR_EnablePVD();

  BSP_LED_Init(LED_GREEN);

  if(HAL_OK != BSP_COM_Init(COM0, &UART1_Handle))
  { 
    while(1){};
  }

  BSP_SPI_Init(BSP_SPI0, &SPI1_Handle);

  vTraceEnable(TRC_START);

  /*
   * FreeRTOS 
   */

  /* Create task 2 - LED Red Blinky */
  xTaskCreateStatic(task_2, "LED_GREEN", STACK_SIZE, (void*) 1, 1, xStack_2, &xTaskBuffer_2);

  /* Start the FreeRTOS scheduler */
  vTaskStartScheduler();
}

void task_2(void* args)
{
  while(1)
  {
    vTaskDelay(100/portTICK_PERIOD_MS);
    BSP_LED_Toggle(LED_GREEN);
  }
}

/*
 * Set SYSCLK   = 72MHz
 * Set APB1CLK  = 36MHz
 * Set APB2CLK  = 72MHz
 */
void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef clkinitstruct = {0};
  RCC_OscInitTypeDef oscinitstruct = {0};
  
  /* Configure PLLs------------------------------------------------------*/
  /* PLL2 configuration: PLL2CLK=(HSE/HSEPrediv2Value)*PLL2MUL=(25/5)*8=40 MHz */
  /* PREDIV1 configuration: PREDIV1CLK = PLL2CLK / HSEPredivValue = 40 / 5 = 8 MHz */
  /* PLL configuration: PLLCLK = PREDIV1CLK * PLLMUL = 8 * 9 = 72 MHz */
  /* Enable HSE Oscillator and activate PLL with HSE as source */
  oscinitstruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  oscinitstruct.HSEState = RCC_HSE_ON;
  oscinitstruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  oscinitstruct.PLL.PLLState = RCC_PLL_ON;
  oscinitstruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  oscinitstruct.PLL.PLLMUL = RCC_PLL_MUL9;
  
  if (HAL_RCC_OscConfig(&oscinitstruct)!= HAL_OK)
  { /* Initialization Error */
    while(1);
  }
  
  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 clocks
  dividers */
  clkinitstruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK |
  RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  clkinitstruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  clkinitstruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  clkinitstruct.APB2CLKDivider = RCC_HCLK_DIV1;
  clkinitstruct.APB1CLKDivider = RCC_HCLK_DIV2;
  
  if (HAL_RCC_ClockConfig(&clkinitstruct, FLASH_LATENCY_2)!= HAL_OK)
  { /* Initialization Error */
    while(1);
  }
}

void PVD_IRQHandler(void)
{
  HAL_PWR_PVD_IRQHandler();
}

void HAL_PWR_PVDCallback(void)
{
  BSP_LOG("Undervoltage <2.9V detected!\r\n");
  BSP_LED_On(LED_GREEN);
}

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer,
                                    StackType_t **ppxIdleTaskStackBuffer,
                                    uint32_t *pulIdleTaskStackSize )
{
/* If the buffers to be provided to the Idle task are declared inside this
function then they must be declared static - otherwise they will be allocated on
the stack and so not exists after this function exits. */
static StaticTask_t xIdleTaskTCB;
static StackType_t uxIdleTaskStack[ configMINIMAL_STACK_SIZE ];

    /* Pass out a pointer to the StaticTask_t structure in which the Idle task's
    state will be stored. */
    *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;

    /* Pass out the array that will be used as the Idle task's stack. */
    *ppxIdleTaskStackBuffer = uxIdleTaskStack;

    /* Pass out the size of the array pointed to by *ppxIdleTaskStackBuffer.
    Note that, as the array is necessarily of type StackType_t,
    configMINIMAL_STACK_SIZE is specified in words, not bytes. */
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}