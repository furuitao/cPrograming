#include "stdio.h"
int main(void){
	short i = 10000;
	int j;

	j = i * i;

	printf("%d\n", i * i);

	printf("%lu\n", sizeof(i));
	printf("%lu\n", sizeof(j));
	return 0;
}