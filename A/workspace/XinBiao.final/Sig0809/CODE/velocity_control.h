/*
 * velocity_control.h
 *
 *  Created on: 2020��8��4��
 *      Author: QSY
 */

#ifndef CODE_VELOCITY_CONTROL_H_
#define CODE_VELOCITY_CONTROL_H_

#include "common.h"


/* -------------------------------------------
 *	�³�1-velocity_control_a.c
 * ------------------------------------------*/
#define MOTOR4_B   ATOM1_CH6_P02_6   //����4�����תPWM����	//RL
#define MOTOR4_A   ATOM1_CH7_P02_7   //����4�����תPWM����

#define MOTOR3_A   ATOM1_CH0_P21_2   //����3�����תPWM����	//FR
#define MOTOR3_B   ATOM0_CH1_P21_3   //����3�����תPWM����

#define MOTOR2_B   ATOM0_CH4_P02_4  //����2�����תPWM����		//RR
#define MOTOR2_A   ATOM0_CH5_P02_5   //����2�����תPWM����

#define MOTOR1_B   ATOM0_CH2_P21_4   //����1�����תPWM����	//FL
#define MOTOR1_A   ATOM0_CH3_P21_5   //����1�����תPWM����



/* -------------------------------------------
 *	�³�2-velocity_control_b.c
 * ------------------------------------------*/
#define MOTOR44_A   ATOM1_CH6_P02_6   //����4�����תPWM����	//RL
#define MOTOR44_B   ATOM1_CH7_P02_7   //����4�����תPWM����

#define MOTOR33_B   ATOM1_CH0_P21_2   //����3�����תPWM����	//FR
#define MOTOR33_A   ATOM0_CH1_P21_3   //����3�����תPWM����

#define MOTOR22_A   ATOM0_CH4_P02_4   //����2�����תPWM����	//RR
#define MOTOR22_B   ATOM0_CH5_P02_5   //����2�����תPWM����

#define MOTOR11_B   ATOM0_CH2_P21_4   //����1�����תPWM����	//FL
#define MOTOR11_A   ATOM0_CH3_P21_5   //����1�����תPWM����




/* velocity_control_a.c */
void control_v1_a(float32 exp_speed);
void control_v2_a(float32 exp_speed);
void control_v3_a(float32 exp_speed);
void control_v4_a(float32 exp_speed);
void control_v1234_a(void);
void set_velocity(float32 x,float32 y,float32 z);
float constrain_ad(float lowerBoundary, float upperBoundary, float input);



/* velocity_control_b.c */
void control_v1_b(float32 exp_speed);
void control_v2_b(float32 exp_speed);
void control_v3_b(float32 exp_speed);
void control_v4_b(float32 exp_speed);
void control_v1234_b(void);



/* key_control.c */
void Update_Key_Status(void);
int is_key3_pressed(void);
int is_key4_pressed(void);
void set_value_a(void);
void set_value_b(void);


/* key_control_ad.c */
int is_SW1_pressed(void);
int is_key2_pressed_ad(void);
int is_key3_pressed_ad(void);
void Update_Key_Status_ad(void);
void set_value(void);


/* lcd_disp.c */
void lcd_disp_key1(void);
void lcd_disp_key2(void);


/* lcd_disp_ad.c */
void lcd_disp(void);


#endif /* CODE_VELOCITY_CONTROL_H_ */
