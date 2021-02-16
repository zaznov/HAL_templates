/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
#include <stdio.h>

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
    char str[100];
    char ch1 = 32;
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId myTerminal_1Handle;
osThreadId myTerminal_2Handle;
osThreadId myScreenHandle;
osThreadId myLedsHandle;
osSemaphoreId myBinarySem01Handle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void StartTerminal_1(void const * argument);
void StartTerminal_2(void const * argument);
void StartScreen(void const * argument);
void StartLeds(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* Create the semaphores(s) */
  /* definition and creation of myBinarySem01 */
  osSemaphoreDef(myBinarySem01);
  myBinarySem01Handle = osSemaphoreCreate(osSemaphore(myBinarySem01), 1);

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of myTerminal_1 */
  osThreadDef(myTerminal_1, StartTerminal_1, osPriorityIdle, 0, 128);
  myTerminal_1Handle = osThreadCreate(osThread(myTerminal_1), NULL);

  /* definition and creation of myTerminal_2 */
  osThreadDef(myTerminal_2, StartTerminal_2, osPriorityIdle, 0, 128);
  myTerminal_2Handle = osThreadCreate(osThread(myTerminal_2), NULL);

  /* definition and creation of myScreen */
  osThreadDef(myScreen, StartScreen, osPriorityIdle, 0, 128);
  myScreenHandle = osThreadCreate(osThread(myScreen), NULL);

  /* definition and creation of myLeds */
  osThreadDef(myLeds, StartLeds, osPriorityIdle, 0, 128);
  myLedsHandle = osThreadCreate(osThread(myLeds), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_StartTerminal_1 */
/**
* @brief Function implementing the myTerminal_1 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTerminal_1 */
void StartTerminal_1(void const * argument)
{
  /* USER CODE BEGIN StartTerminal_1 */
    //uint8_t str[] = "Hello USART_1!\n";
  /* Infinite loop */
  for(;;)
  {
    my_UART_transmit(&huart2, 1, 15, 0xFFFF);
    osDelay(1000);
  }
  /* USER CODE END StartTerminal_1 */
}

/* USER CODE BEGIN Header_StartTerminal_2 */
/**
* @brief Function implementing the myTerminal_2 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTerminal_2 */
void StartTerminal_2(void const * argument)
{
  /* USER CODE BEGIN StartTerminal_2 */
    //uint8_t str[] = "Hello USART_2!\n";
  /* Infinite loop */
  for(;;)
  {
      my_UART_transmit(&huart2, 2, 15, 0xFFFF);
      osDelay(1000);
  }
  /* USER CODE END StartTerminal_2 */
}

/* USER CODE BEGIN Header_StartScreen */
/**
* @brief Function implementing the myScreen thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartScreen */
void StartScreen(void const * argument)
{
  /* USER CODE BEGIN StartScreen */
    LCD_init();
	sprintf(str,"Stm32F407VG");
	LCD_String(str);
	LCD_Set_Position(10, 2);
	sprintf(str,"ARM mc");
	LCD_String(str);
	osDelay(2000);
	LCD_Clear();
	LCD_Set_Position(4, 0);
	LCD_SendChar('s');
	LCD_Set_Position(8, 1);
	LCD_SendChar('t');
	LCD_Set_Position(12, 2);
	LCD_SendChar('m');
	LCD_Set_Position(16, 3);
	LCD_SendChar('3');
	LCD_SendChar('2');
	osDelay(2000);
  /* Infinite loop */
  for(;;)
  {
    LCD_Set_Position(3, 3);
    LCD_SendChar(ch1);
    osDelay(2000);
    ch1++;
  }
  /* USER CODE END StartScreen */
}

/* USER CODE BEGIN Header_StartLeds */
/**
* @brief Function implementing the myLeds thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartLeds */
void StartLeds(void const * argument)
{
  /* USER CODE BEGIN StartLeds */
  /* Infinite loop */
  for(;;)
  {
    HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
    osDelay(20);
    HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
    osDelay(40);
    HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
    osDelay(60);
    HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
    osDelay(80);
  }
  /* USER CODE END StartLeds */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
