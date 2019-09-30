#include "bsp_lcd.h"

/**
 * @brief LED variables
 */
GPIO_TypeDef*   LED_PORT[LEDn] = {LED0_GPIO_PORT};

const uint16_t  LED_PIN[LEDn]  = {LED0_PIN};

/**
 * @brief COM variables
 */
USART_TypeDef* COM_USART[COMn]   = {USER_COM0}; 

GPIO_TypeDef* COM_TX_PORT[COMn]   = {USER_COM0_TX_GPIO_PORT};
 
GPIO_TypeDef* COM_RX_PORT[COMn]   = {USER_COM0_RX_GPIO_PORT};

const uint16_t COM_TX_PIN[COMn]   = {USER_COM0_TX_PIN};

const uint16_t COM_RX_PIN[COMn]   = {USER_COM0_RX_PIN};

/**
 * @brief SPI variables
 */
SPI_TypeDef* Bsp_Spi[SPIn]   = {USER_SPI0}; 

GPIO_TypeDef* SPI_MOSI_PORT[SPIn]   = {USER_SPI0_MOSI_GPIO_PORT};
 
GPIO_TypeDef* SPI_MISO_PORT[SPIn]   = {USER_SPI0_MISO_GPIO_PORT};

GPIO_TypeDef* SPI_SCK_PORT[SPIn]   = {USER_SPI0_SCK_GPIO_PORT};

GPIO_TypeDef* SPI_CS_PORT[SPIn]   = {USER_SPI0_CS_GPIO_PORT};

const uint16_t SPI_MOSI_PIN[SPIn]   = {USER_SPI0_MOSI_PIN};

const uint16_t SPI_MISO_PIN[SPIn]   = {USER_SPI0_MISO_PIN};

const uint16_t SPI_SCK_PIN[SPIn]    = {USER_SPI0_SCK_PIN};

const uint16_t SPI_CS_PIN[SPIn]    = {USER_SPI0_CS_PIN};

/**
  * @brief  Configures LED GPIO.
  * @param  Led: Specifies the Led to be configured. 
  *   This parameter can be one of following parameters:
  *     @arg LED0/LED_RED
  *     @arg LED1/LED_GREEN
  */
void BSP_LED_Init(Bsp_Led_TypeDef Led)
{
    GPIO_InitTypeDef  gpioinitstruct = {0};

    /* Enable the GPIO_LED Clock */
    LEDx_GPIO_CLK_ENABLE(Led);

    /* Configure the GPIO_LED pin */
    gpioinitstruct.Pin    = LED_PIN[Led];
    gpioinitstruct.Mode   = GPIO_MODE_OUTPUT_PP;
    gpioinitstruct.Pull   = GPIO_PULLDOWN;
    gpioinitstruct.Speed  = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(LED_PORT[Led], &gpioinitstruct);
}


void BSP_LED_On(Bsp_Led_TypeDef Led)
{
    HAL_GPIO_WritePin(LED_PORT[Led], LED_PIN[Led], GPIO_PIN_SET);
}

void BSP_LED_Off(Bsp_Led_TypeDef Led)
{
    HAL_GPIO_WritePin(LED_PORT[Led], LED_PIN[Led], GPIO_PIN_RESET);
}

void BSP_LED_Toggle(Bsp_Led_TypeDef Led)
{
    HAL_GPIO_TogglePin(LED_PORT[Led], LED_PIN[Led]);
}

