/*
 * 1. 编写程序，要求用户录入一串整数（把这串整数存储在数组中），然后通过调用selection_sort函数来排序这些整数。在给定n个元素的数组后，selection_sort函数必须做下列工作：
 * (a) 搜索数组找出最大的元素，然后把它移到数组的最后；
 * (b) 递归地调用函数本身来对前n-1个数组元素进行排序。
 */
#include "stdio.h"
#define N 10
void selection_sort(int[], int length);

int main(void){
	int a[N];
	printf("Enter %d numbers: ", N);
	for(int i=0; i<N; i++){
		scanf("%d", &a[i]);
	}
	selection_sort(a, N);

	printf("Ordered numbers: ");

	for(int i=0; i<N; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}

void selection_sort(int a[], int length){
	if(length <= 1){
		return;
	}
	int max = 0;
	for(int i=1; i<length; i++){
		if(a[max] < a[i]){
			max = i;
		}
	}
	if(max != length - 1){
		int temp = a[length - 1];
		a[length - 1] = a[max];
		a[max] = temp;
	}
	selection_sort(a, length - 1);
}

