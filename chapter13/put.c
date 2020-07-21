#include "stdio.h"
// #include "string.h"
int main(void){
	char *p = "abc";
	puts(p);//abc
	// puts(*p);//错误
	// putchar(p);//输出未知结果
	putchar(*p);//a

	int i,j;
	char s[10];
	scanf("%d%s%d", &i, s, &j);
	printf("%d,%s,%d\n", i, s, j);
}