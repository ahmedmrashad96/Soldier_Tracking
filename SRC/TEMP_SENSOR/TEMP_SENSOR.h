/*
 * TEMP_SENSOR.h
 *
 *  Created on: Apr 4, 2020
 *      Author: shena
 */

#ifndef TEMP_SENSOR_TEMP_SENSOR_H_
#define TEMP_SENSOR_TEMP_SENSOR_H_

#include "TEMP_SENSOR_CFG.h"
void TEMP_SENSOR_vidInit();
uint16 TEMP_SENSOR_u16GetData(int8 TEMP_ARR[]);
#endif /* TEMP_SENSOR_TEMP_SENSOR_H_ */
