/*
 * DIO.h
 *
 *  This file contains the Prototypes of the DIO Driver
 *
 *  Created on: Mar 16, 2020
 *      Author: Ahmed Rashad
 */

#ifndef DIO_H_
#define DIO_H_

#include "DIO_CFG.h"

void 	DIO_vidInit 		(void);
uint8	DIO_u8SetPinDir (uint8 U8PinNum , uint8 U8Dir);
uint8 	DIO_u8WritePin 	(uint8 U8PinNum , uint8 U8Data);
uint8   DIO_u8ReadPin 	(uint8 U8PinNum);

#endif /* DIO_H_ */
