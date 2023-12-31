/**
  ******************************************************************************
  * @file    USB_Device/HID_Standalone_BCD/Inc/main.h 
  * @author  MCD Application Team
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f072b_discovery.h"
#include "usbd_core.h"
#include "usbd_desc.h"
#include "usbd_hid.h" 

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/

/* Uncomment the line below to select your USB clock source */
#define USE_USB_CLKSOURCE_CRSHSI48   1
//#define USE_USB_CLKSOURCE_PLL        1
typedef enum
{
  USB_BCD_ERROR                     = 0xFF,
  USB_BCD_CONTACT_DETECTION         = 0xFE,
  USB_BCD_STD_DOWNSTREAM_PORT       = 0xFD,
  USB_BCD_CHARGING_DOWNSTREAM_PORT  = 0xFC,
  USB_BCD_DEDICATED_CHARGING_PORT   = 0xFB,
  USB_BCD_DISCOVERY_COMPLETED       = 0xFA,
  USB_BCD_DEVICE_DISCONNECTED       = 0xF9,
  USB_BCD_IDLE                      = 0x00,
} USB_BCD_Status;

void Error_Handler(void);

#if !defined (USE_USB_CLKSOURCE_PLL) && !defined (USE_USB_CLKSOURCE_CRSHSI48)
 #error "Missing USB clock definition"
#endif
/* Exported functions ------------------------------------------------------- */
void Toggle_Leds(void);
void GetPointerData(uint8_t *pbuf);

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
