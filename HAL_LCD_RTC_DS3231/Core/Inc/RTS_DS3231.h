/**
  ******************************************************************************
  * @file    RTS_DS3231.h
  * @author  Zaznov NIIKP
  * @version V1.0.0
  * @date    00/00/2020
  * @brief   This file contains all the functions prototypes for work with...
  To view Datasheet visit:
  https:....
  ******************************************************************************
  * FILE RTS_DS3231.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __RTS_DS3231_H_
#define __RTS_DS3231_H_
/* Includes ------------------------------------------------------------------*/ 
#include "stm32f4xx_hal.h"
/* defines -------------------------------------------------------------------*/  

/* Variables -----------------------------------------------------------------*/
extern uint8_t aRT_Buffer[8];
/* Functions -----------------------------------------------------------------*/
uint8_t RTC_Convert_to_Dec(uint8_t c);
uint8_t RTC_Convert_to_BinDec(uint8_t c);

void I2C_WriteBuffer(I2C_HandleTypeDef hi, uint8_t DEV_ADDR, uint8_t sizebuf);
void I2C_ReadBuffer(I2C_HandleTypeDef hi, uint8_t DEV_ADDR, uint8_t sizebuf);
#endif /* __RTS_DS3231_H_ */

/************************* 2020 Zaznov NIIKP ***********************************
*
* END OF FILE RTS_DS3231.h */

