#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

char *vstrcat(const char *first, ...){
    va_list ap;
    char *ptr;
    int len = strlen(first);
    va_start(ap, first);
    for(;;){
        ptr = va_arg(ap, char*);
        if(ptr == NULL){
            break;
        }
        len += strlen(ptr);
    }
    va_end(ap);


    char *result = malloc((len+1) * sizeof(char));
    if(result == NULL){
        printf("分配空间失败\n");
        exit(EXIT_FAILURE);
    }
    va_start(ap, first);
    strcat(result, first);
    for(;;){
        ptr = va_arg(ap, char*);
        if(ptr == NULL){
            break;
        }
        strcat(result,ptr);
    }
    va_end(ap);
    return result;
}

int main(void){
    printf("%s\n", vstrcat("12","23","34", NULL));
}
