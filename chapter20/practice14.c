#include <stdio.h>
#include <stdlib.h>

union data{
    struct {
        unsigned int f:1;
        unsigned int i:8;
        unsigned int d:23;
    } digit;
    float f;
};

int main(void){
    union data d;

    d.digit.f = 1;
    d.digit.i = 102;
    d.digit.d = 5293094;
    d.f = -100;

    printf("%f\n", d.f);
    printf("%d\n", d.digit.f);
    printf("%d\n", d.digit.i);
    printf("%d\n", d.digit.d);
}