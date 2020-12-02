/**
  ******************************************************************************
  * @file    lcd_20x4.c
  * @author  Zaznov NIIKP
  * @version V2.0.0
  * @date    29/10/2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the lcd_20x4-driver:           
  *           + ...
  *           + ...
  *           + ...
  ******************************************************************************
  * FILE lcd_20x4.c
  */
/* Includes ------------------------------------------------------------------*/
#include "lcd_20x4.h"

/* Defines -------------------------------------------------------------------*/ 

/* Variables -----------------------------------------------------------------*/

/* Functions -----------------------------------------------------------------*/
void LCD_init(void)

{
        HAL_Delay(40);
        rs0_now_command();
        e1_strob_hold();
        LCD_Write_Half_Data(3);
        short_delay();
        e0_strob_write();
        short_delay();
        HAL_Delay(5);
        e1_strob_hold();
        LCD_Write_Half_Data(3);
        short_delay();
        e0_strob_write();
        short_delay();
        HAL_Delay(5);
        e1_strob_hold();
        LCD_Write_Half_Data(3);
        short_delay();
        e0_strob_write();
        short_delay();
        HAL_Delay(1);
    
        LCD_Command(0x28);          //режим 4 бит, 2 линии (для нашего большого дисплея это 4 линии), шрифт 5х8
        HAL_Delay(1);
        LCD_Command(0x28);          //еще раз для верности
        HAL_Delay(1);
        LCD_Command(0x0C);          //дисплей включаем (D=1), также включаем пока все курсоры
        HAL_Delay(1);
        LCD_Command(0x01);          //уберем мусор
        HAL_Delay(2);
        LCD_Command(0x06);          //пишем влево
        HAL_Delay(1);
        LCD_Command(0x02);          //возврат курсора в нулевое положение
        HAL_Delay(2);
}

void LCD_Write_Half_Data(uint8_t data)
{
        if((data >> 3)&0x01)   {d7_set();} else {d7_reset();}
        if((data >> 2)&0x01)   {d6_set();} else {d6_reset();}
        if((data >> 1)&0x01)   {d5_set();} else {d5_reset();}
        if(data&0x01)          {d4_set();} else {d4_reset();}
}

void short_delay(void)

{
        uint32_t i;
        for(i=0;i<100;i++);
}

void LCD_Command(uint8_t data)
{

        rs0_now_command();
    
        e1_strob_hold();
        LCD_Write_Half_Data(data>>4);
        short_delay();
        e0_strob_write();
        short_delay();
    
        e1_strob_hold();
        LCD_Write_Half_Data(data);
        short_delay();
        e0_strob_write();
        short_delay();
}

void LCD_Data(uint8_t data)
{
        rs1_now_data();
    
        e1_strob_hold();
        LCD_Write_Half_Data(data>>4);
        short_delay();
        e0_strob_write();
        short_delay();
    
        e1_strob_hold();
        LCD_Write_Half_Data(data);
        short_delay();
        e0_strob_write();
        short_delay();
}

void LCD_Clear(void)
{
        LCD_Command(0x01);
        HAL_Delay(2);
}

void LCD_Send_Data(char ch)
{
        LCD_Data((uint8_t) ch);
        HAL_Delay(2);
}

void LCD_String(char* str)
{
    int8_t i = 0;
    while(str[i] && str[i] != '\r')
    {
        LCD_Send_Data(str[i]);
        i++;
    }
}

void LCD_Set_Position(int8_t x, int8_t y)
{
    switch(y)
    {
        case(0):
            LCD_Command(0x80 + 0x0 + x);
            break;
        case(1):
            LCD_Command(0x80 + 0x40 + x);
            break;
        case(2):
            LCD_Command(0x80 + 0x14 + x);
            break;
        case(3):
            LCD_Command(0x80 + 0x54 + x);
            break; 
    }    
    HAL_Delay(2);    
}



/************************* 2020 Zaznov NIIKP ***********************************
*
* END OF FILE lcd_20x4.c */
