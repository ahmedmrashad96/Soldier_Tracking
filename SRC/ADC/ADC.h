/*
 * ADC.h
 *
 *  Created on: Nov 22, 2019
 *      Author: Ahmed Rashad
 */

#ifndef ADC_H_
#define ADC_H_

#include "ADC_CFG.h"

void ADC_vidInit();
void ADC_Select(uint8 ADC);
void ADC_vidStartConversion ();
uint8 ADC_u8ConvFinshed();
uint16 ADC_u16GetData(void);
uint16 ADC_u16Read( uint8 ADC);


#endif /* ADC_H_ */
