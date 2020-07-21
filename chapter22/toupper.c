/*
 * 2. 编写程序，把文件中的所有字母转换成大写形式（非字母字符不改变）。程序应从命令行获取文件名并把输出写到stdout中。
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if(argc != 2){
        printf("请输入文件名\n");
        exit(EXIT_FAILURE);
    }
    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL){
        printf("文件打开失败\n");
        exit(EXIT_FAILURE);
    }
    int ch;
    while((ch = getc(fp)) != EOF){
        if(islower(ch)){
            putchar(toupper(ch));
        }else{
            putchar(ch);
        }
    }
    return 0;
}
