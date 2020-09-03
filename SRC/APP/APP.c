/*
 * APP.c
 *
 *  Created on: Apr 4, 2020
 *      Author: shena
 */


#include "../COMMON/Std_Types.h"
#include "../COMMON/Utils.h"
#include "../COMMON/INTERRUPT.h"

#include "../LCD/LCD.h"
#include "../TIMER/TIMER.h"
#include "../DIO/DIO.h"
#include "../TEMP_SENSOR/TEMP_SENSOR.h"

#include "../GSM/GSM.h"
#include "../GPS/GPS.h"
#include "../SWITCH/SWITCH.h"

#define Selector PORTC_0
#define Select_GSM LOW
#define Select_GPS HIGH
#define NAM_LENGTH 	15
#define TMP_LENGTH	4


//#define APP_update 0
//#define APP_uptodate 1
//uint8 APP_state=APP_update;


typedef struct {
	int8 Name[NAM_LENGTH];
	int8 TEMP[TMP_LENGTH];
	int8 LON [LON_LENGTH];
	int8 LAT [LAT_LENGTH];
	uint8 FIX;
}SOLDIER;

int8 mobile_number[3][15]={"+0201553130804","+201210674670","+201273041399"};


typedef enum{
	APP_STATE_INIT=1,
	APP_STATE_WAIT=2,
	APP_STATE_SENS=3,
	APP_STATE_PBNS=4,
	APP_STATE_LCD =5,
	APP_STATE_SMS =6,
	APP_STATE_MAX
}APP_STATE;

static uint8 LAST_STATE=0,APP_State=0;

void APP_vidInit()
{
	APP_State=APP_STATE_INIT;
}
static void APP_vidInitTask()
{
	SW_vidInit();
	LCD_vidInit();
	TEMP_SENSOR_vidInit();
	GPS_vidInit();
	GSM_vidInit();

}
static uint8 u8flagPBN1=0,u8flagPBN2=0,u8flagPBN3=0,u8flagGPS=0,u8flagTEMP=0;
static void APP_vidWaitTask()
{
//	static uint8 u8Counter=0;
	if(u8flagPBN1||u8flagPBN2||u8flagPBN3);

}
static void APP_vidSensTask()
{


}
static void APP_vidLCDTask()
{

}
static void APP_vidPBNSTask()
{

}
static void APP_vidSMSTask()
{

}




void APP_vidTask()
{
	/*
	 * init
	 *
	 * read sensors
	 *
	 * wait while reading pbns and update lcd
	 *
	 * send sms
	 *
	 *
	 */


	switch (APP_State)
	{
	case APP_STATE_INIT:
		APP_vidInitTask();
		break;
	case APP_STATE_WAIT:
		APP_vidWaitTask();
		break;
	case APP_STATE_SENS:
		APP_vidSensTask();
		break;
	case APP_STATE_LCD:
		APP_vidLCDTask();
		break;
	case APP_STATE_PBNS:
		APP_vidPBNSTask();
		break;
	case APP_STATE_SMS:
		APP_vidSMSTask();
		break;
	default:
		break;
	}


}

static uint8 str_concat (int8 str1[],int8 str2[])
{
	uint8 i=0,j=0;
	while (str1[i])
	{
		i++;
	}
	while (str2[j])
	{
		str1[i++]=str2[j++];
	}
	str1[i]=0;
	return i;
}

uint8 x[20];
int main(void)
{
	int8 message[50]={0};
	GPS Data ;
	_delay_ms(100);






	GSM_vidSelect();
	while(!GSM_u8Startup());


	GPS_vidSelect();
	Data = GPS_READ();

	GSM_vidSelect();
	GPS_vidDisAttach();

	SOLDIER x={"Mr. XYZ","XXX","NOT Valid","NOT Valid",0};
	x.FIX=1;
	x.FIX&=GPS_u8GetLat(x.LAT);
	x.FIX&=GPS_u8GetLon(x.LON);
	TEMP_SENSOR_u16GetData(x.TEMP);

	str_concat(message,"Name: ");
	str_concat(message,x.Name);
	str_concat(message,"\r");
	str_concat(message,"Temp:");
	str_concat(message,x.TEMP);
	if(!x.FIX)
	{
		str_concat(message,"Last Known LOC");
	}
	str_concat(message,"\r");
	str_concat(message,"LAT: ");
	str_concat(message,x.LAT);
	str_concat(message,"\r");
	str_concat(message,"LON: ");
	str_concat(message,x.LON);
	str_concat(message,"\r");
	LCD_vidString(x.TEMP);


	uint8 i=0;
	while(1)
	{
		////		switch (APP_state)
		////		{
		////
		////		}
		////
		////
		//		if(APP_state==APP_update)
		//		{
		//			GPS_u8GetLat(x.LAT);
		//			GPS_u8GetLon(x.LON);
		//			TEMP_SENSOR_u16GetData(x.TEMP);
		//
		//
		//			APP_state = APP_uptodate;
		//		}
		if (SW_u8Read(arr[(i++)%3])== Pushed) // active low
		{
			GSM_vidSendSMS(message,mobile_number[(i-1)%3]);
		}

	}

}
//
//void (*fun[])()={LCD_vidTask,SW_vidTask};
////uint32 update_time=0;
//ISR(TIMER0_COMP_VECTOR_NUM )
//{
////	if((update_time++)>20000)
////	{
////		update_time=0;
////		APP_state=APP_update;
////	}
//	fun[(updatetime())%2]();
//
//}

