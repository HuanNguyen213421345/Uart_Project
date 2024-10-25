/****************************************************************
 *Include Library
 ***************************************************************/
#include "stdbool.h"
#include "string.h"
#include "stdint.h"
#include "gpio.h"
#include "usart.h"
#include "Uart_MiddleWare.h"
#include "Array_Lib.h"
#include "stm32f1xx_hal.h"

/****************************************************************
 *Definition
 ***************************************************************/
#define RX_BUFFER_LINE 4U
#define RX_BUFFER_SIZE 80U

/****************************************************************
 *Variable
 ***************************************************************/
static uint8_t RX_BUFFER[RX_BUFFER_LINE][RX_BUFFER_SIZE] = {0};
static uint32_t RX_Tail = 0;
static uint32_t RX_Head = 0;

/****************************************************************
 *Static Function
 ***************************************************************/
static void Uart_Peripheral_Init(void)
{
	MX_GPIO_Init();

	MX_USART2_UART_Init();
	HAL_UART_Receive_IT(&huart2,&RX_BUFFER[RX_Tail][0], 43);

}
/****************************************************************
 *API Function
 ***************************************************************/
void Uart_System_Init(void)
{
	Uart_Peripheral_Init();

	Uart_Print_String((uint8_t *)"Init success\n");
	Uart_Print_String((uint8_t *)"Please put your file\n");

}

//truyền dữ liệu qua usb_ttl
void Uart_Print_String(uint8_t *string)
{
	HAL_UART_Transmit(&huart2, string, strlen((char*) string), 1000);
}

bool Uart_Buffer_Ready(void)
{
	return(RX_Tail != RX_Head);
}

uint32_t Uart_Find_Max_Data_Line(void)
{
	uint32_t max_temp = 0;

	max_temp = Array_Find_Max_Value(&RX_BUFFER[RX_Head][0], 43);
	RX_Head++;
	if(RX_Head >= 4)
	{
		RX_Head = 0;
	}

	return max_temp;
}

/* Call back function */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{

	RX_Tail ++;
	if(RX_Tail >= 4)
	{
		RX_Tail = 0;
	}

	HAL_UART_Receive_IT(&huart2,&RX_BUFFER[RX_Tail][0], 43);
}

















