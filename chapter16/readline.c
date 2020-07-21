#include <stdio.h>
#include "readline.h"

/*读第一个非空的字符，并清空后续的输入缓冲区*/
char read_char(){
	char ch;
	while((ch = getchar()) == ' ' || ch  == '\n');
	while(getchar() != '\n');
	return ch;
}

/*读取一行字符串*/
void read_line(char *str, int n){
	char ch;
	int i = 0;
	while((ch = getchar()) == ' ' || ch  == '\n');
	do{
		if(i < n){
			str[i++] = ch;
		}
		str[i] = '\0';
		ch = getchar();
	}while(ch != '\n');
}