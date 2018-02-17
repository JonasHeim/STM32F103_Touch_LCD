/*
 * spi.c
 *
 *  Created on: 29.10.2017
 *      Author: forcexx
 */

#include <spi.h>

void spi_init() {

	/*
	 *
	 *  Touchscreen SPI1
	 *
	 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);

	SPI_InitTypeDef spi_init_struct;
	SPI_StructInit(&spi_init_struct);

	spi_init_struct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;
	spi_init_struct.SPI_CPHA = SPI_CPHA_1Edge;
	spi_init_struct.SPI_CPOL = SPI_CPOL_Low;
	spi_init_struct.SPI_DataSize = SPI_DataSize_8b;
	spi_init_struct.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	spi_init_struct.SPI_FirstBit = SPI_FirstBit_MSB;
	spi_init_struct.SPI_Mode = SPI_Mode_Master;
	spi_init_struct.SPI_NSS = SPI_NSS_Soft;
	spi_init_struct.SPI_CRCPolynomial = 7;

	SPI_Init(SPI1, &spi_init_struct);

	SPI_CalculateCRC(SPI1, DISABLE);

	SPI_Cmd(SPI1, ENABLE);

	/* Enable DMA events for RX/TX */
	SPI_I2S_DMACmd(SPI1, SPI_I2S_DMAReq_Rx, ENABLE);
	SPI_I2S_DMACmd(SPI1, SPI_I2S_DMAReq_Tx, ENABLE);

	/*
	 *
	 *  LCD SPI3
	 *
	 */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);

	SPI_StructInit(&spi_init_struct);

	spi_init_struct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_64;
	spi_init_struct.SPI_CPHA = SPI_CPHA_1Edge;
	spi_init_struct.SPI_CPOL = SPI_CPOL_Low;
	spi_init_struct.SPI_DataSize = SPI_DataSize_8b;
	spi_init_struct.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	spi_init_struct.SPI_FirstBit = SPI_FirstBit_MSB;
	spi_init_struct.SPI_Mode = SPI_Mode_Master;
	spi_init_struct.SPI_NSS = SPI_NSS_Soft;
	spi_init_struct.SPI_CRCPolynomial = 7;

	SPI_Init(SPI2, &spi_init_struct);

	SPI_CalculateCRC(SPI2, DISABLE);

	SPI_Cmd(SPI2, ENABLE);
}


