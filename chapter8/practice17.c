/*
 * 17. 编写程序打印n*n的幻方（1,2,3,...,n^2的方阵排列，且每行、每列和每条对角线上的和都相等）。由用户指定n的值：
 * This program creates a magic square of a specified size.
 * The size must be an odd number between 1 and 99.
 * Enter size of magic square: 5
 * 17   24    1    8   15
 * 23    5    7   14   16
 *  4    6   13   20   22
 * 10   12   19   21    3
 * 11   18   25    2    9
 * 
 */
#include "stdio.h"

int main(void){
	int n;

	printf("This program creates a magic square of a specified size.\n");
	printf("The size must be an odd number between 1 and 99.\n");
	printf("Enter size of magic square: ");
	scanf("%d", &n);

	int arry[99][99] = {0};//初始化为0
	int max = n * n;
	int x = 0,y = n / 2;
	for(int i = 1; i <= max; i++){
		if( i > 1){
			int n_x = (x + n - 1) % n;// x上移
			int n_y = (y + 1) % n;// y右移

			if(arry[n_x][n_y] > 0){// 新位置有值，需要改为上一个数字的下面
				x = (x + 1) % n;
			}else{
				x = n_x;
				y = n_y;
			}
		}

		arry[x][y] = i;
	}

	for(int i = 0; i < n ; i++){
		for(int j = 0; j < n ; j++){
			printf("%8d", arry[i][j]);
		}
		printf("\n");
	}

	return 0;
}