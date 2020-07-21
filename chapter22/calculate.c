/*
 * 4. (a) 编写程序统计文本文件中字符的数量。
 * (b) 编写程序统计文本文件中单词的数量。（所谓“单词”指的是不含空白字符的任意序列。）
 * (c) 编写程序统计文本文件中行的数量。
 * 要求每一个程序都通过命令行获得文件名。
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, const char *argv[]){
    if(argc != 2){
        printf("请输入文件名\n");
        exit(EXIT_FAILURE);
    }
    FILE *fp = fopen(argv[1], "r");
    int ch,c_count=0,w_count=0,l_count=0;
    bool last_is_space = false;
    if(fp != NULL){
        while((ch = getc(fp)) != EOF){
            c_count++;   
            if(isspace(ch)){
                if(!last_is_space){
                    w_count++;
                }
                last_is_space = true;
            }else{
                last_is_space = false;
            }
            if(ch == '\n'){
                l_count++;
            }
        }
        fclose(fp);
    }
    c_count++;
    if(!last_is_space){
        w_count++;
    }
    l_count++;
    printf("字符数量：%d\n", c_count);
    printf("单词数量：%d\n", w_count);
    printf("行数量：%d\n", l_count);
    return 0;
}
