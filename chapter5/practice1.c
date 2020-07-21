/*
 * 
 * 1. 编写一个程序，确定一个数的位数：
 * 
 * Enter a number: 374
 * The number 374 has 3 digits
 * 
 */
#include "stdio.h"
int main(void){
	int num;

	printf("Enter a number: ");
	scanf("%3d", &num);

	printf("The number %d has ", num);
	if(num < 10){
		printf("1");
	}else if(num < 100){
		printf("2");
	}else{
		printf("3");
	}
	printf(" digits.\n");

	return 0;
}