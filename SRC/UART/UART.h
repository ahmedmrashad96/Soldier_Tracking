/*
 * UART.h
 *
 *  Created on: Feb 7, 2020
 *      Author: Ahmed Rashad
 */

#ifndef UART_H_
#define UART_H_

#include "UART_CFG.h"

void UART_vidInit(void);
void UART_vidSendChar(uint8 u8Data);
uint8 UART_u8RecieveChar(void);
uint8 UART_u8DataReady();
uint8 UART_u8GetUdr();
void UART_vidSendString(uint8 u8Data[], uint8 length);
void UART_vidRecieveString(uint8 u8Data[], uint8* length);
uint8 UART_vidSendStringConfirmed(uint8 * u8Data);

#ifdef DEBUGGING
void _Debug(int8 u8Data[]);
void _Debug_value(uint32 u32Data);
#endif

#endif /* UART_H_ */
