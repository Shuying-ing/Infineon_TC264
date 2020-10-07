/*
 * lcd_disp_ad.c
 *
 *  Created on: 2020Äê8ÔÂ23ÈÕ
 *      Author: QSY
 */


#include "headfile.h"


extern int current_status;
extern float32 v, angle_v, back_v;
extern uint32 towards_time_max, stop_time_max, i_max;
extern uint16 backwards_time, adjust_angle_time;


void lcd_disp(void)
{
	lcd_showstr(0,0,"v:");
	lcd_showstr(0,1,"towards:");
	lcd_showstr(0,2,"stop:");
	lcd_showstr(0,3,"angle_v:");
	lcd_showstr(0,4,"angle_t:");
	lcd_showstr(0,5,"back_v:");
	lcd_showstr(0,6,"back_t:");
	lcd_showstr(0,7,"i_max:");


	lcd_showfloat(69,0,v,2,3);
	lcd_showint32(69,1,towards_time_max,6);
	lcd_showint32(69,2,stop_time_max,6);
	lcd_showfloat(79,3,angle_v,2,3);
	lcd_showuint16(79,4,adjust_angle_time);
	lcd_showfloat(79,5,back_v,2,3);
	lcd_showuint16(79,6,backwards_time);
	lcd_showint32(69,7,i_max,6);


	lcd_showstr(134,0,"  ");
	lcd_showstr(134,1,"  ");
	lcd_showstr(134,2,"  ");
	lcd_showstr(134,3,"  ");
	lcd_showstr(134,4,"  ");
	lcd_showstr(134,5,"  ");
	lcd_showstr(134,6,"  ");
	lcd_showstr(134,7,"  ");

	switch(current_status)
	{
		case 0:
			lcd_showstr(134,0,"--");
			break;
		case 1:
			lcd_showstr(134,1,"--");
			break;
		case 2:
			lcd_showstr(134,2,"--");
			break;
		case 3:
			lcd_showstr(134,3,"--");
			break;
		case 4:
			lcd_showstr(134,4,"--");
			break;
		case 5:
			lcd_showstr(134,5,"--");
			break;
		case 6:
			lcd_showstr(134,6,"--");
			break;
		case 7:
			lcd_showstr(134,7,"--");
			break;
	}
}


