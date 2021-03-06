/******************** (C) COPYRIGHT 2009 STMicroelectronics ********************
* File Name          : usb_endp.c
* Author             : MCD Application Team
* Version            : V3.0.1
* Date               : 04/27/2009
* Description        : Endpoint routines
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "usb_lib.h"
#include "usb_desc.h"
#include "usb_mem.h"
#include "hw_config.h"
#include "usb_istr.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint8_t buffer_out[VIRTUAL_COM_PORT_DATA_SIZE];
__IO uint32_t count_out = 0;
__IO uint8_t count_in = 0;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
* Function Name  : EP3_IN_Callback
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void EP3_OUT_Callback(void)
{
	/* Deal in While */
	count_out = GetEPRxCount(ENDP3);
	PMAToUserBufferCopy(buffer_out, ENDP3_RXADDR, count_out);
	SetEPRxValid(ENDP3);
//	if(buffer_callback != NULL) {
//		buffer_callback(buffer_out, count_out);
//	}
}

void EP6_OUT_Callback(void)
{
	SetEPRxValid(ENDP6);
}


/*******************************************************************************
* Function Name  : EP1_IN_Callback
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void EP1_IN_Callback(void)
{
	//count_in = 0;
	//printf("ok!\r\n");
}

/*******************************************************************************
* Function Name  : EP4_IN_Callback
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void EP4_IN_Callback(void)
{
	
}


/*******************************************************************************
* Function Name  : USB_Istr
* Description    : Start of frame callback function.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void SOF_Callback(void)
{
	count_in = 0;
  //In_Data_Offset = 0;
  //Out_Data_Offset = 0;
}

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/

