#include "stdio.h"
void pb(int n);
int main(void){
	int n;
	printf("输入数字，输入0结束\n");
	while(1){
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		pb(n);
		printf("\n");
	}
	return 0;
}

void pb(int n){
	if(n != 0){
		pb(n/2);
		putchar('0' + n % 2);
	}
}