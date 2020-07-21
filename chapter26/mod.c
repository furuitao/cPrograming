#include <stdio.h>
#include <stdlib.h>

int mod(int i, int j);

int main(void){
    printf("10 mod  3 = %d\n", mod(10,  3));
    printf(" 3 mod 10 = %d\n", mod( 3, 10));
}

int mod(int i, int j){
    div_t t = div(i, j);
    return t.rem;
}