/*
 * dma.c
 *
 *  Created on: 31.10.2017
 *      Author: forcexx
 */

#include <dma.h>
volatile uint8_t dma_spi_touchscreen_rx_buffer[DMA_SPI_RECEIVE_COUNT] = { 0x0 };
volatile uint8_t dma_spi_touchscreen_tx_buffer[DMA_SPI_RECEIVE_COUNT] = { 0x92,
		0x0, 0x0 };

void dma_init() {

	/*
	 * DMA for SPI1 touchscreen RX
	 */

	RCC_AHBPeriphClockCmd(DMA_SPI_RCC, ENABLE);

	DMA_InitTypeDef dma_init_struct;

	DMA_StructInit(&dma_init_struct);

	dma_init_struct.DMA_BufferSize = DMA_SPI_RECEIVE_COUNT;
	dma_init_struct.DMA_DIR = DMA_DIR_PeripheralSRC;
	dma_init_struct.DMA_M2M = DMA_M2M_Disable;
	dma_init_struct.DMA_MemoryBaseAddr =
			(uint32_t) dma_spi_touchscreen_rx_buffer;
	dma_init_struct.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	dma_init_struct.DMA_MemoryInc = DMA_MemoryInc_Enable;
	dma_init_struct.DMA_Mode = DMA_Mode_Circular;
	dma_init_struct.DMA_PeripheralBaseAddr = (uint32_t) (&(SPI1->DR));
	dma_init_struct.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	dma_init_struct.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	dma_init_struct.DMA_Priority = DMA_Priority_Medium;

	DMA_Init(DMA_SPI_RX_CHANNEL, &dma_init_struct);

	dma_set_spi_rx(ENABLE);

	/*
	 * DMA for SPI1 touchscreen TX
	 */

	dma_init_struct.DMA_BufferSize = DMA_SPI_TRANSMIT_COUNT;
	dma_init_struct.DMA_DIR = DMA_DIR_PeripheralDST;
	dma_init_struct.DMA_M2M = DMA_M2M_Disable;
	dma_init_struct.DMA_MemoryBaseAddr =
			(uint32_t) dma_spi_touchscreen_tx_buffer;
	dma_init_struct.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	dma_init_struct.DMA_MemoryInc = DMA_MemoryInc_Enable;
	dma_init_struct.DMA_Mode = DMA_Mode_Normal;
	dma_init_struct.DMA_PeripheralBaseAddr = (uint32_t) (&(SPI1->DR));
	dma_init_struct.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	dma_init_struct.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	dma_init_struct.DMA_Priority = DMA_Priority_Medium;

	DMA_Init(DMA_SPI_TX_CHANNEL, &dma_init_struct);

}

void dma_set_spi_rx(FunctionalState state) {
	DMA_Cmd(DMA_SPI_RX_CHANNEL, state);
}

void dma_set_spi_tx(FunctionalState state) {
	DMA_Cmd(DMA_SPI_TX_CHANNEL, state);
}

void dma_reset_spi_tx(void) {
	/* Disable the DMA channel */
	dma_set_spi_tx(DISABLE);

	/* Reset transmitted bytes; reset to memory base address */
	DMA_SetCurrDataCounter(DMA_SPI_TX_CHANNEL, DMA_SPI_TRANSMIT_COUNT);
}
