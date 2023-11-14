/*
 * display7seg.h
 *
 *  Created on: Nov 10, 2023
 *      Author: Acer
 */

#ifndef INC_DISPLAY7SEG_H_
#define INC_DISPLAY7SEG_H_

#include "fsm_automatic.h"

void display7SEG( int num );
void pinenable(int a);
void updateClockBuffer();
void update7SEG ( int index );
void displaySEG();


#endif /* INC_DISPLAY7SEG_H_ */
