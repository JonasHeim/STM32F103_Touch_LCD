/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CANWAKEUP_H
#define __CANWAKEUP_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/** @addtogroup BSP
  * @{
  */ 

/**
 * @brief LED Types Definition
 */
typedef enum 
{
  LED0 = 0,
  LED_GREEN = LED0
} Bsp_Led_TypeDef;

#define LEDn                             1

#define LED0_PIN                         GPIO_PIN_13
#define LED0_GPIO_PORT                   GPIOC
#define LED0_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOC_CLK_ENABLE()  
#define LED0_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOC_CLK_DISABLE()  

#define LEDx_GPIO_CLK_ENABLE(__INDEX__)   LED0_GPIO_CLK_ENABLE()

#define LEDx_GPIO_CLK_DISABLE(__INDEX__)  LED0_GPIO_CLK_DISABLE()

/**
 * @brief COM Types Definition
 */
typedef enum 
{
  COM0 = 0,
} Bsp_COM_TypeDef;

/** @addtogroup STM3210E_EVAL_COM
  * @{
  */
#define COMn                                1

/**
 * @brief Definition for COM port0, connected to USART1
 */ 
#define USER_COM0                           USART1
#define USER_COM0_CLK_ENABLE()              __HAL_RCC_USART1_CLK_ENABLE()
#define USER_COM0_CLK_DISABLE()             __HAL_RCC_USART1_CLK_DISABLE()

#define USER_COM0_TX_PIN                    GPIO_PIN_9
#define USER_COM0_TX_GPIO_PORT              GPIOA
#define USER_COM0_TX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOA_CLK_ENABLE()
#define USER_COM0_TX_GPIO_CLK_DISABLE()     __HAL_RCC_GPIOA_CLK_DISABLE()

#define USER_COM0_RX_PIN                    GPIO_PIN_10
#define USER_COM0_RX_GPIO_PORT              GPIOA
#define USER_COM0_RX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOA_CLK_ENABLE()
#define USER_COM0_RX_GPIO_CLK_DISABLE()     __HAL_RCC_GPIOA_CLK_DISABLE()

#define COMx_CLK_ENABLE(__INDEX__)          USER_COM0_CLK_ENABLE()
#define COMx_CLK_DISABLE(__INDEX__)         USER_COM0_CLK_DISABLE()

#define COMx_TX_GPIO_CLK_ENABLE(__INDEX__)  USER_COM0_TX_GPIO_CLK_ENABLE()

#define COMx_TX_GPIO_CLK_DISABLE(__INDEX__) USER_COM0_TX_GPIO_CLK_DISABLE()

#define COMx_RX_GPIO_CLK_ENABLE(__INDEX__)  USER_COM0_RX_GPIO_CLK_ENABLE()

#define COMx_RX_GPIO_CLK_DISABLE(__INDEX__) USER_COM0_RX_GPIO_CLK_DISABLE()

/**
 * @brief LED Types Definition
 */
typedef enum 
{
  BSP_SPI0 = 0
} Bsp_SPI_TypeDef;

/** @addtogroup STM3210E_EVAL_SPI
  * @{
  */
#define SPIn                                  1

/**
 * @brief Definition for SPI port0, connected to SPI1
 */ 
#define USER_SPI0                           SPI1
#define USER_SPI0_CLK_ENABLE()              __HAL_RCC_SPI1_CLK_ENABLE()
#define USER_SPI0_CLK_DISABLE()             __HAL_RCC_SPI1_CLK_DISABLE()

#define USER_SPI0_MOSI_PIN                  GPIO_PIN_7
#define USER_SPI0_MOSI_GPIO_PORT            GPIOA
#define USER_SPI0_MOSI_GPIO_CLK_ENABLE()    __HAL_RCC_GPIOA_CLK_ENABLE()
#define USER_SPI0_MOSI_GPIO_CLK_DISABLE()   __HAL_RCC_GPIOA_CLK_DISABLE()

#define USER_SPI0_MISO_PIN                  GPIO_PIN_6
#define USER_SPI0_MISO_GPIO_PORT            GPIOA
#define USER_SPI0_MISO_GPIO_CLK_ENABLE()    __HAL_RCC_GPIOA_CLK_ENABLE()
#define USER_SPI0_MISO_GPIO_CLK_DISABLE()   __HAL_RCC_GPIOA_CLK_DISABLE()

#define USER_SPI0_SCK_PIN                   GPIO_PIN_5
#define USER_SPI0_SCK_GPIO_PORT             GPIOA
#define USER_SPI0_SCK_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOA_CLK_ENABLE()
#define USER_SPI0_SCK_GPIO_CLK_DISABLE()    __HAL_RCC_GPIOA_CLK_DISABLE()

#define USER_SPI0_CS_PIN                    GPIO_PIN_4
#define USER_SPI0_CS_GPIO_PORT              GPIOA
#define USER_SPI0_CS_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOA_CLK_ENABLE()
#define USER_SPI0_CS_GPIO_CLK_DISABLE()     __HAL_RCC_GPIOA_CLK_DISABLE()

#define SPIx_CLK_ENABLE(__INDEX__)          USER_SPI0_CLK_ENABLE()
#define SPIx_CLK_DISABLE(__INDEX__)         USER_SPI0_CLK_DISABLE()

#define SPIx_MOSI_GPIO_CLK_ENABLE(__INDEX__)  USER_SPI0_MOSI_GPIO_CLK_ENABLE()

#define SPIx_MOSI_GPIO_CLK_DISABLE(__INDEX__) USER_SPI0_MOSI_GPIO_CLK_DISABLE()

#define SPIx_MISO_GPIO_CLK_ENABLE(__INDEX__)  USER_SPI0_MISO_GPIO_CLK_ENABLE()

#define SPIx_MISO_GPIO_CLK_DISABLE(__INDEX__) USER_SPI0_MISO_GPIO_CLK_DISABLE()

#define SPIx_SCK_GPIO_CLK_ENABLE(__INDEX__)  USER_SPI0_SCK_GPIO_CLK_ENABLE()

#define SPIx_SCK_GPIO_CLK_DISABLE(__INDEX__) USER_SPI0_SCK_GPIO_CLK_DISABLE()

#define SPIx_CS_GPIO_CLK_ENABLE(__INDEX__)  USER_SPI0_CS_GPIO_CLK_ENABLE()

#define SPIx_CS_GPIO_CLK_DISABLE(__INDEX__) USER_SPI0_CS_GPIO_CLK_DISABLE()

void BSP_LED_Init(Bsp_Led_TypeDef Led);
void BSP_LED_On(Bsp_Led_TypeDef Led);
void BSP_LED_Off(Bsp_Led_TypeDef Led);
void BSP_LED_Toggle(Bsp_Led_TypeDef Led);

HAL_StatusTypeDef BSP_COM_Init(Bsp_COM_TypeDef Com, UART_HandleTypeDef *huart);
HAL_StatusTypeDef BSP_COM_Print(UART_HandleTypeDef *huart, char  *pData);

HAL_StatusTypeDef BSP_SPI_Init(Bsp_SPI_TypeDef Spi, SPI_HandleTypeDef *spi);

/**
  * @}
  */ 
  
#ifdef __cplusplus
}
#endif
  
#endif /* __CANWAKEUP_H */
