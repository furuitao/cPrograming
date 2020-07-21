#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void display(int n, ...){
    va_list ap;
    char *ptr;
    va_start(ap, n);
    for(int i=0; i<n; i++){
        ptr = va_arg(ap, char*);    
        printf("%s ", ptr);
    }
    va_end(ap);
    printf("\n");    
}

int main(void){
    display(4, "Special", "Agent", "Dale", "Cooper");
    return 0;
}