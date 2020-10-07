/*
 * lcd_disp.c
 *
 *  Created on: 2020年8月4日
 *      Author: QSY
 */

#include "headfile.h"


extern int key1_status;
extern int key2_status_xyz, key2_status_M1, key2_status_M2, key2_status_M3, key2_status_M4;
extern float32 x, y, z;
extern float32 kp_4, ki_4, kd_4, kp_3, ki_3, kd_3, kp_2, ki_2, kd_2, kp_1, ki_1, kd_1;	//新车2
extern float Kp1, Ki1, Kd1, Kp2, Ki2, Kd2, Kp3, Ki3, Kd3, Kp4, Ki4, Kd4;	//新车1


void lcd_disp_key1(void)
{
	switch(key1_status)
	{
		case 0:		//Set_xyz
			lcd_showstr(0,0,"XYZ_Sst");
			lcd_showstr(0,2,"x:"); lcd_showfloat(22,2,x,2,3);	//显示浮点数   整数显示2位   小数显示三位
			lcd_showstr(0,3,"y:"); lcd_showfloat(22,3,y,2,3);
			lcd_showstr(0,4,"z:"); lcd_showfloat(22,4,z,2,3);
			break;


/*
 *	增量式PID-新车2
 *
		case 1:		//Set_Motor1_car2
			lcd_showstr(0,0,"Motor1_Sst_car2");
			lcd_showstr(0,2,"P1:"); lcd_showfloat(22,2,kp_1,2,3);	//显示浮点数   整数显示2位   小数显示三位
			lcd_showstr(0,3,"I1:"); lcd_showfloat(22,3,ki_1,2,3);
			lcd_showstr(0,4,"D1:"); lcd_showfloat(22,4,kd_1,2,3);
			break;

		case 2:		//Set_Motor2_car2
			lcd_showstr(0,0,"Motor2_Sst_car2");
			lcd_showstr(0,2,"P2:"); lcd_showfloat(22,2,kp_2,2,3);	//显示浮点数   整数显示2位   小数显示三位
			lcd_showstr(0,3,"I2:"); lcd_showfloat(22,3,ki_2,2,3);
			lcd_showstr(0,4,"D2:"); lcd_showfloat(22,4,kd_2,2,3);
			break;

		case 3:		//Set_Motor3_car2
			lcd_showstr(0,0,"Motor3_Sst_car2");
			lcd_showstr(0,2,"P3:"); lcd_showfloat(22,2,kp_3,2,3);	//显示浮点数   整数显示2位   小数显示三位
			lcd_showstr(0,3,"I3:"); lcd_showfloat(22,3,ki_3,2,3);
			lcd_showstr(0,4,"D3:"); lcd_showfloat(22,4,kd_3,2,3);
			break;

		case 4:		//Set_Motor4_car2
			lcd_showstr(0,0,"Motor4_Sst_car2");
			lcd_showstr(0,2,"P4:"); lcd_showfloat(22,2,kp_4,2,3);	//显示浮点数   整数显示2位   小数显示三位
			lcd_showstr(0,3,"I4:"); lcd_showfloat(22,3,ki_4,2,3);
			lcd_showstr(0,4,"D4:"); lcd_showfloat(22,4,kd_4,2,3);
			break;
*/


/*
 *	增量式PID-新车1
 */

		case 1:		//Set_Motor1_car1
			lcd_showstr(0,0,"Motor1_Set_car1");
			lcd_showstr(0,2,"P1:"); lcd_showfloat(22,2,Kp1,2,3);	//显示浮点数   整数显示2位   小数显示三位
			lcd_showstr(0,3,"I1:"); lcd_showfloat(22,3,Ki1,2,3);
			lcd_showstr(0,4,"D1:"); lcd_showfloat(22,4,Kd1,2,3);
			break;

		case 2:		//Set_Motor2_car1
			lcd_showstr(0,0,"Motor2_Set_car1");
			lcd_showstr(0,2,"P2:"); lcd_showfloat(22,2,Kp2,2,3);	//显示浮点数   整数显示2位   小数显示三位
			lcd_showstr(0,3,"I2:"); lcd_showfloat(22,3,Ki2,2,3);
			lcd_showstr(0,4,"D2:"); lcd_showfloat(22,4,Kd2,2,3);
			break;

		case 3:		//Set_Motor3_car1
			lcd_showstr(0,0,"Motor3_Set_car1");
			lcd_showstr(0,2,"P3:"); lcd_showfloat(22,2,Kp3,2,3);	//显示浮点数   整数显示2位   小数显示三位
			lcd_showstr(0,3,"I3:"); lcd_showfloat(22,3,Ki3,2,3);
			lcd_showstr(0,4,"D3:"); lcd_showfloat(22,4,Kd3,2,3);
			break;

		case 4:		//Set_Motor4_car1
			lcd_showstr(0,0,"Motor4_Set_car1");
			lcd_showstr(0,2,"P4:"); lcd_showfloat(22,2,Kp4,2,3);	//显示浮点数   整数显示2位   小数显示三位
			lcd_showstr(0,3,"I4:"); lcd_showfloat(22,3,Ki4,2,3);
			lcd_showstr(0,4,"D4:"); lcd_showfloat(22,4,Kd4,2,3);
			break;
	}
}

void lcd_disp_key2(void)
{
	lcd_showstr(80,2,"  ");	lcd_showstr(80,3,"  "); lcd_showstr(80,4,"  ");

	if(key1_status==0){
		switch(key2_status_xyz){
			case 0:	lcd_showstr(80,2,"--");	break;
			case 1:	lcd_showstr(80,3,"--");	break;
			case 2:	lcd_showstr(80,4,"--");	break;
		}
	}
	else if(key1_status==1){
		switch(key2_status_M1){
			case 0:	lcd_showstr(80,2,"--"); break;
			case 1:	lcd_showstr(80,3,"--"); break;
			case 2:	lcd_showstr(80,4,"--"); break;
		}
	}
	else if(key1_status==2){
		switch(key2_status_M2){
			case 0:	lcd_showstr(80,2,"--");	break;
			case 1:	lcd_showstr(80,3,"--");	break;
			case 2:	lcd_showstr(80,4,"--");	break;
		}
	}
	else if(key1_status==3){
		switch(key2_status_M3){
			case 0:	lcd_showstr(80,2,"--");	break;
			case 1:	lcd_showstr(80,3,"--");	break;
			case 2:	lcd_showstr(80,4,"--");	break;
		}
	}
	else{
		switch(key2_status_M4){
			case 0:	lcd_showstr(80,2,"--");	break;
			case 1:	lcd_showstr(80,3,"--");	break;
			case 2:	lcd_showstr(80,4,"--");	break;
		}
	}
}


