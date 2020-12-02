/**
  ******************************************************************************
  * @file    RTS_DS3231.c
  * @author  Zaznov NIIKP
  * @version V1.0.0
  * @date    00/00/2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the RTS_DS3231-driver:           
  *           + ...
  *           + ...
  *           + ...
  ******************************************************************************
  * FILE RTS_DS3231.c
  */
/* Includes ------------------------------------------------------------------*/
#include "RTS_DS3231.h"

/* Defines -------------------------------------------------------------------*/ 

/* Variables -----------------------------------------------------------------*/
uint8_t aRT_Buffer[8] = {0,0,0,0,0,0,0,0};
/* Functions -----------------------------------------------------------------*/

uint8_t RTC_Convert_to_Dec(uint8_t c)
{
	uint8_t ch = ((c>>4)*10+(0x0F&c));
	return ch;
}
uint8_t RTC_Convert_to_BinDec(uint8_t c)
{
	uint8_t ch = ((c/10)<<4)|(c%10);
	return ch;
}

void I2C_WriteBuffer(I2C_HandleTypeDef hi, uint8_t DEV_ADDR, uint8_t sizebuf)
{
	while(HAL_I2C_Master_Transmit(&hi, (uint16_t) DEV_ADDR, (uint8_t*) &aRT_Buffer, (uint16_t) sizebuf, (uint32_t)1000)!=HAL_OK)
	{
			/*if(HAL_I2C_GetError(&hi)!=HAL_I2C_ERROR_AF)
			{
			}*/
	}
}

void I2C_ReadBuffer(I2C_HandleTypeDef hi, uint8_t DEV_ADDR, uint8_t sizebuf)
{
	while(HAL_I2C_Master_Receive(&hi, (uint16_t) DEV_ADDR, (uint8_t*) &aRT_Buffer, (uint16_t) sizebuf, (uint32_t)1000)!=HAL_OK)
	{
			/*if(HAL_I2C_GetError(&hi)!=HAL_I2C_ERROR_AF)
			{
			}*/
	}
}

/************************* 2020 Zaznov NIIKP ***********************************
*
* END OF FILE RTS_DS3231.c */
