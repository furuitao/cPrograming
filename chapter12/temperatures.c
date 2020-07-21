/*
 * 14. 假设下面的数组含有一周24小时的温度读数，数组的每一行是某一天的读数：
 * int temperatures[7][24];
 * 编写一条语句，使用search函数（见练习题7）在整个temperatures数组中寻找值32。
 * 
 */
#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "time.h"
bool search(const int a[], int n, int key);
void print_arry(int *a, int n);
void init(int *a, int n);
int find_largest(int a[], int n);

int main(void){
	int temperatures[7][24];
	int *p = &temperatures[0][0];
	init(p, 7 * 24);
	print_arry(p, 7 * 24);
	printf("数组中包含32：%d\n", search(p, 7 * 24, 32));

	for(int i=0; i<7; i++){
		printf("第%d天最高温度是：%d\n", i + 1, find_largest(temperatures[i], 24));
	}
}

void init(int *a, int n){
	srand((unsigned)time(NULL));
	for(int i=0; i<n; i++){
		*(a+i) = 25 + rand() % 10;
	}
}

void print_arry(int *a, int n){
	while(n-- > 0){
		printf("%8d", *(a++));
		if(n % 24 == 0){
			printf("\n");
		}
	}
}

bool search(const int a[], int n, int key){
	for(int i=0; i<n; i++){
		if(*(a++) == key){
			return true;
		}
	}
	return false;
}

int find_largest(int a[], int n){
	int max = *a;
	while(n-- > 1){
		a++;
		if(*a > max){
			max = *a;
		}
	}
	return max;
}