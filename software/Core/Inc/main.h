/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f4xx_hal.h"

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
#define BUTTON_SELECT_Pin GPIO_PIN_3
#define BUTTON_SELECT_GPIO_Port GPIOC
#define BUTTON_SELECT_EXTI_IRQn EXTI3_IRQn
#define ENC_R_B_Pin GPIO_PIN_0
#define ENC_R_B_GPIO_Port GPIOA
#define ENC_R_A_Pin GPIO_PIN_1
#define ENC_R_A_GPIO_Port GPIOA
#define VOLTM_BOOST_Pin GPIO_PIN_2
#define VOLTM_BOOST_GPIO_Port GPIOA
#define VOLTM_BATT_Pin GPIO_PIN_3
#define VOLTM_BATT_GPIO_Port GPIOA
#define ENC_L_A_Pin GPIO_PIN_5
#define ENC_L_A_GPIO_Port GPIOA
#define BOOT1_Pin GPIO_PIN_2
#define BOOT1_GPIO_Port GPIOB
#define FAN_L_PWM_Pin GPIO_PIN_6
#define FAN_L_PWM_GPIO_Port GPIOC
#define FAN_R_PWM_Pin GPIO_PIN_7
#define FAN_R_PWM_GPIO_Port GPIOC
#define SDA_Pin GPIO_PIN_9
#define SDA_GPIO_Port GPIOC
#define SCL_Pin GPIO_PIN_8
#define SCL_GPIO_Port GPIOA
#define TX_Pin GPIO_PIN_9
#define TX_GPIO_Port GPIOA
#define RX_Pin GPIO_PIN_10
#define RX_GPIO_Port GPIOA
#define BUZZER_Pin GPIO_PIN_11
#define BUZZER_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define LED_B_Pin GPIO_PIN_15
#define LED_B_GPIO_Port GPIOA
#define LED_G_Pin GPIO_PIN_10
#define LED_G_GPIO_Port GPIOC
#define LED_R_Pin GPIO_PIN_11
#define LED_R_GPIO_Port GPIOC
#define ENC_L_B_Pin GPIO_PIN_3
#define ENC_L_B_GPIO_Port GPIOB
#define MOTOR_R_IN2_Pin GPIO_PIN_4
#define MOTOR_R_IN2_GPIO_Port GPIOB
#define MOTOR_R_IN1_Pin GPIO_PIN_5
#define MOTOR_R_IN1_GPIO_Port GPIOB
#define MOTOR_L_IN2_Pin GPIO_PIN_6
#define MOTOR_L_IN2_GPIO_Port GPIOB
#define MOTOR_L_IN1_Pin GPIO_PIN_7
#define MOTOR_L_IN1_GPIO_Port GPIOB
#define MOTOR_R_PWM_Pin GPIO_PIN_8
#define MOTOR_R_PWM_GPIO_Port GPIOB
#define MOTOR_L_PWM_Pin GPIO_PIN_9
#define MOTOR_L_PWM_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
