#include "stdio.h"
int main(void){
	printf("When you come to a fork in the road, take it. \
--Yogi Berra\n");// 使用 \ 做分隔符：1.\ 必须是最后一个字符，2.下一行必须从行首开始，不能有缩进
	printf("When you come to a fork in the road, take it. "
       "--Yogi Berra\n");// 使用 空白符 做分隔符，会自动将两个字符串拼接起来

	char *p;
	printf("%p\n", p);// 未初始化的指针，会输出未知的结果


	char a[5] = {'a','b','c','d','e'};
	printf("%s\n", a);// 不包含空字符的字符串，会一直输出，直到内存中是空字符的字节。
}