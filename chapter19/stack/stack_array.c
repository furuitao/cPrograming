#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

struct stack_type{
	Item *contents;
	int top;
    int size;
};

static void terminate (const char *message){
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Stack create(int size){
    printf("使用数组创建栈\n");
	Stack s = malloc(sizeof(struct stack_type));
    if(s == NULL){
        terminate("栈创建失败");
    }
    s -> contents = calloc(size, sizeof(Item));
    if(s -> contents == NULL){
        terminate("栈创建失败");
    }
    s -> top = 0;
    s -> size = size;
    return s;
}

void destroy(Stack s){
    if(s != NULL){
        free(s -> contents);
    }
    free(s);
}

void make_empty(Stack s){
    s -> top = 0;
}

void push(Stack s, Item v){
    if(is_full(s)){
        printf("扩容\n");
        int new_size = 2 * s -> size;
        Item *new_contents = calloc(new_size, sizeof(Item));//扩容新数组
        memcpy(new_contents, s -> contents, s -> size * sizeof(Item));// 将原数组内容拷贝到新数组
        free(s -> contents);// 释放旧数组
        s -> contents = new_contents;// 指向新数组
        s -> size = new_size;
    }

    s -> contents[s -> top++] = v;
}

Item pop(Stack s){
    if(is_empty(s)){
        terminate("栈为空");
    }

    return s -> contents[--s -> top];
}

bool is_empty(Stack s){
    return s -> top == 0;
}

bool is_full(Stack s){
    return s -> top == s -> size;
}
