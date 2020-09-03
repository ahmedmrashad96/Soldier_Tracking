/*
 * SWITCH.c
 *
 *  Created on: Dec 21, 2019
 *      Author: Ahmed Rashad
 */

#include "SWITCH_LOCAL.h"


static void dummy()
{

}
static	uint8 PBN[PBN_COUNT] = {PBN_0,PBN_1,PBN_2};
static	uint8 PBN_state[PBN_COUNT] = {SWITCH_STATE_Error};
static void (*ptrfun[PBN_COUNT])(void)={dummy};

void SW_vidInit(void)
{
	uint8 u8i;

	for (u8i=0 ;u8i<PBN_COUNT;u8i++)
	{
		DIO_u8SetPinDir(PBN_state[u8i],INPUT_PULLUP);
	}


}


void SW_vidTask(void)
{
	static uint8 counter[PBN_COUNT] = {0},u8i=0;

	if (u8i < PBN_COUNT)
	{
		switch (PBN_state[u8i])
		{
		case Released 	:
			if (DIO_u8ReadPin(PBN[u8i])==LOW)
				PBN_state[u8i] = PrePushed;
			break;
		case PrePushed	:
			if (DIO_u8ReadPin(PBN[u8i])==LOW)
				counter[u8i]++;
			if (counter[u8i]>=SENS_COUNT)
			{
				counter[u8i]=0;
				PBN_state[u8i] = Pushed;
			}
			break;
		case Pushed		:
			if (DIO_u8ReadPin(PBN[u8i])==HIGH)
				PBN_state[u8i] = PreReleased;
			break;
		case PreReleased:
			if (DIO_u8ReadPin(PBN[u8i])==HIGH)
				counter[u8i]++;
			if (counter[u8i]>=SENS_COUNT)
			{
				counter[u8i]=0;
				PBN_state[u8i] = Released;
			}
			break;
		default:
			PBN_state[u8i] = Released;
			break;
		}
		u8i++;
	}
	else
	{
		u8i=0;
	}
}

uint8 SW_u8Read(uint8 u8PBN)
{
	return PBN_state[u8PBN];
}
