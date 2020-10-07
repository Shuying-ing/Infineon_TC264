/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：三群：824575535
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		main
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598)
 * @version    		查看doc内version文件 版本说明
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
 * 		车1 && 车2
 * 	-------------------------
 *
 * CPU0:Initialize_core0_car1/2()
 *	 	ISR1:velovity_control_a/b()
 *
 * ***********************************************/


/* ==============================================================
 * 		实时调整角度adjust_angle_delta();
 *
 * 		参数1：v
 * 			车1车2分开处理
 * 		参数2：z
 *			与v有关
 *		参数3：delay_time
 *			与v、z有关
 * 		参数4：adjust_interval
 * 			与v成反比
 * 		参数5：towards_time
 * 			配合v
 * 		参数6：stop_time
 * 			大于一定值，保证角度采集可靠
 * ===============================================================*/


int core0_main(void)
{
	disableInterrupts();
	get_clk();	//获取时钟频率  务必保留

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
 *		一旦不是90° 立刻调整角度
 *			一定间隔调整角度 --> 静止一小段时间采集数据
 *			距离一定时间内不变 --> 后退
 * -----------------------------------------------------


    	// z_control_ad
    	z_times = 0;
		while(target_angle!=90 && target_angle!=45 && target_angle!=135 && z_times<3)
		{
			if(z_times==0)	//第一次进while循环直接开始调整角度
				adjust_interval = 2221111112;

			x = v*cosf(target_angle*IFX_PI/180);
			y = v*sinf(target_angle*IFX_PI/180);	//即使不满足interval，先全向移动一会儿

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
	    	while(!adjust_angle_flag || !get_angle_flag)		//保证target_angle有效
	    	{
	    		waiting_flag = 1;
	    	}
	    	waiting_flag = 0;
	    	towards_time = 0;
		}
		if(z_times==3)	//原地转圈，先全向移动一会儿
		{
			z_times = 0;
			x = v*cosf(target_angle*IFX_PI/180);
			y = v*sinf(target_angle*IFX_PI/180);
			delay(997);
		}

    	// x, y_control
		systick_start(STM1);	//和towards_stop()配套使用
		towards_stop();


//		// 后退
//		if(backwards_flag)
//		{
//			target_angle = (target_angle+180)%360;
//			backwards();
//			backwards_flag = 0;
//		}
* */



/* -----------------------------------------------------------------------------------------
 *		实时调整角度
 *			一定间隔调整角度 --> 静止一小段时间采集数据
 *			距离一定时间内不变 --> 后退
 * -----------------------------------------------------* */


		// z_control
    	systick_start(STM0);
    	adjust_interval += systick_getval_us(STM0);
    	if(adjust_angle_flag && adjust_interval>100000) //和速度成反比
    	{
    		adjust_angle_delta();
    		adjust_angle_flag = 0;
    		adjust_interval = 0;
    	}
    	if(!adjust_angle_flag)	//角度调整完成
    	{
    		towards_flag = 0;
    		stop_flag = 1;
    		towards_time = 0;
    	}


    	// x, y_control
		systick_start(STM1);	//和towards_stop()配套使用
		towards_stop();


    	// 后退
    	if(backwards_flag)
    	{
    		target_angle = (target_angle+180)%360;
    		backwards();
    		backwards_flag = 0;
    	}


    }

}

#pragma section all restore

