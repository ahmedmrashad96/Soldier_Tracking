/*
 * DIO.C
 *
 * This file contains the Source Code of the DIO Driver
 *
 *  Created on: Mar 16, 2020
 *      Author: Ahmed Rashad
 */



#include "DIO_LOCAL.h"

void DIO_vidInit (void)
{
	//DIO Initialization function

}

uint8 DIO_u8SetPinDir (uint8 u8PinNum , uint8 u8Dir)
{
	/*
	 * Setting pin direction
	 * 		Pin number 		: 	PORTx_n 	n= 	0:7		x=	A:D
	 *		Pin Direction	:	OUTPUT	/	INPUT 	/ INPUT_PULLUP
	 *
	 */
	// initializing the status of the functions
	uint8 u8Status=ERROR;
	// checking the inputs of the functions
	if ((u8PinNum<DIO_PINS_MAX)&&(u8Dir<DIO_PIN_DIR_MAX))
	{
		u8Status = SUCCESS;
		// calculating the port no.
		switch(u8PinNum/8)
		{
		case PORT_A : //PORTA
			// Write pin direction
			Assign_Bit(DDRA ,u8PinNum % 8, Get_Bit(u8Dir,0) );
			// Write pin pullup state
			Assign_Bit(PORTA,u8PinNum % 8, Get_Bit(u8Dir,1) );
			break;
		case PORT_B : //PORTB
			// Write pin direction
			Assign_Bit(DDRB ,u8PinNum % 8, Get_Bit(u8Dir,0) );
			// Write pin pullup state
			Assign_Bit(PORTB,u8PinNum % 8, Get_Bit(u8Dir,1) );
			break;
		case PORT_C : //PORTC
			// Write pin direction
			Assign_Bit(DDRC ,u8PinNum % 8, Get_Bit(u8Dir,0) );
			// Write pin pullup state
			Assign_Bit(PORTC,u8PinNum % 8, Get_Bit(u8Dir,1) );
			break;
		case PORT_D : //PORTD
			// Write pin direction
			Assign_Bit(DDRD ,u8PinNum % 8, Get_Bit(u8Dir,0) );
			// Write pin pullup state
			Assign_Bit(PORTD,u8PinNum % 8, Get_Bit(u8Dir,1) );
			break;
		default:
			u8Status=ERROR;
			break;
		}

	}
	return u8Status;

}

uint8 DIO_u8WritePin (uint8 u8PinNum , uint8 u8Data)
{
	/*
	 * Writing to pin
	 * 		Pin number 		: 	PORTx_n 	n= 	0:7		x=	A:D
	 *		Pin Data		:	HIGH	/	LOW
	 *
	 */
	// initializing the status of the functions
	uint8 u8Status=ERROR;
	// checking the inputs of the functions
	if ((u8PinNum<DIO_PINS_MAX)&&(u8Data<DIO_DATA_ERROR))
	{
		u8Status=SUCCESS;
		// calculating the port no.
		switch(u8PinNum/8)
		{
		case PORT_A : //PORTA
			// Write pin values
			Assign_Bit(PORTA ,u8PinNum % 8, u8Data );
			break;
		case PORT_B : //PORTB
			// Write pin values
			Assign_Bit(PORTB ,u8PinNum % 8, u8Data );
			break;
		case PORT_C : //PORTC
			// Write pin values
			Assign_Bit(PORTC ,u8PinNum % 8, u8Data );
			break;
		case PORT_D : //PORTD
			// Write pin values
			Assign_Bit(PORTD ,u8PinNum % 8, u8Data );
			break;
		default:
			u8Status=ERROR;
			break;
		}

	}
	return u8Status;
}

uint8 DIO_u8ReadPin (uint8 u8PinNum )
{
	/*
	 * Reading from pin
	 * 		Pin number 		: 	PORTx_n 	n= 	0:7		x=	A:D
	 */
	// initializing the status of the functions
	uint8 u8Data=DIO_DATA_ERROR;
	// checking the inputs of the functions
	if (u8PinNum<DIO_PINS_MAX)
	{
		// calculating the port no.
		switch(u8PinNum/8)
		{
		case PORT_A : //PORTA
			//Read from pin
			u8Data= Get_Bit(PINA ,u8PinNum % 8);
			break;
		case PORT_B : //PORTB
			//Read from pin
			u8Data= Get_Bit(PINB ,u8PinNum % 8);
			break;
		case PORT_C : //PORTC
			//Read from pin
			u8Data= Get_Bit(PINC ,u8PinNum % 8);
			break;
		case PORT_D : //PORTD
			//Read from pin
			u8Data= Get_Bit(PIND ,u8PinNum % 8);
			break;
		default:
			u8Data= DIO_DATA_ERROR;
			break;
		}
	}
	return u8Data;
}
