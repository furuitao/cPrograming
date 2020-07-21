/*
 * 17. 编写程序，从文件中读取一系列电话号码并以标准格式显示。文件的每一行只包含一个电话号码，但可能存在多种格式。可以假定每行包含10个数字，可能夹杂着其他字符（可以忽略）。例如，假定文件包含如下内容：
 * 404.817.6900
 * (215) 686-1776
 * 312-746-6000
 * 877 275 5273
 * 6173434200
 * 程序的输出如下：
 * (404) 817-6900
 * (215) 686-1776
 * (312) 746-6000
 * (877) 275-5273
 * (617) 343-4200
 * 程序从命令行获取文件名。
 */
#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    if(argc != 2){
        printf("请输入文件名\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    int ch;
    int i = 0;
    if(fp != NULL){
        while((ch = getc(fp)) != EOF){
            if(isdigit(ch)){
                if(i == 0){
                    printf("(");
                }
                putchar(ch);
                i++;

                if(i == 3){
                    printf(") ");
                }else if(i == 6){
                    printf("-");
                }
                if(i == 10){
                    fscanf(fp, "%*[^\n]");
                }
            }else if(ch == '\n'){
                putchar('\n');
                i = 0;
            }
        }
        fclose(fp);
    }
    printf("\n");
    return 0;
}