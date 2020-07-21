#include "stdio.h"
#define N 6
void find_two_largest(int a[], int n, int *largest, int *second_largest);

int main(void){
	int a[N];
	int largest, second_largest;
	printf("输入%d个数字\n", N);
	int i=0;
	while(i < N){
		scanf("%d", &a[i++]);
	}
	find_two_largest(a, N, &largest, &second_largest);
	printf("largest = %d, second_largest = %d\n", largest, second_largest);
}

void find_two_largest(int a[], int n, int *largest, int *second_largest){
	*largest = a[0];
	*second_largest = a[0];
	
	for(int i=1; i<n; i++){
		if(a[i] > *largest){
			*second_largest = *largest;
			*largest = a[i];
		}else if(a[i] > *second_largest){
			*second_largest = a[i];
		}
	}
}