/*
2. 编写名为duplicate的函数，此函数使用动态存储分配来创建字符串的副本。例如，调用
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *duplicate(char *str);
int *create_array(int n, int initial_value);

int main(void){
	char *p = "123";
	char *s = duplicate(p);
	printf("%s, %lu, %lu\n", s, sizeof(p), sizeof(s));

	int *arry = create_array(10, 2);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", arry[i]);
	}
	printf("\n");
}

char *duplicate(char *str){
	char *p = malloc(sizeof(char) * (strlen(str)+1));
	if(p != NULL){
		strcpy(p, str);
	}
	return p;
}

/*函数应返回一个指向动态分配的n元int型数组的指针，数组的每个成员都初始化为initial_value。如果内存分配失败，返回值为NULL。*/
int *create_array(int n, int initial_value){
	int *p = malloc(sizeof(int) * n);

	for (int i = 0; p != NULL && i < n; ++i)
	{
		p[i] = initial_value;
	}

	return p;
}
