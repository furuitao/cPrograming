/*
 * 7. 在进行文件内容压缩的众多方法中，最简单快捷的方法之一是行程长度编码（run-length encoding）方式。这种方法通过用一对字节替换相同的字节序列来进行文件的压缩：第一个字节是重复计数，第二个字节是需要重复的字节。例如，假设待压缩的文件以下列字节序列开始（以十六进制形式显示）：
 * 46 6F 6F 20 62 61 72 21 21 21 20 20 20 20 20
 * 压缩后的文件将包含下列字节：
 * 01 46 02 6F 01 20 01 62 01 61 01 72 03 21 05 20
 * 如果原始文件包含许多相同字节的长序列，那么行程长度编码的方法非常适用。最差的情况（文件中没有连续的重复字节）下，行程长度编码实际上可能使文件的长度加倍。
 * (a) 编写名为compress_file的程序，此程序使用行程长度编码方法来压缩文件。为了运行程序compress_file，将使用下列格式的命令：
 * compress_file 原始文件
 * 程序compress_file将把原始文件的压缩版本写入到“原始文件.rle”文件中。例如，命令
 * compress_file foo.txt
 * 将会使程序compress_file把文件foo.txt的压缩版写到名为foo.txt.rle的文件中。提示：编程题6描述的程序可以用来调试。
 * (b) 编写名为uncompress_file的程序，此程序是程序compress_file的反向操作。程序uncompress_file的命令格式为
 * 
 * uncompress_file compressed-file
 * 压缩后的文件（[插图]）扩展名为.rle。例如，命令
 * uncompress_file foo.txt.rle
 * 将会使程序uncompress_file打开文件foo.txt.rle，并且把未压缩版的内容写入foo.txt。如果命令行参数的扩展名不是.rle，uncompress_file应显示一条出错消息。
 * 
 */
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdbool.h>
 #include <string.h>

void compress_file(const char *filename);
static bool is_end_of(const char *str, const char *suffix);
void uncompress_file(const char *filename, const char *destfile);

int main(int argc, char const *argv[])
{
    if(argc < 3){
       printf("压缩命令：./rle -c filename\n解压命令：./rle -d filename [destfile]，其中filename必须以.rle结尾\n");
       exit(EXIT_FAILURE);
    }
    if(strcmp(argv[1], "-c") == 0){
        compress_file(argv[2]);
    }else if(strcmp(argv[1], "-d") == 0){
        uncompress_file(argv[2], argv[3]);
    }
    return 0;
}

void compress_file(const char *filename){
    // 获取输出文件filename.rle
    char *destfile = malloc((strlen(filename) + 4) * sizeof(char));
    strcpy(destfile, filename);
    strcat(destfile, ".rle");
    FILE *fp = fopen(filename, "rb");
    if(fp != NULL){
        FILE *dest = fopen(destfile, "wb");
        int ch, last;
        int count = 0;
        while((ch = getc(fp)) != EOF){
            if(count == 0){//初始化
                last = ch;
                count ++;
            }else if(last == ch){
                count ++;
            }else{
                fprintf(dest, "%.2X%.2x", count, last);// 写入上一个字符
                // printf("%.2X%.2x", count, last);// 写入上一个字符
                count = 1;
                last = ch;
            }

        }
        fprintf(dest, "%.2X%.2x", count, last);// 写入最后一个字符
        // printf("%.2X%.2x", count, last);// 写入最后一个字符
        fclose(dest);
        fclose(fp);
    }else{
        printf("%s 打开失败\n", filename);
        exit(EXIT_FAILURE);
    }
}

void uncompress_file(const char *filename, const char *destf){
    if(!is_end_of(filename, ".rle")){
        printf("解压文件必须以.rle结尾\n");
        exit(EXIT_FAILURE);
    }
    // 输出文件名，如果没有提供，则需要从输入文件截取
    char *destfile;
    if(destf == NULL){
        destfile = malloc((strlen(filename) - 4) * sizeof(char));
        strncpy(destfile, filename, strlen(filename) - 4);
    }else{
        destfile = malloc(strlen(destf) * sizeof(char));
        strcpy(destfile, destf);
    }

    FILE *fp = fopen(filename, "rb");
    if(fp != NULL){
        FILE *dest = fopen(destfile, "wb");
        int count,ch;
        while(fscanf(fp, "%2X%2X", &count, &ch) == 2){
            while(count-- > 0){
                putc(ch, dest);
                // putchar(ch);
            }
        }
        fclose(dest);
        fclose(fp);
    }else{
        printf("%s 打开失败\n", filename);
        exit(EXIT_FAILURE);
    }
}

static bool is_end_of(const char *str, const char *suffix){
    return strcmp(str + strlen(str) - strlen(suffix), suffix) == 0;
}


