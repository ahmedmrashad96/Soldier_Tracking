/*
 * GSM.h
 *
 *  Created on: Apr 4, 2020
 *      Author: shena
 */

#ifndef GSM_GSM_H_
#define GSM_GSM_H_


uint8 GSM_vidInit();
uint8 GSM_u8Startup();
uint8 GSM_vidSendSMS(int8  SMS[],int8  Num[] );
void GSM_vidSelect();

#endif /* GSM_GSM_H_ */
