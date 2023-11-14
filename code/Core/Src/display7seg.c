/*
 * display7seg.c
 *
 *  Created on: Nov 10, 2023
 *      Author: Acer
 */
#include "display7seg.h"
void display7SEG( int num ){
    char LED7SEG [10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90 };
    for ( int i = 0; i < 7; ++ i) {
           HAL_GPIO_WritePin ( GPIOB , GPIO_PIN_0 << i , ( LED7SEG [num ] >> i ) & 1) ;}
     }
void pinenable(int a){
	if (a == 0){
		HAL_GPIO_WritePin(GPIOA, EN0_Pin, RESET);
        HAL_GPIO_WritePin(GPIOA, EN1_Pin, SET);
        HAL_GPIO_WritePin(GPIOA, EN2_Pin, SET);
        HAL_GPIO_WritePin(GPIOA, EN3_Pin, SET);
     }
     if (a == 1){
        HAL_GPIO_WritePin(GPIOA, EN0_Pin, SET);
        HAL_GPIO_WritePin(GPIOA, EN1_Pin, RESET);
        HAL_GPIO_WritePin(GPIOA, EN2_Pin, SET);
        HAL_GPIO_WritePin(GPIOA, EN3_Pin, SET);
      }
      if (a == 2){
        HAL_GPIO_WritePin(GPIOA, EN1_Pin, SET);
        HAL_GPIO_WritePin(GPIOA, EN0_Pin, SET);
        HAL_GPIO_WritePin(GPIOA, EN2_Pin, RESET);
        HAL_GPIO_WritePin(GPIOA, EN3_Pin, SET);
       }
       if (a == 3){
        HAL_GPIO_WritePin(GPIOA, EN1_Pin, SET);
        HAL_GPIO_WritePin(GPIOA, EN0_Pin, SET);
        HAL_GPIO_WritePin(GPIOA, EN2_Pin, SET);
        HAL_GPIO_WritePin(GPIOA, EN3_Pin, RESET);
        }
}

int MAX_LED = 4;
int index_led = 0;
int led_buffer [4] = {1 , 2 , 3 , 4};
void updateClockBuffer(){
     led_buffer[0] = count1 / 10;
     led_buffer[1] = count1 % 10;
     led_buffer[2] = count2 / 10;
     led_buffer[3] = count2 % 10;
}
void update7SEG ( int index ) {
     switch ( index ) {
       	case 0:
       		// Display the first 7 SEG with led_buffer [0]
       		display7SEG(led_buffer[0]);
       		pinenable(0);
       		break ;
     	case 1:
       		// Display the second 7 SEG with led_buffer [1]
      		display7SEG(led_buffer[1]);
       		pinenable(1);
       		break ;
       	case 2:
       		// Display the third 7 SEG with led_buffer [2]
       		display7SEG(led_buffer[2]);
       		pinenable(2);
       		break ;
       	case 3:
       		// Display the forth 7 SEG with led_buffer [3]
       		display7SEG(led_buffer[3]);
       		pinenable(3);
       	}
     }
void displaySEG(){
	  if (timer2_flag == 1){
	  setTimer2(250);
	  updateClockBuffer() ;
	  update7SEG(index_led);
	  index_led++;
	  if(index_led >= MAX_LED) index_led = 0;
	  }
}
