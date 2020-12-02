/**
  ******************************************************************************
  * @file    max7219.c
  * @author  Zaznov NIIKP
  * @version V1.0.0
  * @date    00/00/2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the max7219-driver:           
  *           + ...
  *           + ...
  *           + ...
  ******************************************************************************
  * FILE max7219.c
  */
/* Includes ------------------------------------------------------------------*/
#include "max7219.h"

/* Defines -------------------------------------------------------------------*/ 

/* Variables -----------------------------------------------------------------*/

/* Functions -----------------------------------------------------------------*/
void max_7219_send(uint8_t reg, uint8_t data)
{
    uint8_t Buf[1] = {0};
    cs_reset();
    Buf[0] = reg;
    HAL_SPI_Transmit(&hspi3, &Buf[0], 1, 1000);  
    Buf[0] = data;
    HAL_SPI_Transmit(&hspi3, &Buf[0], 1, 1000);  
    cs_set();
  
}

void max_7219_init(void)
{
    max_7219_send(DECODE_MODE, DECODE_MODE_ON);
    max_7219_send(SCAN_LIMIT, SCAN_LIMIT_8);
    max_7219_send(INTENSITY, INTENSITY_LOW);
    max_7219_send(SHUTDOWN, SHUTDOWN_OFF);
}

void max_7219_clear(void)
{
    uint8_t led_number = 8;
    while(led_number)
    {
        max_7219_send(led_number, LED_CLEAR);
        led_number--;
    }
}

void max_7219_write_number(int32_t number)
{
        uint8_t minus=0;                                                        //переменна€ дл€ минуса
        max_7219_clear();    
        if(number<0)
        {
            minus=1;
            number*=-1;
        }
        if(number==0)
        {
            max_7219_send(1,0);                                                 //в первый разр€д напишем 0
            return;
        }
        uint8_t led_number=0;
        do
        {
            max_7219_send(++led_number,number%10);
            number/=10;
        } while(number);
        if (minus)
        {
            max_7219_send(led_number+1,0xA);                                    //символ Ц
        } 
}

/************************* 2020 Zaznov NIIKP ***********************************
*
* END OF FILE max7219.c */
