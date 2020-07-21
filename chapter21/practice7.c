/*
7. 在哪个标准头中可以找到下面描述的函数或宏？
(a) 判断当前是星期几的函数。
(b) 判断字符是否是数字的函数。
(c) 给出最大的unsigned int类型值的宏。
(d) 对浮点数向上取整的函数。
(e) 指定一个字符包含多少位的宏。
(f) 指定double类型值有效位个数的宏。
(g) 在字符串中查找特定字符的函数。
(h) 以读方式打开文件的函数。
*/
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <float.h>
#include <string.h>


int main(void){
    //(a) 判断当前是星期几的函数。time.h
    time_t curr;
    time(&curr);
    struct tm *l = localtime(&curr);
    printf("当前星期：%d\n", l -> tm_wday);

    //(b) 判断字符是否是数字的函数。ctype.h
    char a = 'a', b = '2';
    printf("%c是否是数字: %d\n", a, isdigit(a));
    printf("%c是否是数字: %d\n", b, isdigit(b));

    //(c) 给出最大的unsigned int类型值的宏。limits.h
    printf("最大的unsigned int : %u\n", UINT_MAX);

    //(d) 对浮点数向上取整的函数。math.h
    printf("%lf\n", ceil(2.54));
    printf("%lf\n", floor(2.54));

    //(e) 指定一个字符包含多少位的宏。limits.h
    printf("一个字符包含的位数：%d\n", CHAR_BIT);

    //(f) 指定double类型值有效位个数的宏。float.h
    printf("double类型符号位：%d\n", 1);
    printf("double类型基数：%d\n", FLT_RADIX);
    printf("double类型指数位：%d\n", 64 - 1 - DBL_MANT_DIG);
    printf("double类型有效位：%d\n", DBL_MANT_DIG);
    printf("double最小负整数值：%d\n", DBL_MIN_EXP);
    printf("double最大整数值：%d\n", DBL_MAX_EXP);

    //(g) 在字符串中查找特定字符的函数。string.h
    char *str = "abcdefghijk";
    char *ch = strchr(str, 'd');
    printf("d在字符串[%s]中的位置：%ld\n", str, ch - str);

    //(h) 以读方式打开文件的函数。stdio.h
    FILE *fp = fopen("practice7.c", "r");
    int c;
    while((c = fgetc(fp)) != EOF){
        printf("%c", c);
    }
    printf("\n");
    fclose(fp);
    return 0;
}