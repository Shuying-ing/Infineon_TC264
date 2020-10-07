/*
 * obstacle_judge.c
 *
 *  Created on: 2020年8月4日
 *      Author: QSY
 */



#include "headfile.h"


/********************************************
 *
 * 摄像头
 * if掉帧，then逐飞科技 0801--视频1
 *
 ********************************************/

int16 dot[2]={0, 0};
uint8 obstacle_45=0, obstacle_135=0, obstacle_left=0, obstacle_right=0;
float32 obstacle_x=0, obstacle_y=0;



/* 判断障碍物左右 */
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


		//识别完成，计算实际值
	    if(dot[0]!=0&&dot[1]!=0)
	    	calculate_obstacle();

	    //判断障碍物位置
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


	    mt9v03x_finish_flag = 0;		//在图像使用完毕后  务必清除标志位，否则不会开始采集下一幅图像
	}
}


/* 寻找中心点 */
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


/* 图像动态阈值 */
int autoThreshold0(uint8 img[MT9V03X_H][MT9V03X_W])
{
	int pixelCount[256] = {0};	//每个灰度值所占像素个数
	float pixelPro[256] = {0};	//每个灰度值所占总像素比例
	int i, j, pixelSum = MT9V03X_W * MT9V03X_H;	//总像素
	int tmp_threshold = 0;

	// uint8 *data = mt9v03x_csi_image[0];	//指向像素数据的指针
	//统计灰度级中每个像素在整幅图像中的个数
	for (i = 0; i < 80; i++)
	{
		for (j = 0; j < MT9V03X_W; j++)
		{
			pixelCount[img[i][j]]++;
		}
	}

	for(int i = 0; i < 256; i++)
	{
		pixelPro[i] = (float)pixelCount[i] / pixelSum; //计算每个像素在整幅图像中的比例
	}

	//遍历灰度级[0,255]
	float w0, w1, u0tmp, u1tmp, u0, u1, u, deltaTmp, deltaMax = 0;
	for (i = 0; i < 256; i++) // i作为阈值
	{
		w0 = w1 = u0tmp = u1tmp = u0 = u1 = u = deltaTmp = 0;
		for (j = 0; j < 256; j++)
		{
			if (j <= i) //背景部分
			{
				w0 += pixelPro[j];                             //背景像素点占整个图像的比例
				u0tmp += j * pixelPro[j];
			}
			else //前景部分
			{
				w1 += pixelPro[j];                             //前景像素点占整个图像的比例
				u1tmp += j * pixelPro[j];
			}
		}
		u0 = u0tmp / w0;                                 //背景平均灰度μ0
		u1 = u1tmp / w1;                                 //前景平均灰度μ1
		deltaTmp = (float)(w0 * w1 * pow((u0 - u1), 2)); //类间方差公式 g = w1 * w2 * (u1 - u2) ^ 2
		if (deltaTmp > deltaMax)
		{
			deltaMax = deltaTmp;
			tmp_threshold = i;
		}
	}
	return tmp_threshold;
}


/* 读取值 -->> 实际值 */
void calculate_obstacle()
{
	obstacle_x = dot[1] - 94;

	//dot[0]=0,参数1=105cm；	dot[0]=45,参数1=30cm
	obstacle_y = 75*(46-dot[0])/45+30;
}

