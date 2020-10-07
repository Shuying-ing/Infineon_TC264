/*
 * obstacle_judge.h
 *
 *  Created on: 2020Äê8ÔÂ17ÈÕ
 *      Author: QSY
 */

#ifndef CODE_OBSTACLE_JUDGE_H_
#define CODE_OBSTACLE_JUDGE_H_

#include "common.h"


/* obstacle_judge.c */
void find_dot(uint16* dot,uint8 img[MT9V03X_H][MT9V03X_W]);
int autoThreshold0(uint8 img[MT9V03X_H][MT9V03X_W]);
void calculate_obstacle(void);
void obstacle_judge(void);


#endif /* CODE_OBSTACLE_JUDGE_H_ */
