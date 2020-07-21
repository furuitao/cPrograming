/* 变量没有初始化，输出的结果是随机的，没有任何规律，多次执行的结果是不一样的*/
#include "stdio.h"

int main(void){
	int a,b,c;
	float e,f,g;

	printf("a = %d\n",a);
	printf("b = %d\n",b);
	printf("c = %d\n",c);
	printf("e = %f\n",e);
	printf("f = %f\n",f);
	printf("g = %f\n",g);
}