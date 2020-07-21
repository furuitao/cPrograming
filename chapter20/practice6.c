/*
 (a) 使用位运算符编写如下函数：
unsigned short swap_bytes(unsigned short i);
函数swap_bytes的返回值是将i的两个字节调换后产生的结果。（在大多数计算机中，短整数占两个字节。）例如，假设i的值是0x1234（二进制形式为0001001000110100），那么swap_bytes的返回值应该为0x3412（二进制形式为0011010000010010）。编写一个程序来测试你的函数。程序以十六进制读入数，然后交换两个字节并显示出来：

Enter a hexadecimal number (up to four digits): 1234
Number with bytes swapped: 3412
提示：使用%hx转换来读入和输出十六进制数。
(b) 将swap_bytes函数的函数体化简为一条语句。
*/
#include <stdio.h>

unsigned short swap_bytes(unsigned short i);

int main(void){
    unsigned short s;
    printf("Enter a hexadecimal number (up to four digits): ");
    scanf("%hx", &s);
    printf("Number with bytes swapped: %hx\n", swap_bytes(s));
}

unsigned short swap_bytes(unsigned short i){
    return (i & 0xff) << 8 | (i & 0xff00) >> 8;
}