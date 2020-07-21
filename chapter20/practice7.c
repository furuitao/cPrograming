/*
7. 编写如下函数：
unsigned int rotate_left(unsigned int i, int n);
unsigned int rotate_right(unsigned int i, int n);
函数rotate_left返回的值应是将i左移n位并将从左侧移出的位移入i右端而产生的结果。（例如，假定整数占32位，rotate_left(0x12345678, 4)将返回0x23456781。）函数rotate_right也类似，只是将数字中的位向右循环移位。
*/
#include <stdio.h>

unsigned int rotate_left(unsigned int i, int n);
unsigned int rotate_right(unsigned int i, int n);

int main(void){
    unsigned int i = 0x12345678;
    printf("左移：%x\n", rotate_left(i, 4));
    printf("右移：%x\n", rotate_right(i, 8));
}

unsigned int rotate_left(unsigned int i, int n){
    for(; n > 0; n--){
        i = (i << 1) | ((i & 0x80000000) >> 31);
    }
    return i;
}

unsigned int rotate_right(unsigned int i, int n){
    for(; n > 0; n--){
        i = (i >> 1) | ((i & 1) << 31);
    }
    return i;
}
