/*
 * signal1.h
 *
 *  Created on: 2020Äê8ÔÂ4ÈÕ
 *      Author: ASUS
 */

#ifndef CODE_SIGNAL1_H_
#define CODE_SIGNAL1_H_

cfloat32 * mutual_correlation(cfloat32 *fft_in,int16 *adc_in1,int16 *fm_in);
int32 find_max(cfloat32 arr[],int size);
int32 find_max_real(cfloat32 arr[],int size);
void normal(int16 *arr,int size);
uint16 direction(int16 *adc_in0,int16 *adc_in1,int16 *adc_in2,int16 *adc_in3);
float32 distance(int16 *arr,int16 *fm);

#endif /* CODE_SIGNAL1_H_ */
