#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define KEY '&'

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("请输入正确的参数：源文件 加密文件\n");
        exit(EXIT_FAILURE);
    }
    FILE *src, *dest;
    if((src = fopen(argv[1], "rb")) == NULL){
        printf("%s 打开失败\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    dest = fopen(argv[2], "wb");

    int orig_char, new_char;
    while((orig_char = getc(src)) != EOF){
        new_char = orig_char ^ KEY;
        putc(new_char, dest);
    }
    fclose(src);
    fclose(dest);
    return 0;
}