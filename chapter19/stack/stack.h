#ifndef STACK_H
#define STACK_H
#include <stdbool.h>
typedef int Item;
typedef struct stack_type *Stack;
Stack create(int size);
void destroy(Stack s);
void make_empty(Stack s);
void push(Stack s, Item v);
Item pop(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
#endif