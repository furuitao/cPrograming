/*
 * 14. 编写程序，用牛顿方法计算正浮点数的平方根
 * Enter a positive number: 3
 * Square root: 1.73205
 * 
 */
#include "stdio.h"
#include "math.h"
int main(void){
	double x, y1, y2 = 1.0;

	printf("Enter a positive number: ");
	scanf("%lf", &x);
	do{
		y1 = y2;
		y2 = (y1 + x / y1)/2;
	}while( fabs(y1 - y2) > 0.00001);

	printf("Square root: %g\n", y2);
}