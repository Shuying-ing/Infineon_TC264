/*
 * velocity_control_a.c
 *
 *  Created on: 2020年8月21日
 *      Author: QSY
 */



#include "headfile.h"

/*
 *
 * 增量式PID ##新车1##
 *
 * ********************************** */

uint8 periodv=10;  //控制速度的周期
float32 exp_speed1, exp_speed2, exp_speed3, exp_speed4;
int16 exp_rotate1, exp_rotate2, exp_rotate3, exp_rotate4;
int16 cur_rotate1, cur_rotate2, cur_rotate3, cur_rotate4;


/* ******************************************************************************
 *
 * 不知道哪儿来的 ##增量式PID## 调参原则
 *
 * 增大ki，使接近实际速度；切换目标速度时，产生抖动{超调}
 * 		【个人理解：等幅振荡】
 * 增大kp，缓减抖动
 * 		【个人理解:最初尖峰消失】
 *
 * -----------------------------------------------------------------
 *
 * 增大Ki，出现尖峰 \//\ 增大Kp，尖峰消失 /\/\ 增大Ki，加快速度
 *
 * *****************************************************************************/
float Kp1 = 39, Ki1 = 2.5, Kd1 = 0;	//25 13
float Kp2 = 34, Ki2 = 2.7, Kd2 = 0;	//30 15
float Kp3 = 34, Ki3 = 1.9, Kd3 = 0;	//30 16
float Kp4 = 32, Ki4 = 2.2, Kd4 = 0;	//25 13
float Out_increment_1, Out_increment_2, Out_increment_3, Out_increment_4;
float Out_1, Out_2, Out_3, Out_4;
float Ek_1, Ek1_1, Ek2_1, Ek_2, Ek1_2, Ek2_2, Ek_3, Ek1_3, Ek2_3, Ek_4, Ek1_4, Ek2_4;
int32 Motor_duty1, Motor_duty2, Motor_duty3, Motor_duty4;
float Delta_duty_max = 2200;



void control_v4_a(float32 exp_speed)	//RL
{
	cur_rotate4 = gpt12_get(GPT12_T5);
	gpt12_clear(GPT12_T5);

	exp_rotate4 = exp_speed*periodv*2/0.0843262;

	Ek2_4 = Ek1_4;							//上上次误差
	Ek1_4 = Ek_4; 							//上次误差
	Ek_4 = exp_rotate4 - cur_rotate4;		//当前误差

	Out_increment_4 = constrain_ad(-Delta_duty_max, Delta_duty_max, Kp4*(Ek_4-Ek1_4) + Ki4*Ek_4 + Kd4*(Ek_4-2*Ek1_4+Ek2_4));
	Out_4 = constrain_ad(-5000, 5000, Out_4 + Out_increment_4);

	Motor_duty4 = (int32)Out_4;
	if(0<=Motor_duty4)	//电机4   正转
	{
		pwm_duty(MOTOR4_B, Motor_duty4);
		pwm_duty(MOTOR4_A, 0);
	}
	else          		//电机4   反转
	{
		pwm_duty(MOTOR4_B, 0);
		pwm_duty(MOTOR4_A, -Motor_duty4);
	}
}

void control_v3_a(float32 exp_speed)	//FR
{
	cur_rotate3 = gpt12_get(GPT12_T6);
	gpt12_clear(GPT12_T6);

	exp_rotate3 = exp_speed*periodv*2/0.0843262;

	Ek2_3 = Ek1_3;							//上上次误差
	Ek1_3 = Ek_3; 							//上次误差
	Ek_3 = exp_rotate3 - cur_rotate3;		//当前误差

	Out_increment_3 = constrain_ad(-Delta_duty_max, Delta_duty_max, Kp3*(Ek_3-Ek1_3) + Ki3*Ek_3 + Kd3*(Ek_3-2*Ek1_3+Ek2_3));
	Out_3 = constrain_ad(-5000, 5000, Out_3 + Out_increment_3);

	Motor_duty3 = (int32)Out_3;
	if(0<=Motor_duty3)	//电机3   正转
	{
		pwm_duty(MOTOR3_B, Motor_duty3);
		pwm_duty(MOTOR3_A, 0);
	}
	else          		//电机3  反转
	{
		pwm_duty(MOTOR3_B, 0);
		pwm_duty(MOTOR3_A, -Motor_duty3);
	}
}

void control_v2_a(float32 exp_speed)	//RR
{
	cur_rotate2 = gpt12_get(GPT12_T4);
	gpt12_clear(GPT12_T4);

	exp_rotate2 = exp_speed*periodv*2/0.0843262;

	Ek2_2 = Ek1_2;							//上上次误差
	Ek1_2 = Ek_2; 							//上次误差
	Ek_2 = exp_rotate2 - cur_rotate2;		//当前误差

	Out_increment_2 = constrain_ad(-Delta_duty_max, Delta_duty_max, Kp2*(Ek_2-Ek1_2) + Ki2*Ek_2 + Kd2*(Ek_2-2*Ek1_2+Ek2_2));
	Out_2 = constrain_ad(-5000, 5000, Out_2 + Out_increment_2);

	Motor_duty2 = (int32)Out_2;
	if(0<=Motor_duty2)	//电机2   正转
	{
		pwm_duty(MOTOR2_A, Motor_duty2);
		pwm_duty(MOTOR2_B, 0);
	}
	else          		//电机2   反转
	{
		pwm_duty(MOTOR2_A, 0);
		pwm_duty(MOTOR2_B, -Motor_duty2);
	}
}

void control_v1_a(float32 exp_speed)	//FL
{
	cur_rotate1 = gpt12_get(GPT12_T2);
	gpt12_clear(GPT12_T2);

	exp_rotate1 = exp_speed*periodv*2/0.0843262;

	Ek2_1 = Ek1_1;							//上上次误差
	Ek1_1 = Ek_1; 							//上次误差
	Ek_1 = exp_rotate1 - cur_rotate1;		//当前误差

	Out_increment_1 = constrain_ad(-Delta_duty_max, Delta_duty_max, Kp1*(Ek_1-Ek1_1) + Ki1*Ek_1 + Kd1*(Ek_1-2*Ek1_1+Ek2_1));
	Out_1 = constrain_ad(-5000, 5000, Out_1 + Out_increment_1);

	Motor_duty1 = (int32)Out_1;
	if(0<=Motor_duty1)	//电机1   正转
	{
		pwm_duty(MOTOR1_B, Motor_duty1);
		pwm_duty(MOTOR1_A, 0);
	}
	else          		//电机1   反转
	{
		pwm_duty(MOTOR1_B, 0);
		pwm_duty(MOTOR1_A, -Motor_duty1);
	}
}


void control_v1234_a(void)
{
	control_v1_a(exp_speed1);
	control_v2_a(exp_speed2);
	control_v3_a(exp_speed3);
	control_v4_a(exp_speed4);
}


void set_velocity(float32 x,float32 y,float32 z)
{
	//* 纵向移动 四个 y 相同
	//* 横向移动 对侧 x 相同
	//* 旋转移动 一侧 z 相同
	exp_speed1 = -x + y + z;
	exp_speed2 = x + y + z;
	exp_speed3 = -x - y + z;
	exp_speed4 = x - y + z;
}


float constrain_ad(float lowerBoundary, float upperBoundary, float input)
{
	if (input > upperBoundary)
		return upperBoundary;
	else if (input < lowerBoundary)
		return lowerBoundary;
	else
		return input;
}



