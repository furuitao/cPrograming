#include "stdio.h"
int main(void){
	int arry[] = {4, 5, 6, [0] = 7, 8};

	int size = sizeof(arry)/sizeof(arry[0]);
	printf("数组大小：%d，其内容为：[", size);
	for(int i=0; i<size; i++){
		printf("%d ", arry[i]);
	}
	printf("]\n");

	return 0;
}