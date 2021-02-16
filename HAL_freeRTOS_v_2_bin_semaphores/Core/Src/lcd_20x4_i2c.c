/**
  ******************************************************************************
  * @file    lcd_20x4_i2c.c
  * @author  Zaznov NIIKP
  * @version V2.0.0
  * @date    29/10/2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the lcd_20x4-driver:           
  *           + ...
  *           + ...
  *           + ...
  ******************************************************************************
  * FILE lcd_20x4_i2c.c
  */
/* Includes ------------------------------------------------------------------*/
#include "lcd_20x4_i2c.h"

/* Defines -------------------------------------------------------------------*/ 

/* Variables -----------------------------------------------------------------*/
uint8_t buf[1] = {0};
char str1[100];
uint8_t portlcd;                                                                //€чейка дл€ хранени€ данных порта микросхемы расширени€
extern I2C_HandleTypeDef hi2c1;

/* Functions -----------------------------------------------------------------*/
/*
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
    
        LCD_Command(0x28);          //режим 4 бит, 2 линии (дл€ нашего большого диспле€ это 4 линии), шрифт 5х8
        HAL_Delay(1);
        LCD_Command(0x28);          //еще раз дл€ верности
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
    while(str[i])
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
*/
/* Functions for i2c ---------------------------------------------------------*/
void LCD_Write_Data_I2C(uint8_t data)
{
    buf[0] = data;   
    HAL_I2C_Master_Transmit(&hi2c1, (uint16_t)0x4E, buf, 1,1000);
}

__STATIC_INLINE void DelayMicro(__IO uint32_t micros)
{
	micros *=(SystemCoreClock / 1000000) / 5;
	while (micros--);
}

void sendhalfbyte(uint8_t c)
{
	c<<=4;
	e1_strob_hold();//включаем линию E
	DelayMicro(50);
	LCD_Write_Data_I2C(portlcd|c);
	e0_strob_write();//выключаем линию E
	DelayMicro(50);
}

void sendbyte(uint8_t c, uint8_t mode)
{
	if(mode==0) rs0_now_command();
	else rs1_now_data();
	uint8_t hc=0;
	hc=c>>4;
	sendhalfbyte(hc);
    sendhalfbyte(c);
}

void LCD_Clear(void)
{
	sendbyte(0x01,0);
	HAL_Delay(2);
}

void LCD_SendChar(char ch)
{
	sendbyte(ch,1);
}

void LCD_String(char* st)
{
	uint8_t i=0;
	while(st[i]!=0)
	{
		sendbyte(st[i],1);
		i++;
	}
}

void LCD_Set_Position(int8_t X, int8_t Y)
{
	switch(Y)
	{
		case 0:
			sendbyte(X|0x80,0);
			HAL_Delay(1);
			break;
		case 1:
			sendbyte((0x40+X)|0x80,0);
			HAL_Delay(1);
			break;
		case 2:
			sendbyte((0x14+X)|0x80,0);
			HAL_Delay(1);
			break;
		case 3:
			sendbyte((0x54+X)|0x80,0);
			HAL_Delay(1);
			break;
	}
}

void LCD_init(void)
{
	HAL_Delay(15);
	sendhalfbyte(0x03);
	HAL_Delay(4);
	sendhalfbyte(0x03);
	DelayMicro(100);
	sendhalfbyte(0x03);
	HAL_Delay(1);
	sendhalfbyte(0x02);
	HAL_Delay(1);
	sendbyte(0x28,0);//режим 4 бит, 2 линии (дл€ нашего большого диспле€ это 4 линии, шрифт 5х8	
	HAL_Delay(1);
	sendbyte(0x0C,0);//дисплей включаем (D=1), курсоры никакие не нужны
	HAL_Delay(1);
	sendbyte(0x01,0);//уберем мусор
	HAL_Delay(2);
	sendbyte(0x06,0);//пишем влево
	HAL_Delay(1);
	setled();//подсветка
	setwrite();//запись
}



/************************* 2020 Zaznov NIIKP ***********************************
*
* END OF FILE lcd_20x4_i2c.c */
