/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ����Ⱥ��824575535
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ����������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		ģ��IIC
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		tasking v6.3r1
 * @Target core		TC264D
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-3-23
 * @note		
					���߶��壺
					------------------------------------ 
						SCL                 �鿴SEEKFREE_IIC�ļ��ڵ�SEEKFREE_SCL�궨��
						SDA                 �鿴SEEKFREE_IIC�ļ��ڵ�SEEKFREE_SDA�궨��
					------------------------------------ 
 ********************************************************************************************************************/



#ifndef _SEEKFREE_IIC_h
#define _SEEKFREE_IIC_h


#include "common.h"




#define SEEKFREE_SCL    P02_3	//	//P02_3                           //����SCL����  ���������Ϊ����IO
#define SEEKFREE_SDA    P02_2	//	//P02_2                           //����SDA����  ���������Ϊ����IO


#define SEEKFREE_SCL1	P20_11
#define SEEKFREE_SDA1	P20_14


#define SIMIIC_DELAY_TIME	80	//60

typedef enum IIC       //DACģ��
{
    SIMIIC,
    SCCB
} IIC_type;



void  simiic_delay_set(uint16 time);
void  simiic_start(void);
void  simiic_stop(void);
void  simiic_ack_main(uint8 ack_main);
void  send_ch(uint8 c);
uint8 read_ch(uint8 ack);
void  simiic_write_reg(uint8 dev_add, uint8 reg, uint8 dat);
uint8 simiic_read_reg(uint8 dev_add, uint8 reg, IIC_type type);
void  simiic_read_regs(uint8 dev_add, uint8 reg, uint8 *dat_add, uint8 num, IIC_type type);
void  simiic_init(void);











#endif
