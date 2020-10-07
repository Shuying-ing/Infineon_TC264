/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ����Ⱥ��824575535
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		main
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		tasking v6.3r1
 * @Target core		TC264D
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-3-23
 ********************************************************************************************************************/


#include "headfile.h"
#include "IfxCpu.h"


//IfxCpu_mutexLock mutexCpu0InitIsOk;]
#pragma section all "cpu0_psram"


extern uint8 towards_flag, stop_flag, get_angle_flag, adjust_angle_flag, adjust_angle_start_flag, successflag, backwards_flag;
extern uint32 towards_time;
extern int16 target_angle;
extern float32 target_distance, x, y, z, v;
uint32 adjust_interval=0;
uint8 waiting_flag=0;
uint8 z_times=0;



/* **********************************************
 * 		��1 && ��2
 * 	-------------------------
 *
 * CPU0:Initialize_core0_car1/2()
 *	 	ISR1:velovity_control_a/b()
 *
 * ***********************************************/


/* ==============================================================
 * 		ʵʱ�����Ƕ�adjust_angle_delta();
 *
 * 		����1��v
 * 			��1��2�ֿ�����
 * 		����2��z
 *			��v�й�
 *		����3��delay_time
 *			��v��z�й�
 * 		����4��adjust_interval
 * 			��v�ɷ���
 * 		����5��towards_time
 * 			���v
 * 		����6��stop_time
 * 			����һ��ֵ����֤�ǶȲɼ��ɿ�
 * ===============================================================*/


int core0_main(void)
{
	disableInterrupts();
	get_clk();	//��ȡʱ��Ƶ��  ��ر���

	Initialize_core0_car1();
//	Initialize_core0_car2();

    enableInterrupts();
	pit_interrupt_us(CCU6_0, PIT_CH0, 9933);


    while (TRUE)
    {
    	Update_Key_Status_ad();
    	set_value();
    	if(is_SW1_pressed())
    		lcd_disp();



/* -----------------------------------------------------------------------------------------
 *		һ������90�� ���̵����Ƕ�
 *			һ����������Ƕ� --> ��ֹһС��ʱ��ɼ�����
 *			����һ��ʱ���ڲ��� --> ����
 * -----------------------------------------------------


    	// z_control_ad
    	z_times = 0;
		while(target_angle!=90 && target_angle!=45 && target_angle!=135 && z_times<3)
		{
			if(z_times==0)	//��һ�ν�whileѭ��ֱ�ӿ�ʼ�����Ƕ�
				adjust_interval = 2221111112;

			x = v*cosf(target_angle*IFX_PI/180);
			y = v*sinf(target_angle*IFX_PI/180);	//��ʹ������interval����ȫ���ƶ�һ���

	    	systick_start(STM0);
	    	adjust_interval += systick_getval_us(STM0);
	    	if(get_angle_flag && adjust_angle_flag && adjust_interval>120000) //>100000	120000
	    	{
	    		if(target_angle>=0)
	    			z_times += 1;
	    		adjust_angle();
	    		get_angle_flag = 0;
	    		adjust_angle_flag = 0;
	    	}
	    	while(!adjust_angle_flag || !get_angle_flag)		//��֤target_angle��Ч
	    	{
	    		waiting_flag = 1;
	    	}
	    	waiting_flag = 0;
	    	towards_time = 0;
		}
		if(z_times==3)	//ԭ��תȦ����ȫ���ƶ�һ���
		{
			z_times = 0;
			x = v*cosf(target_angle*IFX_PI/180);
			y = v*sinf(target_angle*IFX_PI/180);
			delay(997);
		}

    	// x, y_control
		systick_start(STM1);	//��towards_stop()����ʹ��
		towards_stop();


//		// ����
//		if(backwards_flag)
//		{
//			target_angle = (target_angle+180)%360;
//			backwards();
//			backwards_flag = 0;
//		}
* */



/* -----------------------------------------------------------------------------------------
 *		ʵʱ�����Ƕ�
 *			һ����������Ƕ� --> ��ֹһС��ʱ��ɼ�����
 *			����һ��ʱ���ڲ��� --> ����
 * -----------------------------------------------------* */


		// z_control
    	systick_start(STM0);
    	adjust_interval += systick_getval_us(STM0);
    	if(adjust_angle_flag && adjust_interval>100000) //���ٶȳɷ���
    	{
    		adjust_angle_delta();
    		adjust_angle_flag = 0;
    		adjust_interval = 0;
    	}
    	if(!adjust_angle_flag)	//�Ƕȵ������
    	{
    		towards_flag = 0;
    		stop_flag = 1;
    		towards_time = 0;
    	}


    	// x, y_control
		systick_start(STM1);	//��towards_stop()����ʹ��
		towards_stop();


    	// ����
    	if(backwards_flag)
    	{
    		target_angle = (target_angle+180)%360;
    		backwards();
    		backwards_flag = 0;
    	}


    }

}

#pragma section all restore

