/*
 * GSM_API.c
 *
 *  Created on: Mar 12, 2020
 *      Author: Shourouk
 */

#include "GSM_LOCAL.h"

static int8  AT[]="AT\r";// To initialize mode
static int8  OK[]="OK\r\n";
static int8  Text_Mode[]="AT+CMGF=1\r";   // to set text mode
static uint8 Terminator=0x1A;     // uint8tacter form of control + z terminator uint8acter


static uint8 Str_Compare(int8 Str1[],int8 Str2[])
{
	uint8 i=0;
	while(Str1[i]==Str2[i]&&Str2[i])
	{
		i++;
	}
	return(!(Str1[i]||Str2[i]));
}

static void GSM_vidRecieveString(int8 uint8Data[], uint8* length)
{
	*length=0;
	do
	{
		uint8Data[(*length)++]=UART_u8RecieveChar();
	}
	while((uint8Data[(*length)-1])&&(uint8Data[(*length)-1]!='\n')&&(uint8Data[(*length)-1]!='>'));
	uint8Data[(*length)]=0;
}


uint8 GSMsend_to_modem(int8 sa[])   //function to write anything serially
{

	uint8 f=1 ;
	uint8 i=0 ;
//	UART_u8GetUdr();


	while(f&&sa[i])
	{
		UART_vidSendChar(sa[i]);
		if (sa[i]!=Terminator)
			f = (UART_u8RecieveChar()==sa[i++]);
		else
			f = (UART_u8RecieveChar()=='\r');
	}

	return f;

}

void GSM_vidInit()
{
	DIO_vidInit();
	DIO_u8SetPinDir(Selector,OUTPUT);
	UART_vidInit();
	DIO_u8SetPinDir(RXD,OUTPUT);
	DIO_u8SetPinDir(TXD,INPUT_PULLUP);

}

uint8 GSM_u8Startup()
{
	int8 Buffer[10]={0};
	uint8  Len=0;

	while(! GSMsend_to_modem(AT));
	GSM_vidRecieveString(Buffer,&Len);

	//compare between recieved and ok
	return Str_Compare(OK,Buffer);



}
uint8 GSM_vidSendSMS(int8  SMS[],int8  Num[] )
{

	uint8 u8Flag=1,LEN;
	int8 Buffer[20]={0};
	u8Flag=GSMsend_to_modem(Text_Mode);
	GSM_vidRecieveString(Buffer,&LEN);

	int8 Message_Command1[] = "AT+CMGS=\"";
	int8 Message_Command2[] = "\"\r";
	u8Flag = Str_Compare(Buffer,OK);

	if(u8Flag)
	{
		u8Flag&=GSMsend_to_modem(Message_Command1);
		u8Flag&=GSMsend_to_modem(Num);
		u8Flag&=GSMsend_to_modem(Message_Command2);
		GSM_vidRecieveString(Buffer,&LEN);
		u8Flag&= Str_Compare(Buffer,">");

		u8Flag&= GSMsend_to_modem(SMS);
		UART_vidSendChar(Terminator);

		GSM_vidRecieveString(Buffer,&LEN); // \r of terminator
		GSM_vidRecieveString(Buffer,&LEN); // +cmgs:xx
		GSM_vidRecieveString(Buffer,&LEN); // ok
		u8Flag&= Str_Compare(Buffer,"OK\r\n");

	}
	return u8Flag;
}

void GSM_vidSelect()
{
	DIO_u8WritePin(Selector,Select_GSM);
}
