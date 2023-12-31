/**
  ******************************************************************************
  * @file    COMP/COMP_AnalogWatchdog/Src/stm32f0xx_hal_msp.c
  * @author  MCD Application Team
  * @brief   HAL MSP module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup STM32F0xx_HAL_Examples
  * @{
  */

/** @defgroup COMP_AnalogWatchdog
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup HAL_MSP_Private_Functions
  * @{
  */

/**
  * @brief COMP MSP Initialization 
  *        This function configures the hardware resources used in this example: 
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration  
  *           - NVIC configuration for COMP interrupt request enable
  * @param hcomp: COMP handle pointer
* @retval None
*/
void HAL_COMP_MspInit(COMP_HandleTypeDef *hcomp)
{      
  GPIO_InitTypeDef      GPIO_InitStruct;
  
  /*##-1- Enable peripherals and GPIO Clocks #################################*/
  /* Enable GPIO clock ****************************************/
  COMPx_GPIO_CLK_ENABLE();
  /* COMP Periph clock enable */
  COMPx_CLK_ENABLE();
  
  /*##-2- Configure peripheral GPIO ##########################################*/  
  /* COMP GPIO pin configuration */
  GPIO_InitStruct.Pin = COMPx_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(COMPx_GPIO_PORT, &GPIO_InitStruct);

  /*##-3- Configure the NVIC for COMPx ########################################*/
  /* NVIC for COMPx */
  HAL_NVIC_SetPriority(COMPx_IRQn, 3, 0);
  HAL_NVIC_EnableIRQ(COMPx_IRQn);
}

/**
  * @brief  DeInitializes the COMP MSP.
  * @param  hcomp: pointer to a COMP_HandleTypeDef structure that contains
  *         the configuration information for the specified COMP.  
* @retval None
*/
void HAL_COMP_MspDeInit(COMP_HandleTypeDef *hcomp)
{  
  /*##-1- Disable peripherals and GPIO Clocks ################################*/
  /* De-initialize the COMPx GPIO pin */
  HAL_GPIO_DeInit(COMPx_GPIO_PORT, COMPx_PIN);
                
  /*##-2- Disable the NVIC for COMP ###########################################*/
  HAL_NVIC_DisableIRQ(COMPx_IRQn);
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
