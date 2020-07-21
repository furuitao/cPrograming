#include "stdio.h"
int main(void){
	int i;

	printf("Enter a number between 0 and 32767: ");
	scanf("%5d", &i);

	printf("%o\n", i);

	int j1,j2,j3,j4,j5;
	j5 = i % 8;
	i /= 8;
	j4 = i % 8;
	i /= 8;
	j3 = i % 8;
	i /= 8;
	j2 = i % 8;
	i /= 8;
	j1 = i % 8;
	printf("%d%d%d%d%d\n", j1,j2,j3,j4,j5);
	return 0;
}