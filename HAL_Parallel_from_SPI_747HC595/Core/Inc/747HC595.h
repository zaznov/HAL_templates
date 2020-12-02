/**
  ******************************************************************************
  * @file    747HC595.h
  * @author  Zaznov NIIKP
  * @version V1.0.0
  * @date    00/00/2020
  * @brief   This file contains all the functions prototypes for work with...
  To view Datasheet visit:
  https:....
  ******************************************************************************
  * FILE 747HC595.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __747HC595_H_
#define __747HC595_H_
/* Includes ------------------------------------------------------------------*/ 
#include "stm32f4xx_hal.h"
/* defines -------------------------------------------------------------------*/  
#define cs_reset()  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_RESET)
#define cs_set()    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_SET)
/* Variables -----------------------------------------------------------------*/

/* Functions -----------------------------------------------------------------*/

#endif /* __747HC595_H_ */

/************************* 2020 Zaznov NIIKP ***********************************
*
* END OF FILE 747HC595.h */