HAL_StatusTypeDef BSP_COM_Init(Bsp_COM_TypeDef Com, UART_HandleTypeDef *huart)
{
    HAL_StatusTypeDef ret_val = HAL_ERROR;
    GPIO_InitTypeDef  gpioinitstruct = {0};

    COMx_TX_GPIO_CLK_ENABLE(Com);
    COMx_RX_GPIO_CLK_ENABLE(Com);

    COMx_CLK_ENABLE(Com);

    /* Configure UART Tx as AF PP */
    gpioinitstruct.Pin      = COM_TX_PIN[Com];
    gpioinitstruct.Mode     = GPIO_MODE_AF_PP;
    gpioinitstruct.Speed    = GPIO_SPEED_FREQ_HIGH;
    gpioinitstruct.Pull     = GPIO_PULLUP;
    HAL_GPIO_Init(COM_TX_PORT[Com], &gpioinitstruct);

    /* Configure UART Rx as AF PP */
    gpioinitstruct.Pin      = COM_RX_PIN[Com];
    gpioinitstruct.Mode     = GPIO_MODE_AF_INPUT;
    HAL_GPIO_Init(COM_RX_PORT[Com], &gpioinitstruct);

    huart->Instance         = COM_USART[Com];
    ret_val = HAL_UART_Init(huart);
    return ret_val;
}

size_t strlen(char* string)
{
    size_t retval = 0;

    if(NULL != string)
    {
        for(int i = 0; ;i++)
        {
            if(string[i] == '\0')
            {
                //found string termination
                break;
            }
            retval++;
        }
    }
    return retval;
}

HAL_StatusTypeDef BSP_COM_Print(UART_HandleTypeDef *huart, char *pData)
{
    HAL_StatusTypeDef ret_val = HAL_ERROR;
    if(pData)
    {
        if(strlen(pData))
        {
            ret_val = HAL_UART_Transmit(huart, (unsigned char*) pData, strlen(pData), 1000);
        }
    }

    return ret_val;
}

HAL_StatusTypeDef BSP_SPI_Init(Bsp_SPI_TypeDef Spi, SPI_HandleTypeDef *hspi)
{
    HAL_StatusTypeDef ret_val = HAL_ERROR;

    if(hspi)
    {
            GPIO_InitTypeDef  gpioinitstruct = {0};

        SPIx_MOSI_GPIO_CLK_ENABLE(Spi);
        SPIx_MISO_GPIO_CLK_ENABLE(Spi);
        SPIx_SCK_GPIO_CLK_ENABLE(Spi);
        SPIx_CS_GPIO_CLK_ENABLE(Spi);

        SPIx_CLK_ENABLE(Spi);

        /* Configure SPI MOSI as AF PP */
        gpioinitstruct.Pin      = SPI_MOSI_PIN[Spi];
        gpioinitstruct.Mode     = GPIO_MODE_AF_PP;
        gpioinitstruct.Speed    = GPIO_SPEED_FREQ_HIGH;
        gpioinitstruct.Pull     = GPIO_PULLUP;
        HAL_GPIO_Init(SPI_MOSI_PORT[Spi], &gpioinitstruct);

        /* Configure SPI MISO as AF PP */
        gpioinitstruct.Pin      = SPI_MISO_PIN[Spi];
        gpioinitstruct.Mode     = GPIO_MODE_AF_INPUT;
        gpioinitstruct.Speed    = GPIO_SPEED_FREQ_HIGH;
        gpioinitstruct.Pull     = GPIO_PULLUP;
        HAL_GPIO_Init(SPI_MISO_PORT[Spi], &gpioinitstruct);

        /* Configure SPI SCK as AF PP */
        gpioinitstruct.Pin      = SPI_SCK_PIN[Spi];
        gpioinitstruct.Mode     = GPIO_MODE_AF_PP;
        gpioinitstruct.Speed    = GPIO_SPEED_FREQ_HIGH;
        gpioinitstruct.Pull     = GPIO_PULLUP;
        HAL_GPIO_Init(SPI_SCK_PORT[Spi], &gpioinitstruct);

        /* Configure SPI CS as AF PP */
        gpioinitstruct.Pin      = SPI_CS_PIN[Spi];
        gpioinitstruct.Mode     = GPIO_MODE_AF_PP;
        gpioinitstruct.Speed    = GPIO_SPEED_FREQ_HIGH;
        gpioinitstruct.Pull     = GPIO_PULLUP;
        HAL_GPIO_Init(SPI_CS_PORT[Spi], &gpioinitstruct);

        hspi->Instance         = Bsp_Spi[Spi];
        ret_val = HAL_SPI_Init(hspi);
    }

    return ret_val;
}