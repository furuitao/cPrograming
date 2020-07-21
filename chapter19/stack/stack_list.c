#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node
{
    Item value;
    struct node *next;
};

struct stack_type
{
    struct node *top;
};

static void terminate (const char *message){
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack create(int size){
    printf("使用链表创建栈\n");
    Stack s = malloc(sizeof(struct stack_type));
    if(s == NULL){
        terminate("创建失败");
    }
    s -> top = NULL;
    return s;
}

void destroy(Stack s){
    make_empty(s);
    free(s);
}

void make_empty(Stack s){
    while(!is_empty(s)){
        pop(s);
    }
}

void push(Stack s, Item v){
    struct node *new_node = malloc(sizeof(struct node));
    if(new_node == NULL){
        terminate("栈已满");
    }
    new_node -> next = s -> top;
    new_node -> value = v;

    s -> top = new_node;
}

Item pop(Stack s){
    if(is_empty(s)){
        terminate("栈为空");
    }
    struct node *old_node = s -> top;
    Item v = old_node -> value;

    s -> top = old_node -> next;
    free(old_node);

    return v;
}

bool is_empty(Stack s){
    return s -> top == NULL;
}

bool is_full(Stack s){
    return false;
}
