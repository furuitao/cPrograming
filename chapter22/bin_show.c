/*
6. 编写程序，按字节方式和字符方式显示文件的内容。用户通过命令行指定文件名。程序用于显示2.1节的pun.c文件时，输出如下：
Offset               Bytes                Characters
------   -----------------------------    ----------
     0   23 69 6E 63 6C 75 64 65 20 3C    #include <
    10   73 74 64 69 6F 2E 68 3E 0D 0A    stdio.h>..
    20   0D 0A 69 6E 74 20 6D 61 69 6E    ..int main
    30   28 76 6F 69 64 29 0D 0A 7B 0D    (void)..{.
    40   0A 20 20 70 72 69 6E 74 66 28    .  printf(
    50   22 64 6F 20 43 2C 20 6F 72 20    "To C, or
    60   6E 6F 74 20 74 6F 20 43 3A 20    not to C:
    70   74 68 61 74 20 69 73 20 74 68    that is th
    80   65 20 71 75 65 73 74 69 6F 6E    e question
    90   2E 5C 6E 22 29 3B 0D 0A 20 20    .\n");..
   100   72 65 74 75 72 6E 20 30 3B 0D    return 0;.
   110   0A 7D                            .}
每行分别以字节方式和字符方式显示文件中的10个字节。Offset一栏中的数值表示该行的第一个字节在文件中的位置。只显示打印字符（由isprint函数确定），其他字符显示为点。注意，根据字符集和操作系统的不同，文本文件的形式可能不同。上面的示例假设pun.c是Windows文件，因此在每行的最后有0D和0A（ASCII码的回车和回行符）。提示：确保用"rb"模式打开文件。
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    if(argc != 2){
        printf("请输入文件名\n");
        exit(EXIT_FAILURE);
    }
    FILE *fp = fopen(argv[1], "rb");
    char arry[10];
    if(fp != NULL){
        printf("Offset               Bytes                Characters\n");
        printf("------   -----------------------------    ----------\n");

        for(;;){
            size_t len = fread(arry, sizeof(char), 10, fp);    
            printf("%6lu   ", ftell(fp) - 10);// Offset
            for(int i=0; i<10; i++){
                if(i < len){
                    printf("%.2X ", arry[i]);// 高位    
                }else{
                    printf("   ");
                }
                
            }
            printf("   ");
            for(int i=0; i<len; i++){
                if(isprint(arry[i])){
                    putchar(arry[i]);
                }else{
                    putchar('.');
                }
            }
            printf("\n");
            if(len < 10){
                break;
            }
        }

        fclose(fp);
    }
    return 0;
}