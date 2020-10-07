/*
 * path_planning_ad.h
 *
 *  Created on: 2020Äê8ÔÂ13ÈÕ
 *      Author: QSY
 */

#ifndef CODE_PATH_PLANNING_AD_H_
#define CODE_PATH_PLANNING_AD_H_

#include "common.h"


/* path_planning_ad.c */
void obstacle_avoid(void);

void judge_if_success(void);

void towards_stop(void);
void backwards(void);
void adjust_angle_delta(void);
void adjust_angle(void);

void delay(uint16 delay_time);


#endif /* CODE_PATH_PLANNING_AD_H_ */
