/*
 * TEMP_SENSOR.c
 *
 *  Created on: Apr 4, 2020
 *      Author: shena
 */

#include "TEMP_SENSOR_LOCAL.h"

void TEMP_SENSOR_vidInit()
{
	ADC_vidInit();
	DIO_vidInit();
	DIO_u8SetPinDir(Temp_Sensor_pin,INPUT);
}

uint16 TEMP_SENSOR_u16GetData(int8 TEMP_ARR[])
{
	uint16 temp=(((uint32)ADC_u16Read(Temp_Sensor_pin)*500)/1023);
	uint16 t=temp;

	TEMP_ARR[2]=(t%10)+'0';t/=10;
	TEMP_ARR[1]=(t%10)+'0';t/=10;
	TEMP_ARR[0]=(t%10)+'0';

	return temp;
}

