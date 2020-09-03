/*
 * UART.c
 *
 *  Created on: Feb 7, 2020
 *      Author: Ahmed Rashad
 */


#include	"UART_LOCAL.h"

static uint8 UART_INIT =0;
void UART_vidInit(void)
{
	uint16 	u16Baud;
	if(!UART_INIT)
	{
		UART_INIT =1;
		u16Baud =((FREQUENCY/16/UART_BAUDRATE)-1);

		UCSRA_R	=(0									<< UCSRA_U2X	)
				|(0									<< UCSRA_MPCM   );

		UCSRB_R =(1									<< UCSRB_RXEN   )
				|(1									<< UCSRB_TXEN   )
				|( Get_Bit(UART_CHRACTER_LENGTH,2)	<< UCSRB_UCSZ2  )
				|( UART_UDRE_INT					<< UCSRB_UDRIE  )
				|( UART_TXC_INT						<< UCSRB_TXCIE  )
				|( UART_RXC_INT						<< UCSRB_RXCIE  );

		UCSRC_R	=(1									<< UCSRC_URSEL  )
				|(0									<< UCSRC_UMSEL  )
				|( UART_PARITY_MODE					<< UCSRC_UPM_S  )
				|( UART_STOP_BITS					<< UCSRC_USBS   )
				|((UART_CHRACTER_LENGTH				<< UCSRC_UCZ_S	)&UCSRC_UCZ_M);

		UBRRL_R	=( u16Baud 	&0xff);
		UBRRH_R	=((u16Baud	>> 8 )& UBRRH_M);
	}
}
void UART_vidSendChar(uint8 u8Data)
{
	while (!(UCSRA_R&(1<<UCSRA_UDRE)));
	UDR_R = u8Data;
}

uint8 UART_u8RecieveChar(void)
{
	while (!(UCSRA_R&(1<<UCSRA_RXC)));
	return UDR_R ;
}
uint8 UART_u8DataReady()
{
	return (UCSRA_R&(1<<UCSRA_RXC));
}
uint8 UART_u8GetUdr()
{
	return UDR_R ;
}
void UART_vidSendString(uint8 u8Data[], uint8 length)
{
	for (uint8 i=0;i< length;i++)
	{
		UART_vidSendChar(u8Data[i]);
	}
}
uint8 UART_vidSendStringConfirmed(uint8 * u8Data)
{
	uint8 f =1;
	while(f&&*u8Data)
	{
		UART_vidSendChar(*(u8Data));
		f = (UART_u8RecieveChar()==*(u8Data++));
	}
	return f;
}

void UART_vidRecieveString(uint8 u8Data[], uint8* length)
{
	*length=0;
	do
	{
		u8Data[(*length)++]=UART_u8RecieveChar();
	}
	while(u8Data[(*length)-1]&&u8Data[(*length)-1]!='\r');
	u8Data[(*length)]=0;
}


#ifdef DEBUGGING
void _Debug(int8 u8Data[])
{
	uint8 i=0;
	if(!UART_INIT)
	{
		UART_vidInit();
	}
	do
	{
		UART_vidSendChar(u8Data[i]);
	}
	while (u8Data[++i]);
	UART_vidSendChar('\r');
}

void _Debug_value(uint32 u32Data)
{
	int8 arr[11]={0};
	uint8 i=0;
	uint32 x=1000000;
	while (!(u32Data/x))
	{
		x/=10;
	}
	if (x)
	{
		while (x)
		{
			arr[i++]=(u32Data/x)+'0';
			u32Data -=(u32Data/x)*x;
			x/=10;
		}
	}
	else
	{
		arr[i++]='0';
	}
	_Debug(arr);

}
#endif
