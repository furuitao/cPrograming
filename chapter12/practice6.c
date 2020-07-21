/*
 * 6. 修改9.6节的qsort.c程序，使得low、high和middle是指向数组元素的指针而不是整数。split函数应返回指针而不再是整数。
 */
#include "stdio.h"
#define N 10

void qsort(int *low, int *high);
int * split(int *low, int *high);
int main(void){
	int a[N] = {5,5,5,5,4,5,5,5,5,5};
	qsort(&a[0], &a[N - 1]);

	for (int i = 0; i < N; ++i){
		printf("%d ", a[i]);
	}
	printf("\n");
}

void qsort(int *low, int *high){
	if(low >= high){
		return;
	}
	int *middle = split(low, high);
	qsort(low, middle - 1);
	qsort(middle + 1, high);
}

int * split(int *low, int *high){
	int v = *low;
	for(;;){
		while(v <= *high && low < high){
			high--;
		}
		if(low < high){
			*(low++) = *high;
		}else{
			break;
		}
		
		while(*low <= v && low < high){
			low++;
		}
		if(low < high){
			*(high--) = *low;
		}else{
			break;
		}
	}
	*high = v;
	return high;
}