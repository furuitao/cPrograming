/*
 * 1. 编写宏来计算下面的值。
 * (a) x的立方。
 * (b) n除以4的余数。
 * (c) 如果x与y的乘积小于100则值为1，否则值为0。
 * 你写的宏始终正常工作吗？如果不是，哪些参数会导致失败呢？
 */
#include "stdio.h"
#define CUBE(x) ((x)*(x)*(x)) 
#define MOD_4(n) ((n) % 4)
#define LESS_100(x, y) ((x) * (y) < 100)

int main(void){
	printf("%d\n", CUBE(5));
	printf("%d\n", MOD_4(3 * 2 * 7));
	printf("%d\n", LESS_100(9, 100-95));

	return 0;
}