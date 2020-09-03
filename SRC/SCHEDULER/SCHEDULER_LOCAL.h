/*
 * SCHEDULER_LOCAL.h
 *
 *  Created on: Mar 17, 2020
 *      Author: Ahmed Rashad
 */

#ifndef SCHEDULER_LOCAL_H_
#define SCHEDULER_LOCAL_H_

#include "../COMMON/INTERRUPT.h"
#include "../COMMON/Std_Types.h"
#include "../COMMON/Utils.h"
#include "../TIMER/TIMER.h"

typedef struct {
    uint16 u16Periodicity;
    uint16 u16Offset;
    void (*TaskFunPtr)(void);

}task_t;

#endif /* SCHEDULER_LOCAL_H_ */
