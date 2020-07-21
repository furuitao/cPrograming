#include "stdio.h"
int main(void){
	int i = -10;
	unsigned int j = 10;

	printf("%d\n", i < j); // 隐式类型转换，会把有符号整型转换为无符号整型，导致i不再是-10，而是加上最大的无符号整数，所以输出结果为0
	return 0;
}