#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct stack{
	int value;
	struct stack *next;
} *first = NULL;

bool is_empty();
void push(int n);
int pop();

int main(void){
	printf("是否为空：%d\n", is_empty());
	push(1);
	// push(2);
	printf("%d\n", pop());
	pop();
	printf("程序运行结束。\n");
}

bool is_empty(){
	return first == NULL;
}

void push(int n){
	struct stack *p = malloc(sizeof(struct stack));
	if(p == NULL){
		printf("分配内存失败。。\n");
		return;
	}
	p -> value = n;
	p -> next = first;
	first = p;
}

int pop(){
	if(is_empty()){
		printf("栈为空。。\n");
		exit(0);
	}

	struct stack *p = first;
	int n;
	first = p -> next;
	n = p -> value;
	free(p);
	return n;
}