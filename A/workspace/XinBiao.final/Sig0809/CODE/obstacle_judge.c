/*
 * obstacle_judge.c
 *
 *  Created on: 2020��8��4��
 *      Author: QSY
 */



#include "headfile.h"


/********************************************
 *
 * ����ͷ
 * if��֡��then��ɿƼ� 0801--��Ƶ1
 *
 ********************************************/

int16 dot[2]={0, 0};
uint8 obstacle_45=0, obstacle_135=0, obstacle_left=0, obstacle_right=0;
float32 obstacle_x=0, obstacle_y=0;



/* �ж��ϰ������� */
void obstacle_judge()
{
	if(mt9v03x_finish_flag)
	{
		find_dot(dot, mt9v03x_image);
		uint8 image[60][MT9V03X_W];
/*		for(int i=60;i<120;i++)
			for(int j=0;j<MT9V03X_W;j++)
			{
				mt9v03x_image[i-60][j]=mt9v03x_image[i][j];
				if(mt9v03x_image[i][j]>130)
					image[i-60][j]=255;
				else
					image[i-60][j]=0;
			}
		for(int i=1;i<59;i++)
			for(int j=1;j<187;j++)
			{
				if(image[i-1][j-1]+image[i-1][j]+image[i-1][j+1]+
						+image[i][j-1]+image[i][j]+image[i][j+1]+
						image[i+1][j-1]+image[i+1][j]+image[i+1][j+1]<1020||image[i][j]==0)
					mt9v03x_image[i+60][j]=0;
				else
					mt9v03x_image[i+60][j]=255;
			}
			*/
		for(int i=1;i<60;i++)
			for(int j=0;j<188;j++)
			{
				if(image[i-1][j]==0||image[i][j]==0)
					mt9v03x_image[i+60][j]=0;
				else mt9v03x_image[i+60][j]=255;
			}
		lcd_displayimage032(mt9v03x_image[0], MT9V03X_W, MT9V03X_H);


		//ʶ����ɣ�����ʵ��ֵ
	    if(dot[0]!=0&&dot[1]!=0)
	    	calculate_obstacle();

	    //�ж��ϰ���λ��
//	    if(obstacle_x<10 && obstacle_x>10)
//	    	obstacle_45 = 1;
//	    if(obstacle_x<10 && obstacle_x>10)
//	    	obstacle_135 = 1;
	    if(obstacle_y<100)
	    {
	    	if(obstacle_x<10 && obstacle_x>10)
	    		obstacle_left = 1;
	    	if(obstacle_x<10 && obstacle_x>10)
	    		obstacle_right = 1;
	    }


	    mt9v03x_finish_flag = 0;		//��ͼ��ʹ����Ϻ�  ��������־λ�����򲻻Ὺʼ�ɼ���һ��ͼ��
	}
}


/* Ѱ�����ĵ� */
void find_dot(uint16* dot,uint8 img[MT9V03X_H][MT9V03X_W])
{
	int16 i,j;
	int k = 105;	//autoThreshold0(mt9v03x_image);
	dot[0]=dot[1]=0;
	int16 maxh=0,minh=200,maxw=0,minw=200;
	for(i=60;i<120;i++){
		for(j=0;j<MT9V03X_W;j++){
			if(img[i][j]>k)
			{
				if(i>=maxh) maxh=i;
				if(i<=minh) minh=i;
				if(j>=maxw) maxw=j;
				if(j<=minw) minw=j;
			}
		}
	}

	if(minw<200&&minh<200)
	{
		dot[0] = (maxh+minh) / 2;
		dot[1] = (maxw+minw) / 2;
	}
}


/* ͼ��̬��ֵ */
int autoThreshold0(uint8 img[MT9V03X_H][MT9V03X_W])
{
	int pixelCount[256] = {0};	//ÿ���Ҷ�ֵ��ռ���ظ���
	float pixelPro[256] = {0};	//ÿ���Ҷ�ֵ��ռ�����ر���
	int i, j, pixelSum = MT9V03X_W * MT9V03X_H;	//������
	int tmp_threshold = 0;

	// uint8 *data = mt9v03x_csi_image[0];	//ָ���������ݵ�ָ��
	//ͳ�ƻҶȼ���ÿ������������ͼ���еĸ���
	for (i = 0; i < 80; i++)
	{
		for (j = 0; j < MT9V03X_W; j++)
		{
			pixelCount[img[i][j]]++;
		}
	}

	for(int i = 0; i < 256; i++)
	{
		pixelPro[i] = (float)pixelCount[i] / pixelSum; //����ÿ������������ͼ���еı���
	}

	//�����Ҷȼ�[0,255]
	float w0, w1, u0tmp, u1tmp, u0, u1, u, deltaTmp, deltaMax = 0;
	for (i = 0; i < 256; i++) // i��Ϊ��ֵ
	{
		w0 = w1 = u0tmp = u1tmp = u0 = u1 = u = deltaTmp = 0;
		for (j = 0; j < 256; j++)
		{
			if (j <= i) //��������
			{
				w0 += pixelPro[j];                             //�������ص�ռ����ͼ��ı���
				u0tmp += j * pixelPro[j];
			}
			else //ǰ������
			{
				w1 += pixelPro[j];                             //ǰ�����ص�ռ����ͼ��ı���
				u1tmp += j * pixelPro[j];
			}
		}
		u0 = u0tmp / w0;                                 //����ƽ���ҶȦ�0
		u1 = u1tmp / w1;                                 //ǰ��ƽ���ҶȦ�1
		deltaTmp = (float)(w0 * w1 * pow((u0 - u1), 2)); //��䷽�ʽ g = w1 * w2 * (u1 - u2) ^ 2
		if (deltaTmp > deltaMax)
		{
			deltaMax = deltaTmp;
			tmp_threshold = i;
		}
	}
	return tmp_threshold;
}


/* ��ȡֵ -->> ʵ��ֵ */
void calculate_obstacle()
{
	obstacle_x = dot[1] - 94;

	//dot[0]=0,����1=105cm��	dot[0]=45,����1=30cm
	obstacle_y = 75*(46-dot[0])/45+30;
}

