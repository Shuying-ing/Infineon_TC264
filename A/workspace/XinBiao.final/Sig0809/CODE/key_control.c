/*
 * key_control.c
 *
 *  Created on: 2020年8月4日
 *      Author: QSY
 */

#include "headfile.h"


int key1ReadFlag = 0, key2ReadFlag = 0;
int key1_status = 0;
int key2_status_xyz = 0, key2_status_M1 = 0, key2_status_M2 = 0, key2_status_M3 = 0, key2_status_M4 = 0;
int key3_last_status, key3_status = 0;
int key4_last_status, key4_status = 0;
int Num_of_Status1 = 5, Num_of_Status2 = 3;
extern float32 x, y, z;
extern float kp_4, ki_4, kd_4, kp_3, ki_3, kd_3, kp_2, ki_2, kd_2, kp_1, ki_1, kd_1;	//新车2
extern float Kp1, Ki1, Kd1, Kp2, Ki2, Kd2, Kp3, Ki3, Kd3, Kp4, Ki4, Kd4;	//新车1



// -------------------------------------------------------------
//
//	key1模式*5：		xyz, Motor1, Motor2, Motor3, Motor4
//	key2对应模式*3：	xyz, pid   , pid   , pid   , pid
//
// -------------------------------------------------------------
void Update_Key_Status(void)
{
	if(gpio_get(P22_0)) key1ReadFlag = 1;
	if(!gpio_get(P22_0) && key1ReadFlag)
	{
		key1_status = (key1_status + 1) % Num_of_Status1;
		key1ReadFlag = 0;
	}

	if(gpio_get(P22_1)) key2ReadFlag = 1;
	if(!gpio_get(P22_1) && key2ReadFlag)
	{
		if(key1_status==0) key2_status_xyz = (key2_status_xyz + 1) % Num_of_Status2;
		else if(key1_status==1) key2_status_M1 = (key2_status_M1 + 1) % Num_of_Status2;
		else if(key1_status==2) key2_status_M2 = (key2_status_M2 + 1) % Num_of_Status2;
		else if(key1_status==3) key2_status_M3 = (key2_status_M3 + 1) % Num_of_Status2;
		else key2_status_M4 = (key2_status_M4 + 1) % Num_of_Status2;
		key2ReadFlag = 0;
	}
}

int is_key3_pressed(void){
	key3_last_status = key3_status;
	key3_status = gpio_get(P22_2);
    if(key3_status && !key3_last_status)	return 1;
    else return 0;
}

int is_key4_pressed(void){
	key4_last_status = key4_status;
	key4_status = gpio_get(P22_3);
    if(key4_status && !key4_last_status)	return 1;
    else return 0;
}




/* 增量式PID-新车2 */
void set_value_b(void)
{
	if(key1_status==0){		//set_xyz
		switch(key2_status_xyz){
			case 0:
				if(is_key3_pressed()) x += 0.2;
				if(is_key4_pressed()) x -= 0.2;
				break;
			case 1:
				if(is_key3_pressed()) y += 0.2;
				if(is_key4_pressed()) y -= 0.2;
				break;
			case 2:
				if(is_key3_pressed()) z += 0.2;
				if(is_key4_pressed()) z -= 0.2;
				break;
		}
	}
	else if(key1_status==1){		//set_Motor1_car2
		switch(key2_status_M1){
			case 0:
				if(is_key3_pressed()) kp_1 += 1;
				if(is_key4_pressed()) kp_1 -= 1;
				break;
			case 1:
				if(is_key3_pressed()) ki_1 += 1;
				if(is_key4_pressed()) ki_1 -= 1;
				break;
			case 2:
				if(is_key3_pressed()) kd_1 += 1;
				if(is_key4_pressed()) kd_1 -= 1;
				break;
		}
	}
	else if(key1_status==2){		//set_Motor2_car2
		switch(key2_status_M2){
			case 0:
				if(is_key3_pressed()) kp_2 += 1;
				if(is_key4_pressed()) kp_2 -= 1;
				break;
			case 1:
				if(is_key3_pressed()) ki_2 += 1;
				if(is_key4_pressed()) ki_2 -= 1;
				break;
			case 2:
				if(is_key3_pressed()) kd_2 += 1;
				if(is_key4_pressed()) kd_2 -= 1;
				break;
		}
	}
	else if(key1_status==3){		//set_Motor3_car2
		switch(key2_status_M3){
			case 0:
				if(is_key3_pressed()) kp_3 += 1;
				if(is_key4_pressed()) kp_3 -= 1;
				break;
			case 1:
				if(is_key3_pressed()) ki_3 += 1;
				if(is_key4_pressed()) ki_3 -= 1;
				break;
			case 2:
				if(is_key3_pressed()) kd_3 += 1;
				if(is_key4_pressed()) kd_3 -= 1;
				break;
		}
	}
	else if(key1_status==4){		//set_Motor4_car2
		switch(key2_status_M4){
			case 0:
				if(is_key3_pressed()) kp_4 += 1;
				if(is_key4_pressed()) kp_4 -= 1;
				break;
			case 1:
				if(is_key3_pressed()) ki_4 += 1;
				if(is_key4_pressed()) ki_4 -= 1;
				break;
			case 2:
				if(is_key3_pressed()) kd_4 += 1;
				if(is_key4_pressed()) kd_4 -= 1;
				break;
		}
	}
}



