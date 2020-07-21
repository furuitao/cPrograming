/*
 * 函数应返回名为filename的文本文件中第n行的长度（假定文件的第一行是行1）。如果该行不存在，函数返回0。
 */
#include <stdio.h>
#include <stdlib.h>

int line_length(const char *filename, int n);

int main(int argc, char const *argv[])
{
    if(argc != 3){
        printf("请输入文件名 行数\n");
        exit(EXIT_FAILURE);
    }
    int len = line_length(argv[1], strtol(argv[2],NULL,0));
    printf("文件 %s 中第 %s 行的长度是 %d\n", argv[1], argv[2], len);
    return 0;
}

int line_length(const char *filename, int n){
    int curr = 1;
    int ch,len = 0;
    FILE *fp;
    if((fp = fopen(filename, "r")) != NULL){
        while((ch = getc(fp)) != EOF){
            if(curr > n){
                break;
            }

            if(ch == '\n'){
                curr++;
            }if(curr == n){
                len++;
            }
        }
        fclose(fp);
    }
    return len;
}
