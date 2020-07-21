#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>

int tprintf(char *format, ...);
void int2str(int n, char *str);

int main(void){
    tprintf("%%dd%d\n", 123,456);
    tprintf("aaddaa %d aa%aaa,|%s|,%d\n", 123,"你好!",456);

    return 0;
}

int tprintf(char *format, ...){
    bool is_p = false;
    char ch;
    char intstr[11], *ptr;
    va_list ap;
    int n, l = 0;
    va_start(ap, format);
    while((ch = *(format++)) != '\0'){
        if(ch == '%'){//当前字符是%
            if(is_p){//上一个字符是%
                l++;
                putchar('%');
            }
            is_p = true;//设置当前字符是否为%
        }else{
            if(is_p){//上一个字符是%
                if(ch == 'd'){//输出数字
                    n = va_arg(ap, int);
                    int2str(n, intstr);
                    ptr = intstr;
                    while(*ptr != '\0'){
                        l++;
                        putchar(*(ptr++));
                    }
                }else if(ch == 's'){//输出字符串
                    char *sptr = va_arg(ap, char*);
                    while(*sptr != '\0'){
                        putchar(*(sptr++));
                    }
                }else{//输出上一个%和当前字符
                    l++;
                    putchar('%');
                    l++;
                    putchar(ch);
                }
            }else{//输出当前字符
                l++;
                putchar(ch);
            }
            is_p = false;//设置当前字符是否为%
        }
    }
    va_end(ap);
    return l;
}

void int2str(int n, char *str){
    char temp[10], *p = temp;
    while(n / 10 != 0){
        *(p++) = '0' + n % 10;
        n = n / 10;
    }
    *p = '0' + n;
    while(temp <= p){
        *(str ++) = *(p --);
    }

    *str = '\0';
}