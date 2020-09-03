/*
 * GPS_CFG.h
 *
 *  Created on: Mar 12, 2020
 *      Author: Ahmed Rashad
 */

#ifndef GPS_CFG_H_
#define GPS_CFG_H_

#define UTC_LENGTH 15
#define LAT_LENGTH 13
#define LON_LENGTH 14

enum {

	GPS_OutDated    = 0,
	GPS_UpDating    = 1,
	GPS_UpToDate    = 2,
	GPS_FreshData   = 3,
	GPS_STATES_MAX

}GPS_STATES;



typedef struct {
	int8 UTC[UTC_LENGTH];
	int8 LAT[LAT_LENGTH];
	int8 LON[LON_LENGTH];
	uint8 FIX;
}GPS;

#define Selector PORTC_0
#define Select_GPS HIGH


#endif /* GPS_CFG_H_ */
