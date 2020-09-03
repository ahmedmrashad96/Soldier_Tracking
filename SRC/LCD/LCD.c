/*
 * LCD.c
 *
 *  Created on: Nov 16, 2019
 *      Author: Ahmed Rashad
 */

#include "LCD_LOCAL.h"

static int8 LCD_LINE[2][17]={"                ",
							 "                "};
static uint8 u8x =0,u8y=0,u8LCDState=0;

static uint8 LCD_u8WriteCommand(uint8 u8Command)
{
	static uint8 u8LCDwritetime=0,LCD_Command_State=0;
	switch(LCD_Command_State)
	{
	case 0:
		//RS 	= 0
		DIO_u8WritePin(LCD_RS,LOW);
		//R/W 	= 0
		DIO_u8WritePin(LCD_RW,LOW);
		//Send data

		//Write high Niple
		DIO_u8WritePin(LCD_D7,Get_Bit(u8Command,7));
		DIO_u8WritePin(LCD_D6,Get_Bit(u8Command,6));
		DIO_u8WritePin(LCD_D5,Get_Bit(u8Command,5));
		DIO_u8WritePin(LCD_D4,Get_Bit(u8Command,4));

		//set enable
		DIO_u8WritePin(LCD_E,HIGH);
		//Next State
		LCD_Command_State++;
		u8LCDwritetime = 0;
		break;
	case 1:
		//delay 5 ms
		if(++u8LCDwritetime>5)
		{
			u8LCDwritetime=0;
			LCD_Command_State++;
		}
		break;
	case 2:
		//clear enable
		DIO_u8WritePin(LCD_E,LOW);
		//Next State
		LCD_Command_State++;
		break;
	case 3:
		//delay 5ms
		if(++u8LCDwritetime>5)
		{
			u8LCDwritetime=0;
			LCD_Command_State++;
		}
		break;
	case 4:
		if(u8Command!=0x20)
		{
			//Next State
			LCD_Command_State++;
		}
		else
		{
			LCD_Command_State=9;
		}
		break;
	case 5:

		//Write Low Niple
		DIO_u8WritePin(LCD_D7,Get_Bit(u8Command,3));
		DIO_u8WritePin(LCD_D6,Get_Bit(u8Command,2));
		DIO_u8WritePin(LCD_D5,Get_Bit(u8Command,1));
		DIO_u8WritePin(LCD_D4,Get_Bit(u8Command,0));

		//E		: Falling edge
		DIO_u8WritePin(LCD_E,HIGH);

		LCD_Command_State++;

		break;

	case 6:
		if(++u8LCDwritetime>5)
		{
			u8LCDwritetime=0;
			LCD_Command_State++;
		}
		break;
	case 7:
		DIO_u8WritePin(LCD_E,LOW);
		LCD_Command_State++;
		break;
	case 8:
		if(++u8LCDwritetime>5)
		{
			u8LCDwritetime=0;
			LCD_Command_State++;
		}
		break;
	default:
		LCD_Command_State = 0;
		break;
	}
	return (LCD_Command_State==0);
}


static uint8 LCD_u8Init(void)
{
	static uint8 u8LCD_init_state=0,u8LCDinittime=0;
	switch (u8LCD_init_state)
	{
	case 0:
		DIO_u8SetPinDir(LCD_E ,OUTPUT);
		DIO_u8SetPinDir(LCD_RW,OUTPUT);
		DIO_u8SetPinDir(LCD_RS,OUTPUT);

		DIO_u8SetPinDir(LCD_D7,OUTPUT);
		DIO_u8SetPinDir(LCD_D6,OUTPUT);
		DIO_u8SetPinDir(LCD_D5,OUTPUT);
		DIO_u8SetPinDir(LCD_D4,OUTPUT);
		u8LCD_init_state++;

		break;
	case 1:								//Delay 30 ms
		if (++u8LCDinittime > 40)
		{
			u8LCDinittime=0;
			u8LCD_init_state++;
		}
		break;
	case 2:


		if ( LCD_u8WriteCommand(0x20) )
		{
		u8LCD_init_state++;
		}
		break;
	case 3:								//Delay 5 ms
		if (++u8LCDinittime > 5)
		{
			u8LCDinittime=0;
			u8LCD_init_state++;
		}
		break;
	case 4:								//Function Set 		0011NFxx N:number of lines 1/2 F: font 5*8/5*11
		if ( LCD_u8WriteCommand(0x2c) )
		{
		u8LCD_init_state++;
		}
		break;
	case 5:								//Delay 3 ms
		if (++u8LCDinittime > 3)
		{
			u8LCDinittime=0;
			u8LCD_init_state++;
		}
		break;
	case 6:
		if (LCD_u8WriteCommand(0x0c))
		{
		u8LCD_init_state++;
		}
		break;
	case 7:								//Delay 3 ms
		if (++u8LCDinittime > 3)
		{
			u8LCDinittime=0;
			u8LCD_init_state++;
		}
		break;
	case 8:
		if( LCD_u8WriteCommand(0x01))
		{
		u8LCD_init_state++;
		}
		break;
	case 9:								//Delay 40 ms
		if (++u8LCDinittime > 10)
		{
			u8LCDinittime=0;
			u8LCD_init_state++;
		}
		break;
	default:
		u8LCD_init_state=0;
		break;

	}
return (u8LCD_init_state==0);

}

