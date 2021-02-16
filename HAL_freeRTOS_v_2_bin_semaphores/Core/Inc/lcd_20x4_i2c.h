/**
  ******************************************************************************
  * @file    lcd_20x4_i2c.h
  * @author  Zaznov NIIKP
  * @version V1.0.0
  * @date    00/00/2020
  * @brief   This file contains all the functions prototypes for work with...
  To view Datasheet visit:
  https:....
  ******************************************************************************
  * FILE lcd_20x4_i2c.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LCD_20X4_H_I2C
#define __LCD_20X4_H_I2C
/* Includes ------------------------------------------------------------------*/ 
#include "stm32f4xx_hal.h"
/* defines -------------------------------------------------------------------*/  
#define e1_strob_hold()     LCD_Write_Data_I2C(portlcd |= 0x04)                 // установка линии E в 1
#define e0_strob_write()    LCD_Write_Data_I2C(portlcd &= ~0x04)                // установка линии E в 0
#define rs1_now_data()      LCD_Write_Data_I2C(portlcd |= 0x01)                 // установка линии RS в 1 (данные)
#define rs0_now_command()   LCD_Write_Data_I2C(portlcd &= ~0x01)                // установка линии RS в 0 (команда)
#define setled()            LCD_Write_Data_I2C(portlcd |= 0x08)                 // установка 
#define setwrite()          LCD_Write_Data_I2C(portlcd &= ~0x02)                // установка 
/* Variables -----------------------------------------------------------------*/

/* Functions -----------------------------------------------------------------*/
    void LCD_init(void);
void short_delay(void);
void LCD_Command(uint8_t data);
void LCD_Data(uint8_t data);
    void LCD_Clear(void);
    void LCD_SendChar(char ch);
    void LCD_String(char* str);
    void LCD_Set_Position(int8_t X, int8_t Y);
/* Functions for I2C ---------------------------------------------------------*/
void LCD_Write_Data_I2C(uint8_t data);
#endif /* __LCD_20X4_H_I2C */

/************************* 2020 Zaznov NIIKP ***********************************
*
* END OF FILE lcd_20x4_i2c.h */

