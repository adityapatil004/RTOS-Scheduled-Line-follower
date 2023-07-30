/*
 * IR_Sense.h
 *
 *  Created on: Jun 4, 2023
 *      Author: Aditya
 */

#ifndef LINE_DETECTION_H_
#define LINE_DETECTION_H_

#define TRUE 1
#define FALSE 0

struct Line_detection_stat{
	int Line_Left;
	int Line_Right;
};

void Line_Detection_init();
struct Line_detection_stat Line_Detect();

#endif /* LINE_DETECTION_H_ */
