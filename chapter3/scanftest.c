#include "stdio.h"
int main(void){
	char c1, c2;

	scanf("%c", &c1);
	// fflush(stdin);//错误的方法（VC生效，gcc编译不生效），不生效的原因是：fflush是基于输出流的，对输入流会产生不可预知的结果，所以不应使用这种方式
	while(getchar() != '\n');//1.使用这种方式，吸收换行符
	printf("c1=|%c|\n", c1);
	scanf("%c", &c2);// 2.在%c前面加一个空格，以吸收上一个scanf的换行符
	printf("c2=|%d|\n", c2);
	return 0;
}