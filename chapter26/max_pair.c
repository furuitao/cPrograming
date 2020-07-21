#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

char *max_pair(int num_pairs, ...){
    va_list ap;
    char *r,*curr_str;
    int max,curr_num;

    va_start(ap, num_pairs);
    max = va_arg(ap, int);
    r = va_arg(ap, char*);
    for(int i=1; i<num_pairs; i++){
        curr_num = va_arg(ap, int);
        curr_str = va_arg(ap, char*);
        if(curr_num > max){
            r = curr_str;
        }
    }
    va_end(ap);
    return r;
}

int main(void){
    char *r = max_pair(5, 180, "Seinfeld", 180, "I Love Lucy",
            39, "The Honeymooners", 210, "All in the Family",
            86, "The Sopranos");
    printf("%s\n", r);
}