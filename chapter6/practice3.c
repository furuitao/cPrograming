/*3.编写程序，要求用户输入一个分数，然后将其约分为最简分式：*/
#include "stdio.h"

int main(void){
	int m, n, gcd, i, j;

	printf("Enter a fractions: ");
	scanf("%d/%d", &m, &n);
	i = m;
	j = n;
	while(m != 0){
		gcd = m;
		m = n;
		n = gcd;
		m %= n;
	}

	printf("In lowest terms: %d/%d\n", (i/gcd), (j/gcd));

	return 0;
}