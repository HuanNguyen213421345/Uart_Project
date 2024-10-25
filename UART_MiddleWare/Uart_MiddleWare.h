#ifndef UART_MIDDLEWARE_H_
#define UART_MIDDLEWARE_H_
#include "stdbool.h"

// Tìm max data trong 1 line
uint32_t Uart_Find_Max_Data_Line(void);

//true thì call hàm find_max_data, tức là đã cớ nhiều hơn 1 line
bool Uart_Buffer_Ready(void);

void Uart_System_Init(void);

void Uart_Print_String(uint8_t *string);

void Uart_System_String_Init(void);

#endif
