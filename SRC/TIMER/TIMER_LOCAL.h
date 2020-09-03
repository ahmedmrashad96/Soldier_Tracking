/*
 * TIMER_LOCAL.h
 *
 *  Created on: Dec 10, 2019
 *      Author: Ahmed Rashad
 */

#ifndef TIMER_LOCAL_H_
#define TIMER_LOCAL_H_

#include "../COMMON/Std_Types.h"
#include "../COMMON/Utils.h"
#include "../COMMON/INTERRUPT.h"

#include "TIMER_CFG.h"


#define TIMSK_R	 		(*((volatile uint8 *)(0x59)))

#define TIMSK_OCIE2		(7)
#define TIMSK_TOCIE2	(6)
#define TIMSK_TICIE1	(5)
#define TIMSK_OCIE1A	(4)
#define TIMSK_OCIE1B	(3)
#define TIMSK_TOIE1		(2)
#define TIMSK_OCIE0		(1)
#define TIMSK_TOIE0		(0)




#define TIFR_R			(*((volatile uint8 *)(0x58)))

#define TIFR_OCF2		(7)
#define TIFR_TOV2		(6)
#define TIFR_ICF1		(5)
#define TIFR_OCF1A		(4)
#define TIFR_OCF1B		(3)
#define TIFR_TOV1		(2)
#define TIFR_OCF0		(1)
#define TIFR_TOV0		(0)


// TIMER 0 REGISTERS

// TIMER/COUNTER CONTROL REGISTER TCCR0
#define TCCR0_R	 		(*((volatile uint8 *)(0x53)))

#define TCCR0_FOC0	(7)
#define TCCR0_WGM00	(6)
#define TCCR0_COM01	(5)
#define TCCR0_COM00	(4)
#define TCCR0_COM_S	(4)
#define TCCR0_COM_M	(0x30)
#define TCCR0_WGM01	(3)
#define TCCR0_CS02	(2)
#define TCCR0_CS01	(1)
#define TCCR0_CS00	(0)
#define TCCR0_CS_S	(0)
#define TCCR0_CS_M	(0x07)


#define TCNT0_R	(*((volatile uint8 *)(0x52)))

#define OCR0_R	(*((volatile uint8 *)(0x5c)))
											
											
#define TCNT1H	(*((volatile uint8 *)(0x4D)))
#define TCNT1L	(*((volatile uint8 *)(0x4C)))
											
#define TCCR1A	(*((volatile uint8 *)(0x4F)))
#define TCCR1B	(*((volatile uint8 *)(0x4E)))
											
#define OCR1AH	(*((volatile uint8 *)(0x4B)))
#define OCR1AL	(*((volatile uint8 *)(0x4A)))
#define OCR1BH	(*((volatile uint8 *)(0x49)))
#define OCR1BL	(*((volatile uint8 *)(0x48)))
											
#define ICR1H	(*((volatile uint8 *)(0x47)))
#define ICR1L	(*((volatile uint8 *)(0x46)))
											
											
#define TCNT2	(*((volatile uint8 *)(0x44)))
#define TCCR2	(*((volatile uint8 *)(0x45)))
#define OCR2	(*((volatile uint8 *)(0x43)))
											





#endif /* TIMER_LOCAL_H_ */
