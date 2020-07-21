#include "stdio.h"
#define N 10
void q_sort(int a[], int i, int j);
void q_sort1(int a[], int i, int j);
void print_arry(int a[]);
int main(void){
	int a[N];
	printf("Enter %d numbers to be sorted: ", N);
	for(int i=0; i<N; i++){
		scanf("%d", &a[i]);
	}
	q_sort1(a, 0, N - 1);
	printf("In sorted order: ");
	print_arry(a);
	return 0;
}

void q_sort(int a[], int i, int j){
	// printf("递归 %d ~ %d\n", i, j);
	if(i >= j){// 递归退出条件
		return;
	}
	int s = i, e = j;
	int v = a[i];//对比值
	int f = 0;
	while(i < j){
		if(f == 0 && a[j--] <= v){//左移
			a[i++] = a[++j];
			f = 1;
		}else if(f == 1 && a[i++] >= v){//右移
			a[j--] = a[--i];
			f = 0;
		}
		// printf("%d,%d,%d\n", f, i, j);
	}
	// printf("%d,%d | ", i,j);
	// print_arry(a);
	a[i] = v;//将对比值写入数组中
	q_sort(a, s, i - 1);//递归前部
	q_sort(a, i + 1, e);//递归后部
}

void q_sort1(int a[], int i, int j){
	if(i >= j){
		return;
	}
	int s = i, e = j;
	int v = a[i];
	while(1){
		while(i < j && v <= a[j]){
			j--;
		}
		if(i < j){
			a[i++] = a[j];
		}
		while(i < j && a[i] <= v){
			i++;
		}
		if(i < j){
			a[j--] = a[i];
		}
		if(i >= j){
			break;
		}
	}
	a[i] = v;
	q_sort1(a, s, i - 1);
	q_sort1(a, i + 1, e);
}

void print_arry(int a[]){
	for(int i=0; i<N; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}