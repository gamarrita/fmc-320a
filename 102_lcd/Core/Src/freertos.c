/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : freertos.c
 * Description        : Code for freertos applications
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
extern RTC_HandleTypeDef hrtc;

/* USER CODE END Variables */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

/* USER CODE BEGIN PREPOSTSLEEP */
__weak void PreSleepProcessing(uint32_t ulExpectedIdleTime)
{
    /* place for user code */
    uint32_t delay_ms = ulExpectedIdleTime * 2048ul;

    delay_ms /= 1000;

    HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, delay_ms, RTC_WAKEUPCLOCK_RTCCLK_DIV16);
    HAL_SuspendTick();

    __DSB();
    HAL_PWREx_EnterSTOP2Mode(PWR_STOPENTRY_WFI);
    __ISB();

}

__weak void PostSleepProcessing(uint32_t ulExpectedIdleTime)
{
    /* place for user code */
    HAL_RTCEx_DeactivateWakeUpTimer(&hrtc);
    HAL_ResumeTick();
}
/* USER CODE END PREPOSTSLEEP */

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

