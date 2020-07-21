#include <setjmp.h>
#include <stdio.h>

jmp_buf env;
void f1(void);
void f2(void);

int main(void){
    int v;
    if((v = setjmp(env)) == 0){
        printf("setjmp returned\n");
    }else{
        printf("Program terminates: longjmp called with %d\n", v);
        return 0;
    }

    f1();

    printf("Program terminates normally\n");
    return 0;
}

void f1(void){
    printf("f1 begins\n");
    f2();
    printf("f1 returns\n");
}

void f2(void){
    printf("f2 begins\n");
    longjmp(env, 2);
    printf("f2 returns\n");
}