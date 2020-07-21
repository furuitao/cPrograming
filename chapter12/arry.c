/*
 * 1. 假设下列声明是有效的：
 * int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
 * int *p = &a[1], *q = &a[5];
 * (a) *(p+3)的值是多少？
 * (b) *(q-3)的值是多少？
 * (c) q-p的值是多少？
 * (d) p < q的结果是真还是假？
 * (e) *p <*q的结果是真还是假？
 * 
 */
#include "stdio.h"

int main(void){
	int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
	int *p = &a[1], *q = &a[5];
	printf("%d\n", *(p+3));// 14
	printf("%d\n", *(q-3));// 34
	printf("%ld\n", q - p);// 4
	printf("%d\n", p < q);// 1
	printf("%d\n", *p < *q);// 0

	int *high = &a[7], *low = &a[0], *middle;
	// middle = (low + high) / 2; // error
	middle = low + (high - low) / 2;
	printf("%d\n", *middle);
	return 0;
}