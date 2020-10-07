/*
 * Initialize_all.c
 *
 *  Created on: 2020年8月17日
 *      Author: QSY
 */


#include "headfile.h"



void Initialize_core0_car1(void)
{
	gtm_pwm_init(MOTOR1_A, 17000, 0);
	gtm_pwm_init(MOTOR1_B, 17000, 0);
	gtm_pwm_init(MOTOR2_A, 17000, 0);
	gtm_pwm_init(MOTOR2_B, 17000, 0);
	gtm_pwm_init(MOTOR3_A, 17000, 0);
	gtm_pwm_init(MOTOR3_B, 17000, 0);
	gtm_pwm_init(MOTOR4_A, 17000, 0);
	gtm_pwm_init(MOTOR4_B, 17000, 0);


	//编码器初始化
	gpt12_init(GPT12_T2, GPT12_T2INB_P33_7, GPT12_T2EUDB_P33_6);	//FL
	gpt12_init(GPT12_T6, GPT12_T6INA_P20_3, GPT12_T6EUDA_P20_0);	//FR
	gpt12_init(GPT12_T4, GPT12_T4INA_P02_8, GPT12_T4EUDA_P00_9);	//RR
	gpt12_init(GPT12_T5, GPT12_T5INB_P10_3, GPT12_T5EUDB_P10_1);	//RL

	//按键初始化
    gpio_init(P22_0,GPI,0,PULLUP);
    gpio_init(P22_1,GPI,0,PULLUP);
    gpio_init(P22_2,GPI,0,PULLUP);
    gpio_init(P22_3,GPI,0,PULLUP);

    //拨码开关初始化
    gpio_init(P33_12,GPI,0,PULLUP);
    gpio_init(P33_13,GPI,0,PULLUP);

	seekfree_wireless_init();
	lcd_init();
}


void Initialize_core0_car2(void)
{
	gtm_pwm_init(MOTOR11_A, 17000, 0);
	gtm_pwm_init(MOTOR11_B, 17000, 0);
	gtm_pwm_init(MOTOR22_A, 17000, 0);
	gtm_pwm_init(MOTOR22_B, 17000, 0);
	gtm_pwm_init(MOTOR33_A, 17000, 0);
	gtm_pwm_init(MOTOR33_B, 17000, 0);
	gtm_pwm_init(MOTOR44_A, 17000, 0);
	gtm_pwm_init(MOTOR44_B, 17000, 0);


	//编码器初始化
	gpt12_init(GPT12_T2, GPT12_T2INB_P33_7, GPT12_T2EUDB_P33_6);	//FL
	gpt12_init(GPT12_T6, GPT12_T6INA_P20_3, GPT12_T6EUDA_P20_0);	//FR
	gpt12_init(GPT12_T4, GPT12_T4INA_P02_8, GPT12_T4EUDA_P00_9);	//RR
	gpt12_init(GPT12_T5, GPT12_T5INB_P10_3, GPT12_T5EUDB_P10_1);	//RL

	//按键初始化
    gpio_init(P22_0,GPI,0,PULLUP);
    gpio_init(P22_1,GPI,0,PULLUP);
    gpio_init(P22_2,GPI,0,PULLUP);
    gpio_init(P22_3,GPI,0,PULLUP);

    //拨码开关初始化
    gpio_init(P33_12,GPI,0,PULLUP);
    gpio_init(P33_13,GPI,0,PULLUP);


	seekfree_wireless_init();
	lcd_init();
}


void Initialize_core1(void)
{
	adc_init(ADC_0,ADC0_CH4_A4);	//1adc
	adc_init(ADC_1,ADC1_CH0_A16);	//0adc
	adc_init(ADC_1,ADC1_CH4_A20);	//2adc
	adc_init(ADC_0,ADC0_CH5_A5);	//3adc

	adc_init(ADC_0,ADC0_CH12_A12);	//a车
	adc_init(ADC_1,ADC1_CH1_A17);	//b车

	rda5807_init(95.0);
    seekfree_wireless_init();
}




