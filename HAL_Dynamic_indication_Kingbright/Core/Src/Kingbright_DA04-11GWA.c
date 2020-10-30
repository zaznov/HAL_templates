/**
  ******************************************************************************
  * @file    Kingbright_DA04-11GWA.c
  * @author  Zaznov NIIKP
  * @version V1.0.0
  * @date    00/00/2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the Kingbright_DA04-11YWA-driver:           
  *           + ...
  *           + ...
  *           + ...
  ******************************************************************************
  * FILE Kingbright_DA04-11GWA.c
  */
/* Includes ------------------------------------------------------------------*/
#include "Kingbright_DA04-11GWA.h"

/* Defines -------------------------------------------------------------------*/ 

/* Variables -----------------------------------------------------------------*/

/* Functions -----------------------------------------------------------------*/
void write_number(uint8_t number)
{
    switch(number)
    {
        case 1:
            a_off();
            b_on();
            c_on();
            d_off();
            e_off();
            f_off();
            g_off();
            break;
        case 2:
            a_on();
            b_on();
            c_off();
            d_on();
            e_on();
            f_off();
            g_on();
            break;
        case 3:
            a_on();
            b_on();
            c_on();
            d_on();
            e_off();
            f_off();
            g_on();
            break;
        case 4:
            a_off();
            b_on();
            c_on();
            d_off();
            e_off();
            f_on();
            g_on();
            break;
        case 5:
            a_on();
            b_off();
            c_on();
            d_on();
            e_off();
            f_on();
            g_on();
            break;
        case 6:
            a_on();
            b_off();
            c_on();
            d_on();
            e_on();
            f_on();
            g_on();
            break;
        case 7:
            a_on();
            b_on();
            c_on();
            d_off();
            e_off();
            f_off();
            g_off();
            break;
        case 8:
            a_on();
            b_on();
            c_on();
            d_on();
            e_on();
            f_on();
            g_on();
            break;
        case 9:
            a_on();
            b_on();
            c_on();
            d_on();
            e_off();
            f_on();
            g_on();
            break;
        case 0:
            a_on();
            b_on();
            c_on();
            d_on();
            e_on();
            f_on();
            g_off();
            break;
    }
                                


}
/************************* 2020 Zaznov NIIKP ***********************************
*
* END OF FILE Kingbright_DA04-11GWA.c */