static uint8 LCD_u8WriteData( uint8 u8Data)
{
	static uint8 u8LCDdatatime=0;
	static uint8 LCD_Data_State=0;

	switch(LCD_Data_State){

	case 0:
		//RS 	= 1
			DIO_u8WritePin(LCD_RS,HIGH);

			//R/W 	= 0
			DIO_u8WritePin(LCD_RW,LOW);

			//Send data

			//Write High Niple
			DIO_u8WritePin(LCD_D7,Get_Bit(u8Data,7));
			DIO_u8WritePin(LCD_D6,Get_Bit(u8Data,6));
			DIO_u8WritePin(LCD_D5,Get_Bit(u8Data,5));
			DIO_u8WritePin(LCD_D4,Get_Bit(u8Data,4));

			//E		: Falling edge
			DIO_u8WritePin(LCD_E,HIGH);
			LCD_Data_State++;
			u8LCDdatatime = 0;
		break;

	case 1:
		if(++u8LCDdatatime > 5){
			LCD_Data_State++;
		}
		break;
	case 2:
		u8LCDdatatime =0;
		DIO_u8WritePin(LCD_E,LOW);

			//Write High Niple
			DIO_u8WritePin(LCD_D7,Get_Bit(u8Data,3));
			DIO_u8WritePin(LCD_D6,Get_Bit(u8Data,2));
			DIO_u8WritePin(LCD_D5,Get_Bit(u8Data,1));
			DIO_u8WritePin(LCD_D4,Get_Bit(u8Data,0));

			//E		: Falling edge
			DIO_u8WritePin(LCD_E,HIGH);
			LCD_Data_State++;

		break;
	case 3:DIO_u8WritePin(0,LOW);
			if(++u8LCDdatatime > 5){
				LCD_Data_State++;
			}
			break;


	case 4:
		u8LCDdatatime = 0;
		DIO_u8WritePin(LCD_E,LOW);
		LCD_Data_State++;
		break;

	default :
		LCD_Data_State = 0;
		return 1;
		break;
	}

	return 0;

}

static uint8 LCD_u8GotoXY (uint8 x , uint8 y)
{
	if (LCD_u8WriteCommand(0x80|(((y)&1)<<6)|((x) & 0x3f)))
	{
		return 1;
	}
	return 0;
}


void LCD_vidTask (void)
{
	static uint8 LCDx=0,LCDy=0;
	switch(u8LCDState)
	{
	case 0:
		break;
	case 1:
		if(LCD_u8Init())
		{
			u8LCDState++;
		}
		break;
	case 2:
		if(LCD_u8WriteCommand(1))
		{
			u8LCDState++;
		}
		break;
	case 3:
		if(LCD_u8WriteData(LCD_LINE[LCDy][LCDx]))
		{
			if(++LCDx>15)
			{
				LCDx=0;
				if(++LCDy>1)
				{
					LCDy=0;
				}
				u8LCDState++;
			}
		}
		break;
	case 4:
		if(LCD_u8GotoXY(LCDx,LCDy))
		{
			u8LCDState=3;
		}
		break;
	default:

		break;
	}

}

void LCD_vidGotoXY(uint8 x,uint8 y)
{
	u8x =x;u8y=y;
}
void LCD_vidWrite(uint8 u8data)
{
	if ((u8data != '\n') /*&& (u8data != '\r')*/ )
	{
		LCD_LINE[u8y][u8x++]=u8data;
		if(u8x>15)
		{
			u8x=0;
			if(++u8y>1)
			{
				u8y=0;
			}
		}
	}
	else
	{
		u8x=0;
		if(++u8y>1)
		{
			u8y=0;
		}
	}

}
void LCD_vidInit(void)
{
	u8LCDState=1;
}

void LCD_vidString (int8 I8String[])
{

	uint8 u8i =0;
	while (I8String[u8i])
	{
		LCD_vidWrite( I8String[u8i]);
		u8i++;
	}
}
void LCD_vidClear ()
{
	for (uint8 y =0;y<2;y++)
	{
		for(uint8 x =0 ;x<16;x++)
		{
			LCD_LINE[y][x]=' ';
		}
	}
	u8x=0;
	u8y=0;
}