/* 增量式PID-新车1 */
void set_value_a(void)
{
	if(key1_status==0){		//set_xyz
		switch(key2_status_xyz){
			case 0:
				if(is_key3_pressed()) x += 0.1;
				if(is_key4_pressed()) x -= 0.1;
				break;
			case 1:
				if(is_key3_pressed()) y += 0.1;
				if(is_key4_pressed()) y -= 0.1;
				break;
			case 2:
				if(is_key3_pressed()) z += 0.1;
				if(is_key4_pressed()) z -= 0.1;
				break;
		}
	}
	else if(key1_status==1){		//set_Motor1_car1
		switch(key2_status_M1){
			case 0:
				if(is_key3_pressed()) Kp1 += 1;
				if(is_key4_pressed()) Kp1 -= 1;
				break;
			case 1:
				if(is_key3_pressed()) Ki1 += 1;
				if(is_key4_pressed()) Ki1 -= 1;
				break;
			case 2:
				if(is_key3_pressed()) Kd1 += 0.5;
				if(is_key4_pressed()) Kd1 -= 0.5;
				break;
		}
	}
	else if(key1_status==2){		//set_Motor2_car1
		switch(key2_status_M2){
			case 0:
				if(is_key3_pressed()) Kp2 += 1;
				if(is_key4_pressed()) Kp2 -= 1;
				break;
			case 1:
				if(is_key3_pressed()) Ki2 += 1;
				if(is_key4_pressed()) Ki2 -= 1;
				break;
			case 2:
				if(is_key3_pressed()) Kd2 += 1;
				if(is_key4_pressed()) Kd2 -= 1;
				break;
		}
	}
	else if(key1_status==3){		//set_Motor3_car1
		switch(key2_status_M3){
			case 0:
				if(is_key3_pressed()) Kp3 += 1;
				if(is_key4_pressed()) Kp3 -= 1;
				break;
			case 1:
				if(is_key3_pressed()) Ki3 += 1;
				if(is_key4_pressed()) Ki3 -= 1;
				break;
			case 2:
				if(is_key3_pressed()) Kd3 += 1;
				if(is_key4_pressed()) Kd3 -= 1;
				break;
		}
	}
	else if(key1_status==4){		//set_Motor4_car1
		switch(key2_status_M4){
			case 0:
				if(is_key3_pressed()) Kp4 += 1;
				if(is_key4_pressed()) Kp4 -= 1;
				break;
			case 1:
				if(is_key3_pressed()) Ki4 += 1;
				if(is_key4_pressed()) Ki4 -= 1;
				break;
			case 2:
				if(is_key3_pressed()) Kd4 += 1;
				if(is_key4_pressed()) Kd4 -= 1;
				break;
		}
	}
}
