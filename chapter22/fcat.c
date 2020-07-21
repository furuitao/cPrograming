/*
3. 编写一个名为fcat的程序，通过把任意数量的文件写到标准输出中而把这些文件一个接一个地“拼接”起来，而且文件之间没有间隙。例如，下列命令将在屏幕上显示文件f1.c、f2.c和f3.c：
fcat f1.c f2.c f3.c
如果任何文件都无法打开，那么程序fcat应该发出出错消息。提示：因为每次只可以打开一个文件，所以程序fcat只需要一个文件指针变量。一旦对一个文件完成操作，程序fcat在打开下一个文件时可以使用同一个文件指针变量。
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]){
    FILE *fp;
    int ch;

    for(int i=1; i<argc; i++){
        if((fp = fopen(argv[i], "r")) != NULL){
            while((ch = getc(fp)) != EOF){
                putchar(ch);
            }
            fclose(fp);
        }else{
            printf("%s 打开失败\n", argv[i]);
        }
    }
    return 0;
}
