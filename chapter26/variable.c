#include <stdio.h>
#include <stdarg.h>

int errorf(char *format, ...){
    static int error_numbers = 0;
    va_list ap;
    int n;

    error_numbers ++;
    fprintf(stderr, "** Error %d: ", error_numbers);
    va_start(ap, format);
    n = vfprintf(stderr, format, ap);
    va_end(ap);
    fprintf(stderr, "\n");
    return n;
}

int main(void){
    errorf("%s 失败 %d", "模拟", 1);
    errorf("%s 成功 %d", "测试", 2);
}