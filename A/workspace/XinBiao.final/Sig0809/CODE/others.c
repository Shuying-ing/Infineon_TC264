/*
 * others.c
 *
 *  Created on: 2020��8��12��
 *      Author: QSY
 */

#include "headfile.h"



/* ---------------------------------
 * ��λ����������
 * ---------------------------------*/

#define BYTE0(dwTemp)       ( *( (char *)(&dwTemp)	  ) )     /*!< uint32_t ���ݲ�� byte0  */
#define BYTE1(dwTemp)       ( *( (char *)(&dwTemp) + 1) )     /*!< uint32_t ���ݲ�� byte1  */
#define BYTE2(dwTemp)       ( *( (char *)(&dwTemp) + 2) )     /*!< uint32_t ���ݲ�� byte2  */
#define BYTE3(dwTemp)       ( *( (char *)(&dwTemp) + 3) )     /*!< uint32_t ���ݲ�� byte3  */


uint8 data_to_send[50]={0};

void data_show1(int16 data1)
{
    uint8  _cnt=0;
	uint8  sum = 0, i = 0;
    data_to_send[_cnt++] = 0xAA;      //����Э��֡ͷ  0xAAAA
	data_to_send[_cnt++] = 0xAA;
	data_to_send[_cnt++] = 0xF1;      //ʹ���û�Э��֡0xF1
    data_to_send[_cnt++] = 2;        //8��int16_t ���� 16���ֽ�

	data_to_send[_cnt++]=BYTE1(data1);
	data_to_send[_cnt++]=BYTE0(data1);

    sum = 0;
	for(i=0;i<_cnt;i++)
		sum += data_to_send[i];
	data_to_send[_cnt++]=sum;

	uart_putbuff(WIRELESS_UART,data_to_send,_cnt);
}

void data_show2(int16 data1, int16 data2)
{
    uint8  _cnt=0;
	uint8  sum = 0, i = 0;
    data_to_send[_cnt++] = 0xAA;      //����Э��֡ͷ  0xAAAA
	data_to_send[_cnt++] = 0xAA;
	data_to_send[_cnt++] = 0xF1;      //ʹ���û�Э��֡0xF1
    data_to_send[_cnt++] = 4;        //8��int16_t ���� 16���ֽ�

	data_to_send[_cnt++]=BYTE1(data1);
	data_to_send[_cnt++]=BYTE0(data1);

	data_to_send[_cnt++]=BYTE1(data2);
	data_to_send[_cnt++]=BYTE0(data2);

    sum = 0;
	for(i=0;i<_cnt;i++)
		sum += data_to_send[i];
	data_to_send[_cnt++]=sum;

	uart_putbuff(WIRELESS_UART,data_to_send,_cnt);
}

void data_show3(int16 data1, int16 data2,int16 data3)
{
    uint8  _cnt=0;
	uint8  sum = 0, i = 0;
    data_to_send[_cnt++] = 0xAA;      //����Э��֡ͷ  0xAAAA
	data_to_send[_cnt++] = 0xAA;
	data_to_send[_cnt++] = 0xF1;      //ʹ���û�Э��֡0xF1
    data_to_send[_cnt++] = 6;        //8��int16_t ���� 16���ֽ�

	data_to_send[_cnt++]=BYTE1(data1);
	data_to_send[_cnt++]=BYTE0(data1);

	data_to_send[_cnt++]=BYTE1(data2);
	data_to_send[_cnt++]=BYTE0(data2);

	data_to_send[_cnt++]=BYTE1(data3);
	data_to_send[_cnt++]=BYTE0(data3);

    sum = 0;
	for(i=0;i<_cnt;i++)
		sum += data_to_send[i];
	data_to_send[_cnt++]=sum;

	uart_putbuff(WIRELESS_UART,data_to_send,_cnt);
}

void data_show4(int16 data1, int16 data2,int16 data3,int16 data4)
{
    uint8  _cnt=0;
	uint8  sum = 0, i = 0;
    data_to_send[_cnt++] = 0xAA;      //����Э��֡ͷ  0xAAAA
	data_to_send[_cnt++] = 0xAA;
	data_to_send[_cnt++] = 0xF1;      //ʹ���û�Э��֡0xF1
    data_to_send[_cnt++] = 8;        //8��int16_t ���� 16���ֽ�

	data_to_send[_cnt++]=BYTE1(data1);
	data_to_send[_cnt++]=BYTE0(data1);

	data_to_send[_cnt++]=BYTE1(data2);
	data_to_send[_cnt++]=BYTE0(data2);

	data_to_send[_cnt++]=BYTE1(data3);
	data_to_send[_cnt++]=BYTE0(data3);


	data_to_send[_cnt++]=BYTE1(data4);
	data_to_send[_cnt++]=BYTE0(data4);


    sum = 0;
	for(i=0;i<_cnt;i++)
		sum += data_to_send[i];
	data_to_send[_cnt++]=sum;

	uart_putbuff(WIRELESS_UART,data_to_send,_cnt);
}

