/*
 * key_control_ad.c
 *
 *  Created on: 2020年8月23日
 *      Author: QSY
 */


#include "headfile.h"


int key1_ReadFlag=0, current_status=0, status = 8;
extern int key3_last_status, key3_status, key4_last_status, key4_status;
extern float32 v, angle_v, back_v;
extern uint32 towards_time_max, stop_time_max, i_max;
extern uint16 backwards_time, adjust_angle_time;


int is_SW1_pressed(void)
{
	return(gpio_get(P33_12));
}


int is_key2_pressed_ad(void){
	key3_last_status = key3_status;
	key3_status = gpio_get(P22_2);
    if(key3_status && !key3_last_status)	return 1;
    else return 0;
}

int is_key3_pressed_ad(void){
	key4_last_status = key4_status;
	key4_status = gpio_get(P22_1);
    if(key4_status && !key4_last_status)	return 1;
    else return 0;
}


// -----------------------------------------------------------------------------------------------------------
//
//	key1模式*8:		v, towards_time, stop_time, angle_v, adjust_angle_time, back_v, backwards_time, i_max
//
// -----------------------------------------------------------------------------------------------------------

void Update_Key_Status_ad(void)
{
	if(gpio_get(P22_3)) key1_ReadFlag = 1;
	if(!gpio_get(P22_3) && key1_ReadFlag)
	{
		current_status = (current_status + 1) % status;
		key1_ReadFlag = 0;
	}
}

void set_value(void)
{
	switch(current_status)
	{
		case 0:
			if(is_key2_pressed_ad()) v += 0.04;
			if(is_key3_pressed_ad()) v -= 0.04;
			break;
		case 1:
			if(is_key2_pressed_ad()) towards_time_max += 1000;
			if(is_key3_pressed_ad()) towards_time_max -= 1000;
			break;
		case 2:
			if(is_key2_pressed_ad()) stop_time_max += 1000;
			if(is_key3_pressed_ad()) stop_time_max -= 1000;
			break;
		case 3:
			if(is_key2_pressed_ad()) angle_v += 0.03;
			if(is_key3_pressed_ad()) angle_v -= 0.03;
			break;
		case 4:
			if(is_key2_pressed_ad()) adjust_angle_time += 10;
			if(is_key3_pressed_ad()) adjust_angle_time -= 10;
			break;
		case 5:
			if(is_key2_pressed_ad()) back_v += 0.02;
			if(is_key3_pressed_ad()) back_v -= 0.02;
			break;
		case 6:
			if(is_key2_pressed_ad()) backwards_time += 10;
			if(is_key3_pressed_ad()) backwards_time -= 10;
			break;
		case 7:
			if(is_key2_pressed_ad()) i_max += 1;
			if(is_key3_pressed_ad()) i_max -= 1;
			break;
	}
}


