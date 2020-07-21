/*
 * 编写程序对表达式求值：
 * 
 * Enter an expression: 1+2.5*3
 * Value of expression: 10.5
 * 表达式中的操作数是浮点数，运算符是+、-、*和/。表达式从左向右求值（所有运算符的优先级都一样）。
 */
#include "stdio.h"
int main(void){
	float f;
	char c;
	float result;

	printf("Enter an expression: ");
	scanf(" %f", &result);
	while( (c = getchar()) != '\n'){
		if(c == ' '){// 排除掉空格
			continue;
		}
		scanf(" %f", &f);
		switch(c){
			case '+': result += f; break;
			case '-': result -= f; break;
			case '*': result *= f; break;
			case '/': result /= f; break;
		}
	}

	printf("Value of expression: %g\n", result);

	return 0;
}