#include "stdio.h"
int main(void){
	int a[10][5], *p, (*q)[5];
	p = a[0];
	q = a;

	printf("%p\n%p\n", p, q);
	printf("%p\n%p\n", p+1, q+1);
	return 0;
}