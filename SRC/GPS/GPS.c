/*
 * GPS.C
 *
 *  Created on: Mar 12, 2020
 *      Author: Ahmed Rashad
 */
#include "GPS_LOCAL.h"


static GPS   Data;
static uint8 GPS_Status=GPS_OutDated;


void GPS_vidInit ()
{
	DIO_u8SetPinDir(Selector,OUTPUT);
	DIO_u8SetPinDir(RXD,OUTPUT);
	DIO_u8SetPinDir(TXD,INPUT_PULLUP);
	UART_vidInit();
}
void GPS_vidTask ()
{
	static  uint8 u8State=0,	u8Counter=0,	GPGGA[8]="$GPGGA,";
	if (UART_u8DataReady())
	{
		uint8 u8RxData=UART_u8GetUdr();

		if (GPS_Status<GPS_UpToDate)
		{
			switch (u8State)
			{
			case 1:
				if (u8RxData==',')
				{
					Data.UTC[u8Counter]=0;
					u8State=2;
					u8Counter=0;
					GPS_Status = GPS_UpDating;
				}
				else
				{
					Data.UTC[u8Counter++]=u8RxData;
				}
				break;
			case 2:
				if (u8RxData==',')
				{
					Data.LAT[u8Counter++]=',';
					u8State=3;
				}
				else
				{
					Data.LAT[u8Counter++]=u8RxData;
				}
				break;
			case 3:
				if (u8RxData==',')
				{
					Data.LAT[u8Counter]=0;
					u8State=4;
					u8Counter=0;
				}
				else
				{
					Data.LAT[u8Counter++]=u8RxData;
				}
				break;
			case 4:
				if (u8RxData==',')
				{
					Data.LON[u8Counter++]=',';
					u8State=5;
				}
				else
				{
					Data.LON[u8Counter++]=u8RxData;
				}
				break;
			case 5:
				if (u8RxData==',')
				{
					Data.LON[u8Counter]=0;
					u8State=6;
					u8Counter=0;
				}
				else
				{
					Data.LON[u8Counter++]=u8RxData;
				}
				break;
			case 6:
				if (u8RxData==',')
				{
					u8State=0;
					GPS_Status=GPS_FreshData;
					u8Counter=0;
				}
				else
				{
					Data.FIX=(u8RxData=='1'||u8RxData=='2');
				}
				break;
			default:
				if (u8Counter<7 )
				{
					if (u8RxData!=GPGGA[u8Counter++])
					{
						u8Counter=0;
					}

				}
				else
				{
					Data.UTC[0]=u8RxData;
					u8Counter=1;
					u8State = 1;
				}
				break;
			}
		}
	}
}
GPS   GPS_u8GetData()
{
	if (GPS_Status==GPS_FreshData)
	{
		GPS_Status=GPS_UpToDate;
	}
	return Data;
}
uint8 GPS_u8GetTime(int8 UTC[])
{
	uint8 u8i;
	for (u8i=0;u8i<UTC_LENGTH;u8i++)
	{
		UTC[u8i]=Data.UTC[u8i];
	}
	return Data.FIX;
}
uint8 GPS_u8GetLat(int8 LAT[])
{
	uint8 u8i;
	for (u8i=0;u8i<LAT_LENGTH;u8i++)
	{
		LAT[u8i]=Data.LAT[u8i];
	}
	return Data.FIX;
}
uint8 GPS_u8GetLon(int8 LON[])
{
	uint8 u8i;
	for (u8i=0;u8i<LON_LENGTH;u8i++)
	{
		LON[u8i]=Data.LAT[u8i];
	}
	return Data.FIX;
}
uint8 GPS_GetStatus()
{
	return GPS_Status;
}
void GPS_vidUpdate()
{
	GPS_Status = GPS_OutDated;
}



GPS GPS_READ ()
{
	uint16 dummy;
	GPS_Status = GPS_OutDated;
	while(GPS_Status!=GPS_FreshData)
	{
		GPS_vidTask();
		dummy=0;

	}

	return Data;

}
void GPS_vidDisAttach ()
{
	UART_u8RecieveChar();
}
void GPS_vidSelect()
{
	DIO_u8WritePin(Selector,Select_GPS);
}
