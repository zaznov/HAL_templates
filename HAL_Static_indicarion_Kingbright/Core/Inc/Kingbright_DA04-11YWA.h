/**
  ******************************************************************************
  * @file    Kingbright_DA04-11YWA.h
  * @author  Zaznov NIIKP
  * @version V1.0.0
  * @date    00/00/2020
  * @brief   This file contains all the functions prototypes for work with...
  To view Datasheet visit:
  https:....
  ******************************************************************************
  * FILE Kingbright_DA04-11YWA.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef KINGBRIGHT_DA04
#define KINGBRIGHT_DA04
/* Includes ------------------------------------------------------------------*/ 
#include "gpio.h"
/* defines -------------------------------------------------------------------*/  
    #define a_on() HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET); 
    #define b_on() HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_RESET); 
    #define c_on() HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_RESET); 
    #define d_on() HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET); 
    #define e_on() HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET); 
    #define f_on() HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET); 
    #define g_on() HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET); 
    
    #define a_off() HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET); 
    #define b_off() HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET); 
    #define c_off() HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_SET); 
    #define d_off() HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET); 
    #define e_off() HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET); 
    #define f_off() HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET); 
    #define g_off() HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET);
    
/* Variables -----------------------------------------------------------------*/

/* Functions -----------------------------------------------------------------*/

void write_number(uint8_t number);

#endif /* KINGBRIGHT_DA04 */

/************************* 2020 Zaznov NIIKP ***********************************
*
* END OF FILE Kingbright_DA04-11YWA.h */

