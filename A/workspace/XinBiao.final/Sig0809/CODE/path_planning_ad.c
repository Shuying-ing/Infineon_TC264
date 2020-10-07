/*
 * path_planning_ad.c
 *
 *  Created on: 2020��8��5��
 *      Author: QSY
 */

#include "headfile.h"


extern uint8 obstacle_45, obstacle_135, obstacle_left, obstacle_right, get_angle_flag, adjust_angle_flag, waiting_flag;
extern float32 target_distance;
extern int16 target_angle, last_angle, last_target_angle;
extern float32 v;

float32 x, y, z, k, angle_v=1.14, back_v=0.85;
uint8 successflag=0, towards_flag=1, stop_flag=0, near_flag=0, adjust_angle_ing_flag=0;
uint32 towards_time, stop_time;
uint32 towards_time_max=435000, stop_time_max=40500;	//433000 52000
uint16 backwards_time=220, adjust_angle_time=198;	//220	198


void obstacle_avoid(void)
{
	if(target_angle==90)
	{
		z = 0;
		if(obstacle_left)	//�ϰ��������
			x = 0.2;
		if(obstacle_right)
			x = -0.2;
		delay(300);
		x = 0;
	}

	if(target_angle==45&&obstacle_45)
	{
		x = z = 0;
		delay(300);
		x = y;
	}

	if(target_angle==135&&obstacle_135)
	{
		x = z = 0;
		delay(300);
		x = -y;
	}

	obstacle_left = obstacle_right = obstacle_45 = obstacle_135 = 0;
}



/* �ж��Ƿ�ɹ� */
void judge_if_success(void)
{

	if(successflag==0 && target_distance<=75)	//�ӽ��ű�
		near_flag = 1;

	if(target_distance>100 && target_distance<=900 && near_flag)	//Ŀ���ű�over�������һ�ξ���
	{
		x = 0;
		y = -0.3;
		z = 0;
		delay(300);

		near_flag = 0;
		successflag = 1;
	}

}


/* ǰ��-��ֹ-ǰ��-��ֹ���Ƕ�ʶ��׼ȷ */
void towards_stop(void)
{
	if(last_target_angle!=target_angle)	//�Ƕȸı䣬���¼���ǰ��ʱ��
		towards_time = 0;

	if(towards_flag && !stop_flag)	//ǰ��ing
	{
		towards_time += systick_getval_us(STM1);
		x = v*cosf(target_angle*IFX_PI/180);
		y = v*sinf(target_angle*IFX_PI/180);
	}
	if(towards_time>towards_time_max)	//��ĳһ����ǰ��ʱ�䳬��xxx΢��	//Plan1:v=0.49_293000	0.53_253000		Plan2:v=0.86_433000
	{
		towards_time = 0;
		towards_flag = 0;
		stop_flag = 1;
	}
	if(!towards_flag && stop_flag)	//��ֹing
	{
		stop_time += systick_getval_us(STM1);
		x = y = 0;
	}
	if(stop_time>stop_time_max)	//��ֹʱ�䳬��xxx΢��		//Plan1:77000	Plan2:50000
	{
		while(!adjust_angle_flag || !get_angle_flag) {waiting_flag = 1;}	//��֤target_angle��Ч
		stop_time = 0;
		stop_flag = 0;
		towards_flag = 1;
	}
}


/* ���ˣ�if��ʱ�侲ֹ */
void backwards(void)
{
	x = back_v*cosf(target_angle*IFX_PI/180);
	y = back_v*sinf(target_angle*IFX_PI/180);
	z = 0;
	delay(backwards_time);	//120
}


/* ��תһ��de�Ƕ�(ʵʱ����) */
void adjust_angle_delta(void)
{
	adjust_angle_ing_flag = 1;
//	x = y = 0;	//ʵʱor����

	if(target_angle==45||target_angle==0||target_angle==315)
		z = -angle_v;	//1.01
	if(target_angle==135||target_angle==180||target_angle==225)
		z = angle_v;
	delay(adjust_angle_time);

	z = 0;
	adjust_angle_ing_flag = 0;
}


/* �����Ƕ�_ֱ��תΪǰ������ */
void adjust_angle(void)
{
	k = 0.84;	//k1=0.9	k2=0.85
	adjust_angle_ing_flag = 1;
	x = y = 0;

	//1.6+delay(250)---80 �⻬
	switch(target_angle)
	{
		case -1:
			z = 0;
			break;
		case 315:
			z = -1*k;
			delay(300);
			break;
		case 0:
			z = -1.1*k;
			delay(250);
			break;
		case 45:
			z = -0.9*k;
			delay(100);
			break;
		case 90:
			z = 0;
			break;
		case 135:
			z = 0.9*k;
			delay(100);
			break;
		case 180:
			z = 1.1*k;
			delay(250);
			break;
		case 225:
			z = 1.1*k;
			delay(300);
			break;
		case 270:
			z = 1.1*k;
			delay(395);
			break;
	}
	z = 0;
	adjust_angle_ing_flag = 0;
	delay(1287);	//998 adjust_interval=120000
}


/* ��ʱ_΢�� */
void delay(uint16 delay_time)
{
//	uint32 t=0;
//	while (t < delay_time) {
//		systick_start(STM1);			//ʹ��STM1 ���м�ʱ
//		systick_delay_ms(STM0, 10);		//��ʱ100MS  ʹ��STM0��ʱ��  Ҳ����ʹ��STM1��ʱ��
//		t += systick_getval_ms(STM1);	//��ȡSTM1��ʱʱ��
//	}

	uint32 count = 66666*delay_time;
	while(count>0)
		count--;
}



