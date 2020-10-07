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
#pragma section all "cpu1_dsram"


//extern IfxCpu_mutexLock mutexCpu0InitIsOk;


void core1_main(void)
{
	disableInterrupts();
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
    systick_delay_ms(STM0,500);


    Initialize_core1();


    enableInterrupts();
    pit_interrupt_us(CCU6_1, PIT_CH0, 100);

    //while(IfxCpu_releaseMutex(&mutexCpu0InitIsOk));
    //while(!IfxCpu_acquireMutex(&cpu0));

    while (TRUE)
    {
//    	if(IfxCpu_acquireMutex(&mutexCpu0InitIsOk))
//    	{
//    		data_show1(15);
//    		IfxCpu_releaseMutex(&mutexCpu0InitIsOk);
//    		systick_delay_ms(STM0,100);
//    	}

    }
}

#pragma section all restore
