/*
 * UART_LOCAL.h
 *
 *  Created on: Feb 7, 2020
 *      Author: Ahmed Rashad
 */

#ifndef UART_LOCAL_H_
#define UART_LOCAL_H_

#include "../COMMON/Std_Types.h"
#include "../COMMON/Utils.h"

#include "UART_CFG.h"

#define UDR_R			*((volatile uint8 *)(0x2C))

#define UCSRA_R		*((volatile uint8 *)(0x2B))
#define UCSRA_RXC		(7)
#define UCSRA_TXC		(6)
#define UCSRA_UDRE	(5)
#define UCSRA_FE		(4)
#define UCSRA_DOR		(3)
#define UCSRA_PE		(2)
#define UCSRA_U2X		(1)
#define UCSRA_MPCM	(0)

#define UCSRB_R		*((volatile uint8 *)(0x2A))
#define UCSRB_RXCIE	(7)
#define UCSRB_TXCIE	(6)
#define UCSRB_UDRIE	(5)
#define UCSRB_RXEN	(4)
#define UCSRB_TXEN	(3)
#define UCSRB_UCSZ2	(2)
#define UCSRB_RXB8	(1)
#define UCSRB_TXB8	(0)

#define UCSRC_R		*((volatile uint8 *)(0x40))
#define UCSRC_URSEL	(7)
#define UCSRC_UMSEL	(6)
#define UCSRC_UPM1	(5)
#define UCSRC_UPM0	(4)
#define UCSRC_UPM_S	(4)
#define UCSRC_UPM_M	(0X30)
#define UCSRC_USBS	(3)
#define UCSRC_UCZ1	(2)
#define UCSRC_UCZ0	(1)
#define UCSRC_UCZ_S	(1)
#define UCSRC_UCZ_M	(0X06)
#define UCSRC_UCPOL	(0)

#define UBRRL_R		*((volatile uint8 *)(0x29))

#define UBRRH_R		*((volatile uint8 *)(0x40))
#define UBRRH_M		(0x0f)

#endif /* UART_LOCAL_H_ */
