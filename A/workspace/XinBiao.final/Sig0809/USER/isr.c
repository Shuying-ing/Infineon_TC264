/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ����Ⱥ��824575535
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		isr
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		tasking v6.3r1
 * @Target core		TC264D
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-3-23
 ********************************************************************************************************************/

#include <others.h>
#include "isr_config.h"
#include "isr.h"
#include "IfxCpu.h"

#define size 2048


//��isr.c���жϺ�������������ĵڶ��������̶�Ϊ0���벻Ҫ���ģ���ʹ����CPU1�����ж�Ҳ��Ҫ���ģ���ҪCPU1�����ж�ֻ��Ҫ��isr_config.h���޸Ķ�Ӧ�ĺ궨�弴��
//extern IfxCpu_mutexLockmutexCpu0InitIsOk;


#pragma section all "cpu0_dsram"
int16 arr0[size];
int16 arr1[size];
int16 arr2[size];
int16 arr3[size];
#pragma section all restore


extern float32 x, y, z;
extern uint8 adjust_angle_ing_flag, stop_flag;
uint8 adc_flag;
uint16 cur_sample;
int16 fm[size];
int16 target_angle=-270, angle, last_angle=-1, last_target_angle;
uint8 get_angle_flag=0, adjust_angle_flag=0, adjust_angle_start_flag=0, backwards_flag=0;
float32 target_distance=0, last_target_distance=0;
float32 v=1.31;	//Plan1:0.56	Plan2:0.86
uint32 i, i_max=3;	//target_diatance��ͬ����


/* ���²�������data_show */
extern uint8 towards_flag, adjust_angle_ing_flag, waiting_flag, adjust_flag;
extern uint8 z_times;
extern uint32 towards_time;


IFX_INTERRUPT(cc60_pit_ch0_isr, 0, CCU6_0_CH0_ISR_PRIORITY)
{
	PIT_CLEAR_FLAG(CCU6_0, PIT_CH0);

	set_velocity(x, y, z);
	control_v1234_a();

//	data_show6(target_angle, target_distance, 3*z_times, 10*towards_flag, i, 15*backwards_flag);
}


IFX_INTERRUPT(cc60_pit_ch1_isr, 0, CCU6_0_CH1_ISR_PRIORITY)
{
	PIT_CLEAR_FLAG(CCU6_0, PIT_CH1);

}


IFX_INTERRUPT(cc61_pit_ch0_isr, 0, CCU6_1_CH0_ISR_PRIORITY)
{
	PIT_CLEAR_FLAG(CCU6_1, PIT_CH0);
//	if(IfxCpu_acquireMutex(&mutexCpu0InitIsOk))
//	{
//		data_show1(15);
//		IfxCpu_releaseMutex(&mutexCpu0InitIsOk);
//		systick_delay_ms(STM0,100);
//	}


	if(!adc_flag)	//�źŲɼ�ing
	{
		arr3[cur_sample]=adc_convert(ADC_1,ADC1_CH0_A16,ADC_12BIT)-1551;
		arr2[cur_sample]=adc_convert(ADC_0,ADC0_CH5_A5,ADC_12BIT)-1551;
		arr1[cur_sample]=adc_convert(ADC_0,ADC0_CH4_A4,ADC_12BIT)-1551;
		arr0[cur_sample]=adc_convert(ADC_1,ADC1_CH4_A20,ADC_12BIT)-1551;

		fm[cur_sample]=adc_convert(ADC_0,ADC0_CH12_A12,ADC_12BIT)-1100;	//a��
//		fm[cur_sample]=adc_convert(ADC_1,ADC1_CH1_A17,ADC_12BIT)-1100;	//b��

		cur_sample++;
		if(size==cur_sample)
		{
			cur_sample=0;
			adc_flag=1;
		}
		get_angle_flag = 1;
	}
	if(adc_flag)	//�źŲɼ����
	{
		// �Ƕȼ���
		angle=(direction(arr0,arr1,arr2,arr3)+180)%360;
		if(last_angle==angle)
			target_angle=angle;
		last_angle=angle;	//�Ƕ�����
		last_target_angle = target_angle;


		// �������
		target_distance=constrain_ad(0, 950, distance(arr0,fm));
		last_target_distance = target_distance;

		// �ж��Ƿ��Ѿ�ֹһ��ʱ��
		if((abs(last_target_distance-target_distance)<10)||(last_target_distance<950&&target_distance==950)||(last_target_distance==950&&target_distance<950))
		{
			if(!backwards_flag)
				i++;
		}
		if(target_distance==950 && i==1)	//��ֹͻȻ������ֵ
			i--;
		if(adjust_angle_ing_flag || stop_flag)	//���ڵ����Ƕ�or��ֹ�����¼���
			i = 0;
		if(i>i_max && !adjust_angle_ing_flag && !stop_flag)
		{
			backwards_flag = 1;
			i = 0;
		}

		adjust_angle_flag = 1;
		adc_flag = 0;
	}
}



IFX_INTERRUPT(cc61_pit_ch1_isr, 0, CCU6_1_CH1_ISR_PRIORITY)
{
	PIT_CLEAR_FLAG(CCU6_1, PIT_CH1);

}



