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

typedef enum 
{
  LED0 = 0,
  LED_GREEN = LED0
} Led_TypeDef;

/**
 * @brief COM Types Definition
 */
typedef enum 
{
  COM0 = 0,
} COM_TypeDef;

#define LEDn                             1

#define LED0_PIN                         GPIO_PIN_13
#define LED0_GPIO_PORT                   GPIOC
#define LED0_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOC_CLK_ENABLE()  
#define LED0_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOC_CLK_DISABLE()  

#define LEDx_GPIO_CLK_ENABLE(__INDEX__)   LED0_GPIO_CLK_ENABLE()

#define LEDx_GPIO_CLK_DISABLE(__INDEX__)  LED0_GPIO_CLK_DISABLE()

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

void BSP_LED_Init(Led_TypeDef Led);
void BSP_LED_On(Led_TypeDef Led);
void BSP_LED_Off(Led_TypeDef Led);
void BSP_LED_Toggle(Led_TypeDef Led);

HAL_StatusTypeDef BSP_COM_Init(COM_TypeDef Com, UART_HandleTypeDef *huart);
HAL_StatusTypeDef BSP_COM_Print(UART_HandleTypeDef *huart, char  *pData);

/**
  * @}
  */ 
  
#ifdef __cplusplus
}
#endif
  
#endif /* __CANWAKEUP_H */
