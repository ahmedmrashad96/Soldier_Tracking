/*
 * UART_CFG.h
 *
 *  Created on: Feb 7, 2020
 *      Author: Ahmed Rashad
 */

#ifndef UART_CFG_H_
#define UART_CFG_H_


#define DEBUGGING

#define	UART_PARITY_NON		0
#define	UART_PARITY_EVEN		2
#define	UART_PARITY_ODD		3

#define UART_STOP_BITS_ONE		0
#define UART_STOP_BITS_TWO		1

#define UART_5BIT				0
#define UART_6BIT				1
#define UART_7BIT				2
#define UART_8BIT				3
#define UART_9BIT				8


#ifndef FREQUENCY
#define FREQUENCY				16000000UL
#endif

#define UART_BAUDRATE			9600
#define UART_STOP_BITS 			UART_STOP_BITS_ONE
#define UART_CHRACTER_LENGTH	UART_8BIT
#define UART_PARITY_MODE		UART_PARITY_NON
#define UART_RXC_INT			0
#define UART_TXC_INT			0
#define UART_UDRE_INT			0


#define RXD						PORTD_0
#define TXD						PORTD_1

#endif /* UART_CFG_H_ */