IFX_INTERRUPT(eru_ch0_ch4_isr, 0, ERU_CH0_CH4_INT_PRIO)
{
	if(GET_GPIO_FLAG(ERU_CH0_REQ4_P10_7))//ͨ��0�ж�
	{
		CLEAR_GPIO_FLAG(ERU_CH0_REQ4_P10_7);
	}

	if(GET_GPIO_FLAG(ERU_CH4_REQ13_P15_5))//ͨ��4�ж�
	{
		CLEAR_GPIO_FLAG(ERU_CH4_REQ13_P15_5);
	}
}



IFX_INTERRUPT(eru_ch1_ch5_isr, 0, ERU_CH1_CH5_INT_PRIO)
{
	if(GET_GPIO_FLAG(ERU_CH1_REQ5_P10_8))//ͨ��1�ж�
	{
		CLEAR_GPIO_FLAG(ERU_CH1_REQ5_P10_8);
	}

	if(GET_GPIO_FLAG(ERU_CH5_REQ1_P15_8))//ͨ��5�ж�
	{
		CLEAR_GPIO_FLAG(ERU_CH5_REQ1_P15_8);
	}
}

//��������ͷpclk����Ĭ��ռ���� 2ͨ�������ڴ���DMA��������ﲻ�ٶ����жϺ���
//IFX_INTERRUPT(eru_ch2_ch6_isr, ERU_CH2_CH6_INT_SERVICE, ERU_CH2_CH6_INT_PRIO)
//{
//	if(GET_GPIO_FLAG(ERU_CH2_REQ7_P00_4))//ͨ��2�ж�
//	{
//		CLEAR_GPIO_FLAG(ERU_CH2_REQ7_P00_4);
//
//	}
//	if(GET_GPIO_FLAG(ERU_CH6_REQ9_P20_0))//ͨ��6�ж�
//	{
//		CLEAR_GPIO_FLAG(ERU_CH6_REQ9_P20_0);
//
//	}
//}



IFX_INTERRUPT(eru_ch3_ch7_isr, 0, ERU_CH3_CH7_INT_PRIO)
{
	if(GET_GPIO_FLAG(ERU_CH3_REQ6_P02_0))//ͨ��3�ж�
	{
		CLEAR_GPIO_FLAG(ERU_CH3_REQ6_P02_0);
		if		(1 == camera_type)	mt9v03x_vsync();
		else if	(3 == camera_type)	ov7725_vsync();

	}
	if(GET_GPIO_FLAG(ERU_CH7_REQ16_P15_1))//ͨ��7�ж�
	{
		CLEAR_GPIO_FLAG(ERU_CH7_REQ16_P15_1);

	}
}



IFX_INTERRUPT(dma_ch5_isr, 0, ERU_DMA_INT_PRIO)
{

	if		(1 == camera_type)	mt9v03x_dma();
	else if	(3 == camera_type)	ov7725_dma();
}


//�����жϺ���  ʾ��
IFX_INTERRUPT(uart0_tx_isr, 0, UART0_TX_INT_PRIO)
{
    IfxAsclin_Asc_isrTransmit(&uart0_handle);
}
IFX_INTERRUPT(uart0_rx_isr, 0, UART0_RX_INT_PRIO)
{
    IfxAsclin_Asc_isrReceive(&uart0_handle);
}
IFX_INTERRUPT(uart0_er_isr, 0, UART0_ER_INT_PRIO)
{
    IfxAsclin_Asc_isrError(&uart0_handle);
}

//����1Ĭ�����ӵ�����ͷ���ô���
IFX_INTERRUPT(uart1_tx_isr, 0, UART1_TX_INT_PRIO)
{
    IfxAsclin_Asc_isrTransmit(&uart1_handle);
}
IFX_INTERRUPT(uart1_rx_isr, 0, UART1_RX_INT_PRIO)
{
    IfxAsclin_Asc_isrReceive(&uart1_handle);
    mt9v03x_uart_callback();
}
IFX_INTERRUPT(uart1_er_isr, 0, UART1_ER_INT_PRIO)
{
    IfxAsclin_Asc_isrError(&uart1_handle);
}


//����2Ĭ�����ӵ�����ת����ģ��
IFX_INTERRUPT(uart2_tx_isr, 0, UART2_TX_INT_PRIO)
{
    IfxAsclin_Asc_isrTransmit(&uart2_handle);
}
IFX_INTERRUPT(uart2_rx_isr, 0, UART2_RX_INT_PRIO)
{
    IfxAsclin_Asc_isrReceive(&uart2_handle);
    wireless_uart_callback();
}
IFX_INTERRUPT(uart2_er_isr, 0, UART2_ER_INT_PRIO)
{
    IfxAsclin_Asc_isrError(&uart2_handle);
}



IFX_INTERRUPT(uart3_tx_isr, 0, UART3_TX_INT_PRIO)
{
    IfxAsclin_Asc_isrTransmit(&uart3_handle);
}
IFX_INTERRUPT(uart3_rx_isr, 0, UART3_RX_INT_PRIO)
{
    IfxAsclin_Asc_isrReceive(&uart3_handle);
}
IFX_INTERRUPT(uart3_er_isr, 0, UART3_ER_INT_PRIO)
{
    IfxAsclin_Asc_isrError(&uart3_handle);
}
