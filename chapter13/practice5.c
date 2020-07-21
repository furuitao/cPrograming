/**
 * 5. (a) 编写名为capitalize的函数，把参数中的字母都改为大写字母。参数是空字符结尾的字符串，且此字符串可以包含任意字符而不仅是字母。使用数组取下标操作访问字符串中的字符。提示：使用toupper函数（➤23.5节）把每个字符转换成大写。
 * (b) 重写capitalize函数，这次使用指针算术运算来访问字符串中的字符。
 * 
 */
#include "stdio.h"
#include "ctype.h"

void capitalize(char str[]); 
void capitalize_pinter(char str[]); 
int main(void){
	char str[10] = "2abc1";
	// char *str = "2abc1";// 使用指针初始化，会报错
	printf("%s\n", str);
	capitalize_pinter(str);
	printf("%s\n", str);
}

void capitalize(char str[]){
	int i=0;
	for(;str[i] != '\0'; i++){
		if(str[i] >= 'a' && str[i] <= 'z'){
			str[i] = toupper(str[i]);
		}
	}
}

void capitalize_pinter(char str[]){
	while(*str){
		if(*str >= 'a' && *str <= 'z'){
			*str = toupper(*str);
		}
		str++;
	}
}