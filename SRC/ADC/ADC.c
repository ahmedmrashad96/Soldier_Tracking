/*
 * ADC.c
 *
 *  Created on: Nov 22, 2019
 *      Author: Ahmed Rashad
 */

#include "ADC_LOCAL.h"


void ADC_vidInit()
{
	ADMUX_R =((ADC_REFRENCE		<< ADMUX_REFS_S 	)& ADMUX_REFS_M)
			|( ADC_ADLAR		<< ADMUX_ADLAR	);
//	ADMUX_R=0x60;
	ADCSRA_R=(1					<< ADCSRA_ADEN)
			|( ADC_AUTO_TRIGGER	<< ADCSRA_ADATE)
			|( ADC_INTERRUPT 	<< ADCSRA_ADIE)
			|((ADC_PRESCALAR 	<< ADCSRA_ADPS_S)&ADCSRA_ADPS_M);
	SFIOR_R|=((ADC_TRIGGER << SFIOR_ADTS_S)&SFIOR_ADTS_M);
}
void ADC_Select(uint8 ADC)
{
	ADMUX_R |= (ADC<<ADMUX_MUX_S)&ADMUX_MUX_M;
}
void ADC_vidStartConversion ()
{
	Set_Bit(ADCSRA_R,ADCSRA_ADSC);
}
uint8 ADC_u8ConvFinshed()
{
	return Get_Bit(ADCSRA_R,ADCSRA_ADIF);
}
uint16 ADC_u16GetData(void)
{
	uint16 u16Data;

	u16Data =ADCL_R>>ADCL_S;
	u16Data|=ADCH_R<<ADCH_S;
	Set_Bit(ADCSRA_R,ADCSRA_ADIF);

	return (u16Data);
}


uint16 ADC_u16Read( uint8 ADC)
{
	ADC_Select(ADC);
	ADC_vidStartConversion();
	while(!ADC_u8ConvFinshed());
	return (ADC_u16GetData());
}
