#include "stdio.h"
int main(void){
	int i;

	printf("Enter a two-digit number: ");
	scanf("%3d", &i);

	printf("The reversal is: %d%d%d\n", i%10, i%100/10, i/100);

	return 0;
}