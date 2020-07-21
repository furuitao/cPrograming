/*
 *
 * 编写一个程序，从用户输入的4个整数中找出最大值和最小值：
 * 
 * Enter four integers: 21 43 10 35
 * Largest: 43
 * Smallest: 10
 *
 */
#include "stdio.h"
int main(void){
	int i1, i2, i3, i4;
	int max1, min1;
	int max2, min2;

	printf("Enter four integers: ");
	scanf("%d%d%d%d", &i1, &i2, &i3, &i4);

	if(i1 > i2){
		max1 = i1;
		min1 = i2;
	}else{
		max1 = i2;
		min1 = i1;
	}

	if(i3 > i4){
		max2 = i3;
		min2 = i4;
	}else{
		max2 = i4;
		min2 = i3;
	}

	if(max2 > max1){
		printf("Largest: %d\n", max2);
	}else{
		printf("Largest: %d\n", max1);
	}

	if(min2 < min1){
		printf("Smallest: %d\n", min2);
	}else{
		printf("Smallest: %d\n", min1);
	}

	return 0;
}