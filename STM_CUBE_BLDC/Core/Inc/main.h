/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Curr_PhaseC_Pin GPIO_PIN_0
#define Curr_PhaseC_GPIO_Port GPIOC
#define Curr_PhaseB_Pin GPIO_PIN_1
#define Curr_PhaseB_GPIO_Port GPIOC
#define Temperature_fdbck_Pin GPIO_PIN_2
#define Temperature_fdbck_GPIO_Port GPIOC
#define Curr_PhaseA_Pin GPIO_PIN_0
#define Curr_PhaseA_GPIO_Port GPIOA
#define BUSV_fdbck_Pin GPIO_PIN_1
#define BUSV_fdbck_GPIO_Port GPIOA
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define potentiometer_Pin GPIO_PIN_1
#define potentiometer_GPIO_Port GPIOB
#define LD2_Pin GPIO_PIN_13
#define LD2_GPIO_Port GPIOB
#define UH_PWM_Pin GPIO_PIN_8
#define UH_PWM_GPIO_Port GPIOA
#define VH_PWM_Pin GPIO_PIN_9
#define VH_PWM_GPIO_Port GPIOA
#define WH_PWM_Pin GPIO_PIN_10
#define WH_PWM_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define UH_Enable_Pin GPIO_PIN_10
#define UH_Enable_GPIO_Port GPIOC
#define VH_Enable_Pin GPIO_PIN_11
#define VH_Enable_GPIO_Port GPIOC
#define WH_Enable_Pin GPIO_PIN_12
#define WH_Enable_GPIO_Port GPIOC
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
