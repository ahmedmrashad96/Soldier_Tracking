/*
 * SWITCH_CFG.h
 *
 *  Created on: Dec 21, 2019
 *      Author: Ahmed Rashad
 */

#ifndef SWITCH_CFG_H_
#define SWITCH_CFG_H_


enum SWITCH_STATE{
	Released	=0,
	Pushed		=1,
	PreReleased =2,
	PrePushed	=3,
	SWITCH_STATE_Error
};

#define SENS_COUNT  3
#define PBN_COUNT	3

#define PBN_0	PORTB_5
#define PBN_1	PORTB_6
#define PBN_2	PORTB_7


#endif /* SWITCH_CFG_H_ */
