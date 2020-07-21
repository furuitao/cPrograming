#include <stdio.h>
#include <stdarg.h>

int max_int(int n, ...){
    va_list pa;
    int i,current,largest;
    va_start(pa, n);
    largest = va_arg(pa, int);
    for(i=1; i<n; i++){
        current = va_arg(pa, int);
        if(current > largest){
            largest = current;
        }
    }
    va_end(pa);
    return largest;
}
/*最后一个数需要以0结尾*/
int max_int2(int first, ...){
    va_list ap;
    va_start(ap, first);
    int i,current,largest = first;
    current = va_arg(ap, int);
    while(current != 0){
        if(current > largest){
            largest = current;
        }
        current = va_arg(ap, int);
    }
    va_end(ap);
    return largest;
}

int testVa(int n, ...){
    va_list ap;
    va_start(ap, n);
    int i, c;
    for(i=0; i<4; i++){
        c = va_arg(ap, int);
        printf("%d\n", c);
    }
    va_end(ap);
}

int main(void){
    int max = max_int(3, 200,3,500);
    printf("最大值：%d\n", max);
    int max2 = max_int2(200,3,500,0);
    printf("最大值：%d\n", max2);
    testVa(3,1,2,3);
}