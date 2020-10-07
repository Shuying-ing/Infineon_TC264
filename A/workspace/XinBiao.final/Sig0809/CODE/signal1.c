/*
 * signal1.c
 *
 *  Created on: 2020年8月4日
 *      Author: ASUS
 */

#include "headfile.h"
#include "SysSe/Math/Ifx_FftF32.h"
#define SAMPLE_FREQUENCY	100		//定义采样频率
#define SIZE_N 				4096//定义采集数量

#pragma section all "cpu1_dsram"
cfloat32 fft_in[SIZE_N],result[SIZE_N];
#pragma section all restore

#pragma section all "cpu0_dsram"
cfloat32 fm_out[SIZE_N];
#pragma section all restore

cfloat32 * mutual_correlation(cfloat32 *fft_in,int16 *adc_in1,int16 *fm_in)//fft实现互相关，fft_in存放互相关最终结果，其余两个作为输入数据
{
	int i;
	float32 re,im;
    for(i=0;i<SIZE_N/2;i++)
    {
    	fft_in[i].real = (float)adc_in1[i];
    	fft_in[i].imag = 0;
    }
    for(i=SIZE_N/2;i<SIZE_N;i++)   //对采集到的数据补零，放入fft_in中
    {
    	fft_in[i].real = fft_in[i].imag = 0;
    }
    Ifx_FftF32_radix2(result, fft_in, SIZE_N);//对输入数据进行傅里叶变换

    for(i=0;i<SIZE_N/2;i++)
    	fft_in[i].real = (float)fm_in[i];
    Ifx_FftF32_radix2(fm_out, fft_in, SIZE_N);//对输入数据进行傅里叶变换
    for(i=0;i<SIZE_N;i++)//对其中一个数组取共轭
    {
    	re = result[i].real;
    	im = result[i].imag;
    	result[i].real = re * fm_out[i].real + im * fm_out[i].imag;
    	result[i].imag = re * fm_out[i].imag - im * fm_out[i].real;
    }
    Ifx_FftF32_radix2I(fft_in, result, SIZE_N);

    return fft_in;
}

int32 find_max(cfloat32 arr[],int size)//寻找数组最大值的下标
{
	int32 max=0,j;
	float32 m=arr[0].real;
	for(j=0;j<size;j++)
	{
		if(m<arr[j].real)
		{
			max = j;
			m = arr[j].real;
		}
	}
	if(max>2048)
		max = max - size;
	return max;
}

int32 find_max_real(cfloat32 arr[],int size)//寻找数组最大值的下标
{
	int32 max=0,j;
	float32 m=arr[0].real;
	for(j=0;j<size;j++)
	{
		if(m<arr[j].real)
		{
			max = j;
			m = arr[j].real;
		}
	}
	return max;
}

void normal(int16 *arr,int size)//数组归一化
{
	float sum=0;
	int i;
	for(i=0;i<size;i++)
		sum = sum + arr[i];
	sum = sum /size;
	for(i=0;i<size;i++)
		arr[i] =arr[i] - sum;
}

uint16 direction(int16 *adc_in0,int16 *adc_in1,int16 *adc_in2,int16 *adc_in3)
{
	uint16 angle;
	int32 index[4];
	uint32 IndexMin = 0,i;

	mutual_correlation(fft_in,adc_in1,adc_in0);
	index[0] = find_max(fft_in,SIZE_N);
	mutual_correlation(fft_in,adc_in2,adc_in1);
	index[1] = find_max(fft_in,SIZE_N);
	mutual_correlation(fft_in,adc_in2,adc_in0);
	index[2] = find_max(fft_in,SIZE_N);
	mutual_correlation(fft_in,adc_in3,adc_in1);
	index[3] = find_max(fft_in,SIZE_N);

	/** 找到绝对值最小和最大的值下标 */
	for(i = 1; i < 4; i++)
	{
		if(abs(index[i])<= abs(index[IndexMin]))
			IndexMin = i;
	}

	/* 判断大致方位 */
	if(IndexMin == 0)
	{
		if(index[1] > 0)
			angle = 0;
		else
			angle = 180;
	}

	else if(IndexMin == 1)
	{
		if(index[0] > 0)
			angle = 270;
		else
			angle = 90;
	}

	else if(IndexMin == 2)
	{
		if(index[3] > 0)
			angle = 45;
		else
			angle = 225;
	}

	else if(IndexMin == 3)
	{
		if(index[2] > 0)
			angle = 315;
		else
			angle = 135;
	}
	return angle;
}

float32 distance(int16 *arr,int16 *fm)
{
	int32 dis;
	float32 final;
	mutual_correlation(fft_in,arr,fm);
	dis=find_max_real(fft_in,4096);
	final=(4095-dis)*0.01*346;
	return final;
}
