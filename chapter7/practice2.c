#include "stdio.h"
int main(void){
	int i, n;
	printf("This program prints a table of squares.\n");
	printf("Enter number of entries in table: ");
	scanf("%d", &n);
	while(getchar() != '\n');// 读取换行符，防止下面第一个等待操作被忽略
	for (i = 1; i <= n; i++){
		printf("%10d%10d\n", i, i * i);
		if(i % 24 == 0){
			printf("Press Enter to continue...\n");
			while(getchar() != '\n');// 读取到换行符，继续执行
		}
	}
	return 0;
}