/*
 * 1. 扩展22.2节的canopen.c程序，以便用户可以把任意数量的文件名放置在命令行中：
 * canopen foo bar baz
 * 这个程序应该为每个文件分别显示出can be opended消息或者can't be opened消息。如果一个或多个文件无法打开，程序以EXIT_FAILURE状态终止。
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    if(argc == 1){
        printf("请指定文件名\n");
        exit(EXIT_FAILURE);
    }
    FILE *fp;
    bool fail = false;
    for(int i=1; i<argc; i++){
        if((fp = fopen(argv[i], "r")) == NULL){
            printf("%s can't be opened\n", argv[i]);
            fail = true;
        }else{
            printf("%s can be opened\n", argv[i]);
            fclose(fp);
        }
    }
    if(fail){
        exit(EXIT_FAILURE);
    }else{
        return 0;    
    }
}