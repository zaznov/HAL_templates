/**
  ******************************************************************************
  * @file    lcd_20x4.h
  * @author  Zaznov NIIKP
  * @version V1.0.0
  * @date    00/00/2020
  * @brief   This file contains all the functions prototypes for work with...
  To view Datasheet visit:
  https:....
  ******************************************************************************
  * FILE lcd_20x4.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LCD_20X4_H_
#define __LCD_20X4_H_
/* Includes ------------------------------------------------------------------*/ 
#include "stm32f4xx_hal.h"
/* defines -------------------------------------------------------------------*/  
#define d4_set()    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET)
#define d5_set()    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET)
#define d6_set()    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_SET)
#define d7_set()    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_SET)
#define d4_reset()  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET)
#define d5_reset()  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET)
#define d6_reset()  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_RESET)
#define d7_reset()  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_RESET)

 

#define e1_strob_hold()     HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET)          // установка линии E в 1
#define e0_strob_write()    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET)        // установка линии E в 0
#define rs1_now_data()      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET)          // установка линии RS в 1 (данные)
#define rs0_now_command()   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET)        // установка линии RS в 0 (команда)
/* Variables -----------------------------------------------------------------*/

/* Functions -----------------------------------------------------------------*/
void LCD_init(void);
void LCD_Write_Half_Data(uint8_t data);
void short_delay(void);
void LCD_Command(uint8_t data);
void LCD_Data(uint8_t data);
void LCD_Clear(void);
void LCD_Send_Data(char ch);
void LCD_String(char* str);
void LCD_Set_Position(int8_t X, int8_t Y);
#endif /* __LCD_20X4_H_ */

/************************* 2020 Zaznov NIIKP ***********************************
*
* END OF FILE lcd_20x4.h */

