/*
 * fsm_automatic.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Acer
 */

#include "fsm_automatic.h"
void fsm_automatic_run(){
	switch(status){
		case INIT:
			if(countRED == countGREEN + countAMBER){
				clearLED();
				timerGREEN = countGREEN;
				timerRED = countRED;
				setTimer1(1000);
				status = AUTO_RED1_GREEN2;
				clearLED();
			}
			if(countRED != countGREEN + countAMBER){
				count1 = 88;
				count2 = 88;
				if (timer1_flag == 1){
					setTimer1(250);
                blinkingLED();
				}
			}
			 if(isButton1Pressed() == 1){
				 status = MAN_RED;
				 clearLED();
				 setTimer1(250);
			}
			break;
		case AUTO_RED1_GREEN2:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
			HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, RESET);
			if (timer1_flag == 1){
				timerGREEN-- ;
				timerRED--;
				setTimer1(1000);
				if(timerGREEN <= 0 && timerRED <= countAMBER){
					status = AUTO_RED1_AMBER2;
					timerAMBER = countAMBER;
					clearLED();
				}
			}
			count1 = timerRED;
			count2 = timerGREEN;
			if(isButton1Pressed() == 1){
				status = MAN_RED;
				clearLED();
				setTimer2(250);
			}
			break;
		case AUTO_RED1_AMBER2:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
			HAL_GPIO_WritePin(LED_AMBER2_GPIO_Port, LED_AMBER2_Pin, RESET);
			if (timer1_flag == 1){
				timerAMBER-- ;
				timerRED--;
				setTimer1(1000);
				if(timerAMBER <= 0 ){
					status = AUTO_GREEN1_RED2;
					timerGREEN = countGREEN;
					timerRED = countRED;
					clearLED();
				}
			}
			count1 = timerRED;
			count2 = timerAMBER;
			 if(isButton1Pressed() == 1){
				 status = MAN_RED;
				 clearLED();
			     setTimer2(250);
			}
			break;
		case AUTO_GREEN1_RED2:
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);
			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, RESET);
			if (timer1_flag == 1){
				timerGREEN-- ;
				timerRED--;
				setTimer1(1000);
				if(timerGREEN <= 0 && timerRED <= countAMBER){
					status = AUTO_AMBER1_RED2;
					timerAMBER = 3;
					clearLED();
				}
			}
			count1 = timerGREEN;
			count2 = timerRED;
			 if(isButton1Pressed() == 1){
				 status = MAN_RED;
				 clearLED();
				 setTimer2(250);
			}
			break;
		case AUTO_AMBER1_RED2:
			HAL_GPIO_WritePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin, RESET);
			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, RESET);
			if (timer1_flag == 1){
				timerAMBER-- ;
				timerRED--;
				setTimer1(1000);
				if(timerAMBER <= 0){
					status = INIT;
				}
			}
			count1 = timerAMBER;
			count2 = timerRED;
			 if(isButton1Pressed() == 1){
				 status = MAN_RED;
				 clearLED();
				 setTimer2(250);
			}
			break;
		default:
			break;
}
}
