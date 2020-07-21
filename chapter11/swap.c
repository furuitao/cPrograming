/*
 * 使用指针实现交换两个数的方法
 */
#include "stdio.h"
void swap(int *p, int *q);
int main(void){
	int i = 10, j = 9;

	printf("初始值：i = %d, j = %d\n", i, j);

	swap(&i, &j);

	printf("交换值：i = %d, j = %d\n", i, j);
}

void swap(int *p, int *q){
	int temp = *q;
	*q = *p;
	*p = temp;
}