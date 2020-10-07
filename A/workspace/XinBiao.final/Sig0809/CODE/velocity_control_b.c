/*
 * velocity_control_b.c
 *
 *  Created on: 2020年8月21日
 *      Author: QSY
 */


#include "headfile.h"

/*
 *
 * 增量式PID ##新车2##
 *
 * ********************************** */


/* 此处 extern ∵velocity_control_a.c中已有定义 */
extern uint8 periodv;
extern float32 exp_speed1, exp_speed2, exp_speed3, exp_speed4;
extern int16 exp_rotate1, exp_rotate2, exp_rotate3, exp_rotate4;
extern int16 cur_rotate1, cur_rotate2, cur_rotate3, cur_rotate4;


float kp_1 = 47, ki_1 = 24, kd_1 = 0;
float kp_2 = 40, ki_2 = 24, kd_2 = 0;
float kp_3 = 50, ki_3 = 23, kd_3 = 0;
float kp_4 = 20, ki_4 = 22, kd_4 = 0;
float out_increment_1, out_increment_2, out_increment_3, out_increment_4;
float out_1, out_2, out_3, out_4;
float ek_1, ek1_1, ek2_1, ek_2, ek1_2, ek2_2, ek_3, ek1_3, ek2_3, ek_4, ek1_4, ek2_4;
int32 motor_duty1, motor_duty2, motor_duty3, motor_duty4;
float delta_duty_max = 2255;


void control_v4_b(float32 exp_speed)
{
	cur_rotate4 = gpt12_get(GPT12_T5);
	gpt12_clear(GPT12_T5);

	exp_rotate4 = exp_speed*periodv/0.0843262;


	ek2_4 = ek1_4;							//上上次误差
	ek1_4 = ek_4; 							//上次误差
	ek_4 = exp_rotate4 - cur_rotate4;		//当前误差

	out_increment_4 = constrain_ad(-delta_duty_max, delta_duty_max, kp_4*(ek_4-ek1_4) + ki_4*ek_4 + kd_4*(ek_4-2*ek1_4+ek2_4));
	out_4 = constrain_ad(-5000, 5000, out_4 + out_increment_4);

	motor_duty4 = (int32)out_4;
	if(0<=motor_duty4)	//电机4   正转
	{
		pwm_duty(MOTOR44_B, motor_duty4);
		pwm_duty(MOTOR44_A, 0);
	}
	else          		//电机4   反转
	{
		pwm_duty(MOTOR44_B, 0);
		pwm_duty(MOTOR44_A, -motor_duty4);
	}

}


void control_v3_b(float32 exp_speed)
{
	cur_rotate3 = gpt12_get(GPT12_T6);
	gpt12_clear(GPT12_T6);

	exp_rotate3 = exp_speed*periodv/0.0843262;


	ek2_3 = ek1_3;							//上上次误差
	ek1_3 = ek_3; 							//上次误差
	ek_3 = exp_rotate3 - cur_rotate3;		//当前误差

	out_increment_3 = constrain_ad(-delta_duty_max, delta_duty_max, kp_3*(ek_3-ek1_3) + ki_3*ek_3 + kd_3*(ek_3-2*ek1_3+ek2_3));
	out_3 = constrain_ad(-5000, 5000, out_3 + out_increment_3);

	motor_duty3 = (int32)out_3;
	if(0<=motor_duty3)	//电机3   正转
	{
		pwm_duty(MOTOR33_B, motor_duty3);
		pwm_duty(MOTOR33_A, 0);
	}
	else          		//电机3  反转
	{
		pwm_duty(MOTOR33_B, 0);
		pwm_duty(MOTOR33_A, -motor_duty3);
	}

}


void control_v2_b(float32 exp_speed)
{
	cur_rotate2 = gpt12_get(GPT12_T4);
	gpt12_clear(GPT12_T4);

	exp_rotate2 = exp_speed*periodv/0.0843262;


	ek2_2 = ek1_2;							//上上次误差
	ek1_2 = ek_2; 							//上次误差
	ek_2 = exp_rotate2 - cur_rotate2;		//当前误差

	out_increment_2 = constrain_ad(-delta_duty_max, delta_duty_max, kp_2*(ek_2-ek1_2) + ki_2*ek_2 + kd_2*(ek_2-2*ek1_2+ek2_2));
	out_2 = constrain_ad(-5000, 5000, out_2 + out_increment_2);

	motor_duty2 = (int32)out_2;
	if(0<=motor_duty2)	//电机2   正转
	{
		pwm_duty(MOTOR22_A, motor_duty2);
		pwm_duty(MOTOR22_B, 0);
	}
	else          		//电机2   反转
	{
		pwm_duty(MOTOR22_A, 0);
		pwm_duty(MOTOR22_B, -motor_duty2);
	}

}


void control_v1_b(float32 exp_speed)
{
	cur_rotate1 = gpt12_get(GPT12_T2);
	gpt12_clear(GPT12_T2);

	exp_rotate1 = exp_speed*periodv/0.0843262;


	ek2_1 = ek1_1;							//上上次误差
	ek1_1 = ek_1; 							//上次误差
	ek_1 = exp_rotate1 - cur_rotate1;		//当前误差

	out_increment_1 = constrain_ad(-delta_duty_max, delta_duty_max, kp_1*(ek_1-ek1_1) + ki_1*ek_1 + kd_1*(ek_1-2*ek1_1+ek2_1));
	out_1 = constrain_ad(-5000, 5000, out_1 + out_increment_1);

	motor_duty1 = (int32)out_1;
	if(0<=motor_duty1)	//电机1   正转
	{
		pwm_duty(MOTOR11_B, motor_duty1);
		pwm_duty(MOTOR11_A, 0);
	}
	else          		//电机1   反转
	{
		pwm_duty(MOTOR11_B, 0);
		pwm_duty(MOTOR11_A, -motor_duty1);
	}

}


void control_v1234_b(void)
{
	control_v1_b(exp_speed1);
	control_v2_b(exp_speed2);
	control_v3_b(exp_speed3);
	control_v4_b(exp_speed4);
}



