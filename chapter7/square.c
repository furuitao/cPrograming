#include "stdio.h"
int main(void){
	long i, n;
	printf("This program prints a table of squares.\n");
	printf("Enter number of entries in table: ");
	scanf("%ld", &n);
	for (i = 0; i <= 10; i++){
		printf("%20ld%20ld\n", n, (n * n));
		n--;
	}
	return 0;
}