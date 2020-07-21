#include <stdio.h>
#include "stack.h"

int main(void){
    Stack s = create(2);
    printf("栈为空：%d\n", is_empty(s));
    push(s, 1);
    push(s, 2);
    push(s, 3);

    printf("出栈：%d\n", pop(s));
    printf("出栈：%d\n", pop(s));
    printf("出栈：%d\n", pop(s));
    printf("出栈：%d\n", pop(s));

}
