/*
 * 1. 修改10.2节的栈示例使它存储字符而不是整数。接下来，增加main函数，用来要求用户输入一串圆括号或花括号，然后指出它们之间的嵌套是否正确：
 * 
 * Enter parenteses and/or braces:((){}{()})
 * Parenteses/braces are nested properly
 * 
 */
#include "stdio.h"
#include "stdbool.h"
#define M 100

char contents[M];
int top = 0;

bool is_empty();
bool is_full();
char pop();
void push(char);

int main(void){
	char ch;

	printf("Enter parenteses and/or braces:");
	while(true){
		ch = getchar();
		if(ch == '\n'){
			break;
		}
		if(ch == '(' || ch == '{'){
			push(ch);
		}else if(is_empty()){
			printf("Empty left %c\n", ch);
			break;
		}else if(ch == ')' && pop() != '('){
			printf("No match %c\n", ch);
			break;
		}else if(ch == '}' && pop() != '{'){
			printf("No match %c\n", ch);
			break;
		}
	}
	if(!is_empty()){
		printf("Empty right %c\n", pop());
	}else{
		printf("Parenteses/braces are nested properly\n");
	}
	return 0;
}

bool is_empty(){
	return top == 0;
}

bool is_full(){
	return top == M;
}

char pop(){
	if(is_empty()){
		printf("contents is empty.\n");
		return '\0';
	}else{
		return contents[--top];
	}
}

void push(char ch){
	if(!is_full()){
		contents[top++] = ch;
	}
}