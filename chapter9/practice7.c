/*
 *	7.如果换一种方法计算[插图]，9.6节的power函数速度可以更快。
 */
#include "stdio.h"
int power(int x, int n);
int main(void){
	int x, n;

	printf("Please Enter x^n: ");
	scanf("%d^%d", &x, &n);
	printf("%d\n", power(x, n));

	return 0;
}

int power(int x, int n){
	printf("%d,%d\n", x, n);
	if(n == 0){
		return 1;
	}else if(n == 1){
		return x;
	}
	int p = power(x, n / 2);

	if(n % 2 == 0){
		return p * p;
	}else{
		return x * p * p;
	}
}