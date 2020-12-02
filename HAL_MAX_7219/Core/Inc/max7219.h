/**
  ******************************************************************************
  * @file    max7219.h
  * @author  Zaznov NIIKP
  * @version V1.0.0
  * @date    00/00/2020
  * @brief   This file contains all the functions prototypes for work with...
  To view Datasheet visit:
  https:....
  ******************************************************************************
  * FILE max7219.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAX_7219_H_
#define __MAX_7219_H_
/* Includes ------------------------------------------------------------------*/ 
#include "stm32f4xx_hal.h"
#include "spi.h"
/* defines -------------------------------------------------------------------*/  

#define DECODE_MODE     0x9
#define INTENSITY       0xA
#define SCAN_LIMIT      0xB
#define SHUTDOWN        0xC
#define DISPLAY_TEST    0xD

#define DECODE_MODE_ON  0xFF
#define INTENSITY_LOW   0x02
#define SCAN_LIMIT_8    7
#define SHUTDOWN_OFF    0x01
#define DISPLAY_TEST_WRITE 0x01
#define LED_CLEAR       0x7F


#define cs_reset()  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_RESET)
#define cs_set()    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_SET)
/* Variables -----------------------------------------------------------------*/

/* Functions -----------------------------------------------------------------*/
void max_7219_send (uint8_t reg, uint8_t data);
void max_7219_init(void);
void max_7219_clear(void);
void max_7219_write_number(int32_t number);
#endif /* __MAX_7219_H_ */

/************************* 2020 Zaznov NIIKP ***********************************
*
* END OF FILE max7219.h */

