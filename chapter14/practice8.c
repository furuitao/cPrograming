/*
 * 8. 如果需要一个宏，使它扩展后包含当前行号和文件名。换而言之，我们想把
 * const char *str = LINE_FILE;
 * 扩展为
 * const char *str = "Line 10 of file foo.c";
 * 其中foo.c是包含程序的文件，10是调用LINE_FILE的行号。
 * 
 */
#include "stdio.h"
#include "string.h"
// #define LINE_FILE "Line " __LINE__ " of file " __FILE__
#define LINE(n) #n
#define LINE_TO_STR(a) LINE(a)
#define LINE_FILE "Line " LINE_TO_STR(__LINE__) " of file " __FILE__

const char *str = LINE_FILE;

int main(void){
	printf("%s\n", str);
}
