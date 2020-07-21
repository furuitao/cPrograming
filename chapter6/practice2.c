/*编写程序，要求用户输入两个整数，然后计算并显示这两个整数的最大公约数（GCD）：*/
#include "stdio.h"
int main(void){
	int m, n, gcd;

	printf("Enter two integers: ");
	scanf("%d%d", &m, &n);

	while(m != 0){
		gcd = m;
		m = n;
		n = gcd;
		m %= n;
	}

	printf("Greatest common divisor: %d\n", gcd);
	return 0;
}