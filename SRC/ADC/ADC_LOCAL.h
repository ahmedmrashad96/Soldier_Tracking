/*
 * ADC_LOCAL.h
 *
 *  Created on: Mar 14, 2020
 *      Author: Ahmed Rashad
 */

#ifndef ADC_LOCAL_H_
#define ADC_LOCAL_H_
#include "../COMMON/Std_Types.h"
#include "../COMMON/Utils.h"

#include "ADC_CFG.h"


#define ADMUX_R	    	*((volatile uint8 *)(0x27))
#define ADMUX_REFS1		(7)
#define ADMUX_REFS0		(6)
#define ADMUX_REFS_S	(6)
#define ADMUX_REFS_M 	(0XC0)
#define ADMUX_ADLAR		(5)
#define ADMUX_MUX4		(4)
#define ADMUX_MUX3		(3)
#define ADMUX_MUX2		(2)
#define ADMUX_MUX1		(1)
#define ADMUX_MUX0		(0)
#define ADMUX_MUX_S		(0)
#define ADMUX_MUX_M		(0X1F)




#define ADCSRA_R		*((volatile uint8 *)(0x26))
#define ADCSRA_ADEN		(7)
#define ADCSRA_ADSC		(6)
#define ADCSRA_ADATE	(5)
#define ADCSRA_ADIF		(4)
#define ADCSRA_ADIE		(3)
#define ADCSRA_ADPS2	(2)
#define ADCSRA_ADPS1	(1)
#define ADCSRA_ADPS0	(0)
#define ADCSRA_ADPS_S	(0)
#define ADCSRA_ADPS_M	(0X07)

#define ADCH_R		    *((volatile uint8 *)(0x25))
#define ADCL_R		    *((volatile uint8 *)(0x24))

#define SFIOR_R			*((volatile uint8 *)(0x50))
#define SFIOR_ADTS2		(7)
#define SFIOR_ADTS1		(6)
#define SFIOR_ADTS0		(5)
#define SFIOR_ADTS_S	(5)
#define SFIOR_ADTS_M	(0xE0)


#if ADC_ADLAR == 0
	#define ADCH_S		(8)
	#define ADCL_S 		(0)
#elif ADC_ADLAR == 1
	#define ADCH_S		(2)
	#define ADCL_S		(6)
#else
	#error	ADLAR wrong value
#endif

#endif /* ADC_LOCAL_H_ */
