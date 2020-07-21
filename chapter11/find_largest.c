#include "stdio.h"
#define N 6
int *find_largest(int a[], int n);

int main(void){
	int a[N];
	int *p;
	printf("输入%d个数字\n", N);
	int i=0;
	while(i < N){
		scanf("%d", &a[i++]);
	}
	p = find_largest(a, N);
	printf("largest = %d\n", *p);
}

int *find_largest(int a[], int n){
	int *p = &a[0];
	for (int i = 1; i < n; ++i){
		printf("%p=%d\n", &a[i], a[i]);
		if(a[i] > *p){
			*p = a[i];
		}
	}
	return p;
}