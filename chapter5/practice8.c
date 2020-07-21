/*
 * 编写一个程序，要求用户输入一个时间（用24小时制的时分表示）。程序选择起飞时间与用户输入最接近的航班，显示出相应的起飞时间和抵达时间。
 */
#include "stdio.h"

#define AM_8_00 8 * 60
#define AM_9_43 9 * 60 + 43
#define AM_11_19 11 * 60 + 19
#define PM_12_47 12 * 60 + 47
#define PM_2_00 14 * 60 
#define PM_3_45 15 * 60 + 45
#define PM_7_00 19 * 60
#define PM_9_45 21 * 60 + 45
#define PM_24_00 24 * 60

int main(void){
	int h, m;
	int closest;

	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &h, &m);

	int n = h * 60 + m;
	if(n <= AM_8_00){
		closest = (AM_8_00 - n < n + PM_24_00 - PM_9_45) ? AM_8_00 : PM_9_45;
	}else if(n <= AM_9_43){
		closest = (AM_9_43 - n < n - AM_8_00) ? AM_9_43 : AM_8_00;
	}else if(n <= AM_11_19){
		closest = (AM_11_19 - n < n - AM_9_43) ? AM_11_19 : AM_9_43;
	}else if(n <= PM_12_47){
		closest = (PM_12_47 - n < n - AM_11_19) ? PM_12_47 : AM_11_19;
	}else if(n <= PM_2_00){
		closest = (PM_2_00 - n < n - PM_12_47) ? PM_2_00 : PM_12_47;
	}else if(n <= PM_3_45){
		closest = (PM_3_45 - n < n - PM_2_00) ? PM_3_45 : PM_2_00;
	}else if(n <= PM_7_00){
		closest = (PM_7_00 - n < n - PM_3_45) ? PM_7_00 : PM_3_45;
	}else if(n <= PM_9_45){
		closest = (PM_9_45 - n < n - PM_7_00) ? PM_9_45 : PM_7_00;
	}else{
		closest = (n - PM_9_45 < PM_24_00 - n + AM_8_00) ? PM_9_45 : AM_8_00;
	}

	printf("Closest departure time is ");
	switch(closest){
		case AM_8_00: printf("8:00 a.m., arriving at 10:16 a.m."); break;
		case AM_9_43: printf("9:43 a.m., arriving at 11:52 a.m."); break;
		case AM_11_19: printf("11:19 a.m., arriving at 1:31 p.m."); break;
		case PM_12_47: printf("12:47 p.m., arriving at 3:00 p.m."); break;
		case PM_2_00: printf("2:00 p.m., arriving at 4:08 p.m."); break;
		case PM_3_45: printf("3:45 p.m., arriving at 5:55 p.m."); break;
		case PM_7_00: printf("7:00 p.m., arriving at 9:20 p.m."); break;
		case PM_9_45: printf("9:45 p.m., arriving at 11:58 p.m."); break;
	}
	printf("\n");

	return 0;
}