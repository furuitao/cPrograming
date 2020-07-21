/*
 * 2. 编写一个宏NELEMS(a)来计算一维数组a中元素的个数。
 */
#include "stdio.h"
#include "string.h"
#define NELEMS(a) sizeof(a)/sizeof(a[0])
#define TOUPPER(c) ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))

int main(void){
	int a[] = {3,4,5,6,1};
	printf("%ld\n", NELEMS(a));

	int i;
	char s[10];
	strcpy(s, "abcd");
	i = 0;
	putchar(TOUPPER(s[++i]));// ('a'<=(s[++i])&&(s[++i])<='z'?(s[++i])-'a'+'A':(s[++i]))   ，最终结果为D

	strcpy(s, "0123");
	i = 0;
	putchar(TOUPPER(s[++i]));// ('a'<=(s[++i])&&(s[++i])<='z'?(s[++i])-'a'+'A':(s[++i]))   ，最终结果为2

	return 0;
} 