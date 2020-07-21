#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if(argc != 3){
        printf("请输入2个参数\n");
        exit(EXIT_FAILURE); 
    }
    FILE *src, *dest;
    src = fopen(argv[1], "rb");
    if(src == NULL){
        printf("文件 %s 打开失败\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    dest = fopen(argv[2], "wb");
    if(dest == NULL){
        printf("文件 %s 打开失败\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    int ch;
    while((ch = getc(src)) != EOF){
        putc(ch, dest);
    }
    fclose(src);
    fclose(dest);
    return 0;
}