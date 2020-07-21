/*
 * 18. 编写程序，按“月/日/年”的格式接受用户输入的日期，然后按“月 日，年”的格式显示，其中“月”用英文全名：
 * 
 * Enter a date (mm/dd/yyyy): 2/17/2011
 * You entered the date February 17, 2011
 * 用字符串指针数组存储月份的名字。
 * 
 */
#include "stdio.h"
int main(void){
	char *month[13] = {"","January","February","March","April","May","June","July","August","September","October","November","December"};
	int y, m, d;
	printf("Enter a date (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &m, &d, &y);
	printf("You entered the date %s %.2d, %4d\n", month[m], d, y);
}