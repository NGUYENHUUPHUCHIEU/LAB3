/*
 * global.h
 *
 *  Created on: Nov 2, 2023
 *      Author: Acer
 */
#include "software_timer.h"
#include"main.h"
#include "input_reading.h"
#include"display7seg.h"

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define INIT               1
#define AUTO_RED1_GREEN2   2
#define AUTO_RED1_AMBER2   3
#define AUTO_GREEN1_RED2   4
#define AUTO_AMBER1_RED2   5

#define MAN_RED            6
#define MAN_GREEN          7
#define MAN_AMBER          8

extern int status, timerRED, timerGREEN, timerAMBER;
extern int countRED, countGREEN, countAMBER, count1, count2 ;
extern int MAX_LED, index_led;
extern int RED, GREEN, AMBER;
void clearLED();
void blinkingLED();

#endif /* INC_GLOBAL_H_ */
