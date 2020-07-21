/*
1. 编写一个程序声明结构s（见21.4节），并显示出成员a、b、c的大小和偏移量。（使用sizeof来得到大小，使用offsetof来得到偏移量。）同时使程序显示出整个结构的大小。根据这些信息，判断结构中是否包含空洞。如果包含空洞，指出每一个空洞的位置和大小。
存在空洞
struct s的大小：16
a的大小1, 偏移量：0
b的大小8, 偏移量：4
c的大小4, 偏移量：12
*/
#include <stdio.h>
#include <stddef.h>

struct s{
    char a;
    int b[2];
    float c;
};

int main(void){
    struct s d;

    printf("struct s的大小：%ld\n", sizeof(d));
    printf("a的大小%ld, 偏移量：%ld\n", sizeof(d.a), offsetof(struct s, a));
    printf("b的大小%ld, 偏移量：%ld\n", sizeof(d.b), offsetof(struct s, b));
    printf("c的大小%ld, 偏移量：%ld\n", sizeof(d.c), offsetof(struct s, c));

    return 0;
}