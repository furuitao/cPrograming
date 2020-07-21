/*5.计算输入数字的逆序*/
#include "stdio.h"

int main(void){
	int n;

	printf("Enter a number: ");
	scanf("%d", &n);

	printf("Reverse is: ");
	do{
		printf("%d", n % 10);
	}while((n /= 10) > 0);

	printf("\n");
	
	return 0;
}