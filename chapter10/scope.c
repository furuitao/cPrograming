/*
 * 程序中声明一个标识符时，如果此标识符已经是可见的，新的声明临时隐藏旧的声明，标识符获得了新的含义。
 * 在程序块末尾，标识符重新获得旧的含义。
 * 本程序依次输出0 1 2 3 4 5
 * 
 */
#include "stdio.h"
int i = 5;
void f(int i);
void f1(void);
int main(void){
	int i = 3;
	if(i > 0){
		int i = 0;
		printf("%d\n", i);
	}
	if(i > 0){
		int i = 1;
		printf("%d\n", i);
	}
	printf("%d\n", i);
	f(i);
	f1();
}

void f(int i){
	i = 4;
	printf("%d\n", i);
}

void f1(void){
	printf("%d\n", i);
}