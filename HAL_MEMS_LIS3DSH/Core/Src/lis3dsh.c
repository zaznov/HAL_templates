/**
  ******************************************************************************
  * @file    lis3dsh.c
  * @author  Zaznov NIIKP
  * @version V1.0.0
  * @date    10/12/2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the LIS3DSH-driver:           
  *           + Initialisation
  *           + Measurements of X, Y and Z values
  *           + Showing incline with leds blinking function
  *         Work goes through SPI1;
  ******************************************************************************
  * FILE lis3dsh.c
  */
/* Includes ------------------------------------------------------------------*/
#include "lis3dsh.h"
extern SPI_HandleTypeDef hspi1;
/* Defines -------------------------------------------------------------------*/ 

/* Variables -----------------------------------------------------------------*/

/* Functions -----------------------------------------------------------------*/
static uint8_t lis3dsh_spi_read_write_byte(uint8_t byte_to_transmit);
static void lis3dsh_spi_read(uint8_t *pBuffer, uint8_t ReadAddr, uint16_t NumByteToRead);
static void lis3dsh_spi_write(uint8_t *pBuffer, uint8_t WriteAddr, uint16_t NumByteToWrite);
static uint8_t lis3dsh_readID(void);

uint8_t lis3dsh_spi_read_write_byte(uint8_t byte_to_transmit)
{
    uint8_t byte_to_recive = 0;
    if(HAL_SPI_TransmitReceive(&hspi1, &byte_to_transmit, &byte_to_recive, 1, 1000) != HAL_OK)
    {
        LD5_RED_ON();
    }
    return byte_to_recive;
}

void lis3dsh_spi_read(uint8_t *pBuffer, uint8_t ReadAddr, uint16_t NumByteToRead)
{
    if(NumByteToRead > 0x01)    (ReadAddr |= (uint8_t) (READ_CMD | MULTIPLEBYTE_CMD));  // Multiple bytes reading
	else                        (ReadAddr |= (uint8_t)  READ_CMD);                      // or Single bytes reading
    
    CS_DOWN();                                                                  // Chip select of SPI
	lis3dsh_spi_read_write_byte(ReadAddr);                                      // Set address to read
	while(NumByteToRead > 0)
	{
		*pBuffer++ =lis3dsh_spi_read_write_byte(DUMMY_BYTE);                    // read in Buffer
		NumByteToRead--;
	}
	CS_UP();                                                                    // Chip select of SPI
}

void lis3dsh_spi_write(uint8_t *pBuffer, uint8_t WriteAddr, uint16_t NumByteToWrite)
{
	if(NumByteToWrite > 0x01) (WriteAddr |= (uint8_t) MULTIPLEBYTE_CMD);
    
	CS_DOWN();                                                                  // Chip select of SPI
	lis3dsh_spi_read_write_byte(WriteAddr);                                     // Set address to write
	while(NumByteToWrite > 0)
	{
		lis3dsh_spi_read_write_byte(*pBuffer++);                                // write from Buffer
		NumByteToWrite--;
	}
	CS_UP();                                                                    // Chip select of SPI
}

uint8_t lis3dsh_readID(void)
{  
    uint8_t register_value = 0;
	lis3dsh_spi_read(&register_value,WHO_AM_I_REG_ADDR,1);                      // Read ID of LIS3DSH from WHO_AM_I register
	return register_value;
}



void lis3dsh_ini(void)
{
	if(lis3dsh_readID() == WHO_AM_I_REG_VALUE)    LD4_GREEN_ON();               // Read its ID
	else                                          LD5_RED_ON();                 // if something wrong turn on RED LD
    
    uint8_t settings_value = 0x00;
    settings_value = (LIS3DSH_DATARATE_100 | LIS3DSH_XYZ_ENABLE);
    lis3dsh_spi_write(&settings_value, LIS3DSH_CTRL_REG4_ADDR,1);               // Put settings in REG4
    
	settings_value = (LIS3DSH_SERIALINTERFACE_4WIRE | LIS3DSH_SELFTEST_NORMAL | LIS3DSH_FULLSCALE_2 | LIS3DSH_FILTER_BW_800);
    lis3dsh_spi_write(&settings_value, LIS3DSH_CTRL_REG5_ADDR,1);               // Put settings in REG5
	
    LD6_BLUE_ON();                                                              //Just confirmation, that we finised, turn on BLUE LD
}


void lis3dsh_get_XYZ(int16_t* pData)
{
	int8_t buffer[6];
	float sensitivity = LIS3DSH_SENSITIVITY_0_06G;

	lis3dsh_spi_read((uint8_t*)&buffer[0], LIS3DSH_OUT_X_L_ADDR,1);
	lis3dsh_spi_read((uint8_t*)&buffer[1], LIS3DSH_OUT_X_H_ADDR,1);
	lis3dsh_spi_read((uint8_t*)&buffer[2], LIS3DSH_OUT_Y_L_ADDR,1);
	lis3dsh_spi_read((uint8_t*)&buffer[3], LIS3DSH_OUT_Y_H_ADDR,1);
	lis3dsh_spi_read((uint8_t*)&buffer[4], LIS3DSH_OUT_Z_L_ADDR,1);
	lis3dsh_spi_read((uint8_t*)&buffer[5], LIS3DSH_OUT_Z_H_ADDR,1);
    
	for(uint8_t i=0;i<3;i++)
	{
		pData[i]=(int16_t)(((buffer[2*i+1] << 8) + buffer[2*i])*sensitivity);   //Creating a Buffer with measurements of X, Y and Z
	}
}


void lis3dsh_show_incline_with_leds(void)
{
	int16_t buffer[3]={0};
	int16_t xval, yval,zval = 0x0000;
	lis3dsh_get_XYZ(buffer);
	xval=buffer[0];
	yval=buffer[1];
	zval=buffer[2];
		if(xval>200)
		{
			LD5_RED_ON();
		}
		else if(xval<-200)
		{
			LD4_GREEN_ON();
		}
		if(yval>200)
		{
			LD3_ORANGE_ON();
		}
		else if(yval< -200)
		{
			LD6_BLUE_ON();
		}
	HAL_Delay(20);
	LD3_ORANGE_OFF();
	LD4_GREEN_OFF();
	LD5_RED_OFF();
	LD6_BLUE_OFF();
}
/************************* 2020 Zaznov NIIKP ***********************************
*
* END OF FILE lis3dsh.c */
