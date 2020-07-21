#include "stdio.h"
int main(void){
	int i=2;
	int j = i * i ++; // 顺序不能保证，可能是2*2，也可能是3*2
	printf("j=%d\n", j);
	return 0;
}