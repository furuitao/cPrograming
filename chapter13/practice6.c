/*
 * 6. 编写名为censor的函数，把字符串中出现的每一处foo替换为xxx。例如，字符串"food fool"会变为"xxxd xxxl"。在不失清晰性的前提下程序越短越好。
 */
#include "stdio.h"

void cencor(char str[]);

int main(void){
	char str[50] = "ffood ffool,foooooooofoffffooofffoo";
	printf("%s\n", str);
	cencor(str);
	printf("%s\n", str);
}

void cencor(char str[]){
	char *foo = "foo";

	while(*str){
		int n = 0;
		char *p = foo;
		// printf("%c\n", *str);
		while(*str == *p && *p){
			str++;
			p++;
			n++;
		}
		// printf("===%d\n", n);
		if(n == 3){// 匹配
			*(str - 3) = 'x';
			*(str - 2) = 'x';
			*(str - 1) = 'x';
		}else{// 未匹配
			// printf("1---%c\n", *str);
			str -= n;//回退原位
			str++;//前进一位
			// printf("----%c\n", *str);
		}
	}
}