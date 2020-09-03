/*
 * GPS.h
 *
 *  Created on: Mar 12, 2020
 *      Author: Ahmed Rashad
 */

#ifndef GPS_H_
#define GPS_H_

#include "GPS_CFG.h"

void  GPS_vidInit ();
void  GPS_vidTask ();
GPS   GPS_u8GetData();
uint8 GPS_u8GetTime(int8 UTC[]);
uint8 GPS_u8GetLat(int8 LAT[]);
uint8 GPS_u8GetLon(int8 LON[]);
uint8 GPS_GetStatus();
void  GPS_vidUpdate();
GPS   GPS_READ ();
void  GPS_vidDisAttach ();
void  GPS_vidSelect();

#endif /* GPS_H_ */