void data_show5(int16 data1, int16 data2, int16 data3, int16 data4, int16 data5)
{
    uint8  _cnt=0;
	uint8  sum = 0, i = 0;
    data_to_send[_cnt++] = 0xAA;      //����Э��֡ͷ  0xAAAA
	data_to_send[_cnt++] = 0xAA;
	data_to_send[_cnt++] = 0xF1;      //ʹ���û�Э��֡0xF1
    data_to_send[_cnt++] = 10;        //8��int16_t ���� 16���ֽ�

	data_to_send[_cnt++]=BYTE1(data1);
	data_to_send[_cnt++]=BYTE0(data1);

	data_to_send[_cnt++]=BYTE1(data2);
	data_to_send[_cnt++]=BYTE0(data2);

	data_to_send[_cnt++]=BYTE1(data3);
	data_to_send[_cnt++]=BYTE0(data3);

	data_to_send[_cnt++]=BYTE1(data4);
	data_to_send[_cnt++]=BYTE0(data4);

	data_to_send[_cnt++]=BYTE1(data5);
	data_to_send[_cnt++]=BYTE0(data5);


    sum = 0;
	for(i=0;i<_cnt;i++)
		sum += data_to_send[i];
	data_to_send[_cnt++]=sum;

	uart_putbuff(WIRELESS_UART,data_to_send,_cnt);
}

void data_show6(int16 data1, int16 data2,int16 data3,int16 data4,int16 data5,int16 data6)
{
    uint8  _cnt=0;
	uint8  sum = 0, i = 0;
    data_to_send[_cnt++] = 0xAA;      //����Э��֡ͷ  0xAAAA
	data_to_send[_cnt++] = 0xAA;
	data_to_send[_cnt++] = 0xF1;      //ʹ���û�Э��֡0xF1
    data_to_send[_cnt++] = 12;        //8��int16_t ���� 16���ֽ�

	data_to_send[_cnt++]=BYTE1(data1);
	data_to_send[_cnt++]=BYTE0(data1);

	data_to_send[_cnt++]=BYTE1(data2);
	data_to_send[_cnt++]=BYTE0(data2);

	data_to_send[_cnt++]=BYTE1(data3);
	data_to_send[_cnt++]=BYTE0(data3);

	data_to_send[_cnt++]=BYTE1(data4);
	data_to_send[_cnt++]=BYTE0(data4);

	data_to_send[_cnt++]=BYTE1(data5);
	data_to_send[_cnt++]=BYTE0(data5);

	data_to_send[_cnt++]=BYTE1(data6);
	data_to_send[_cnt++]=BYTE0(data6);

    sum = 0;
	for(i=0;i<_cnt;i++)
		sum += data_to_send[i];
	data_to_send[_cnt++]=sum;

	uart_putbuff(WIRELESS_UART,data_to_send,_cnt);
}

void data_show7(int16 data1, int16 data2,int16 data3,int16 data4,int16 data5,int16 data6,int16 data7)
{
    uint8  _cnt=0;
	uint8  sum = 0, i = 0;
    data_to_send[_cnt++] = 0xAA;      //����Э��֡ͷ  0xAAAA
	data_to_send[_cnt++] = 0xAA;
	data_to_send[_cnt++] = 0xF1;      //ʹ���û�Э��֡0xF1
    data_to_send[_cnt++] = 14;        //8��int16_t ���� 16���ֽ�

	data_to_send[_cnt++]=BYTE1(data1);
	data_to_send[_cnt++]=BYTE0(data1);

	data_to_send[_cnt++]=BYTE1(data2);
	data_to_send[_cnt++]=BYTE0(data2);

	data_to_send[_cnt++]=BYTE1(data3);
	data_to_send[_cnt++]=BYTE0(data3);

	data_to_send[_cnt++]=BYTE1(data4);
	data_to_send[_cnt++]=BYTE0(data4);

	data_to_send[_cnt++]=BYTE1(data5);
	data_to_send[_cnt++]=BYTE0(data5);

	data_to_send[_cnt++]=BYTE1(data6);
	data_to_send[_cnt++]=BYTE0(data6);

	data_to_send[_cnt++]=BYTE1(data7);
	data_to_send[_cnt++]=BYTE0(data7);

    sum = 0;
	for(i=0;i<_cnt;i++)
		sum += data_to_send[i];
	data_to_send[_cnt++]=sum;

	uart_putbuff(WIRELESS_UART,data_to_send,_cnt);
}

void data_show8(int16 data1, int16 data2,int16 data3,int16 data4,int16 data5,int16 data6,int16 data7,int16 data8)
{
    uint8  _cnt=0;
	uint8  sum = 0, i = 0;
    data_to_send[_cnt++] = 0xAA;      //����Э��֡ͷ  0xAAAA
	data_to_send[_cnt++] = 0xAA;
	data_to_send[_cnt++] = 0xF1;      //ʹ���û�Э��֡0xF1
    data_to_send[_cnt++] = 16;        //8��int16_t ���� 16���ֽ�

	data_to_send[_cnt++]=BYTE1(data1);
	data_to_send[_cnt++]=BYTE0(data1);

	data_to_send[_cnt++]=BYTE1(data2);
	data_to_send[_cnt++]=BYTE0(data2);

	data_to_send[_cnt++]=BYTE1(data3);
	data_to_send[_cnt++]=BYTE0(data3);

	data_to_send[_cnt++]=BYTE1(data4);
	data_to_send[_cnt++]=BYTE0(data4);

	data_to_send[_cnt++]=BYTE1(data5);
	data_to_send[_cnt++]=BYTE0(data5);

	data_to_send[_cnt++]=BYTE1(data6);
	data_to_send[_cnt++]=BYTE0(data6);

	data_to_send[_cnt++]=BYTE1(data7);
	data_to_send[_cnt++]=BYTE0(data7);

	data_to_send[_cnt++]=BYTE1(data8);
	data_to_send[_cnt++]=BYTE0(data8);

    sum = 0;
	for(i=0;i<_cnt;i++)
		sum += data_to_send[i];
	data_to_send[_cnt++]=sum;

	uart_putbuff(WIRELESS_UART,data_to_send,_cnt);
}

