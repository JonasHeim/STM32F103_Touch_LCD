/*
 * dma.h
 *
 *  Created on: 31.10.2017
 *      Author: forcexx
 */

#ifndef DMA_H_
#define DMA_H_

#include <stm32f10x_dma.h>

#define DMA_SPI_RECEIVE_COUNT	3
#define DMA_SPI_TRANSMIT_COUNT	3

#define DMA_SPI_RCC	RCC_AHBPeriph_DMA1

#define DMA_SPI_RX_CHANNEL	DMA1_Channel2
#define DMA_SPI_TX_CHANNEL	DMA1_Channel3

/*
 * Initializes direct memory address (dma)
 */
void dma_init(void);
void dma_set_spi_rx(FunctionalState state);
void dma_set_spi_tx(FunctionalState state);
void dma_reset_spi_tx(void);

extern volatile uint8_t dma_spi_touchscreen_rx_buffer[DMA_SPI_RECEIVE_COUNT];
extern volatile uint8_t dma_spi_touchscreen_tx_buffer[DMA_SPI_TRANSMIT_COUNT];

#endif /* DMA_H_ */
