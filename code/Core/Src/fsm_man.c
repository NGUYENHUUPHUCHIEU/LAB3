/*
 * fsm_man.c
 *
 *  Created on: Nov 10, 2023
 *      Author: Acer
 */

#include"fsm_man.h"

void fsm_man_run(){
	switch(status){
		case MAN_RED:
			if (timer1_flag == 1){
				HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
				HAL_GPIO_TogglePin(LED_RED2_GPIO_Port, LED_RED2_Pin);
				setTimer1(250);
				}
			count1 = RED;
			count2 = 2;
			if(isButton2Pressed() == 1){
			   RED++;
			   if(RED > 99){
				   RED = 0;
			   }
			}
			if(isButton3Pressed() == 1){
				countRED = RED;
			}
			if(isButton1Pressed() == 1){
				status = MAN_AMBER;
				clearLED();
				setTimer1(250);
			}
			break;
		case MAN_AMBER:
			if (timer1_flag == 1){
				setTimer1(250);
				HAL_GPIO_TogglePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin);
			    HAL_GPIO_TogglePin(LED_AMBER2_GPIO_Port, LED_AMBER2_Pin);
				}
			count1 = AMBER;
			count2 = 3;
			if(isButton2Pressed() == 1){
			   AMBER++;
			   if(AMBER > 99){
				   AMBER = 0;
			   }
			}
			if(isButton3Pressed() == 1){
				countAMBER = AMBER;
			}
			if(isButton1Pressed() == 1){
				status = MAN_GREEN;
				clearLED();
				setTimer1(250);
			}
			break;
		case MAN_GREEN:
			if (timer1_flag == 1){
				setTimer1(250);
				HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
				HAL_GPIO_TogglePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
			}
			count1 = GREEN;
			count2 = 4;
			if(isButton2Pressed() == 1){
				GREEN++;
				if(GREEN > 99){
				GREEN = 0;
				}
			}
			if(isButton3Pressed() == 1){
				countGREEN = GREEN;
				}
			if(isButton1Pressed() == 1){
				status = INIT;
				clearLED();
				setTimer1(250);
			}
			break;
		default:
			break;
	}
}

