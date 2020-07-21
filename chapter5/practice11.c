/*
 * 11. 编写一个程序，要求用户输入一个两位数，然后显示该数的英文单词：
 * Enter a two-digit number: 45
 * You entered the number forty-five.
 *
 */
#include "stdio.h"
int main(void){
	int l, r;

	printf("Enter a two-digit number: ");
	scanf("%1d%1d", &l, &r);

	printf("You entered the number ");
	switch(l){
		case 1: printf(""); break;
		case 2: printf("twenty"); break;
		case 3: printf("thirty"); break;
		case 4: printf("fourty"); break;
		case 5: printf("fifty"); break;
		case 6: printf("sixty"); break;
		case 7: printf("seventy"); break;
		case 8: printf("eighty"); break;
		case 9: printf("ninety"); break;
	}
	switch(r){
		case 0: printf("%s.\n", l==1 ? "ten" : ""); break;
		case 1: printf("%s.\n", l==1 ? "eleven" : "-one"); break;
		case 2: printf("%s.\n", l==1 ? "twelve" : "-two"); break;
		case 3: printf("%s.\n", l==1 ? "thirteen" : "-three"); break;
		case 4: printf("%s.\n", l==1 ? "fourteen" : "-four"); break;
		case 5: printf("%s.\n", l==1 ? "fifteen" : "-five"); break;
		case 6: printf("%s.\n", l==1 ? "sixteen" : "-six"); break;
		case 7: printf("%s.\n", l==1 ? "seventeen" : "-seven"); break;
		case 8: printf("%s.\n", l==1 ? "eighteen" : "-eight"); break;
		case 9: printf("%s.\n", l==1 ? "nineteen" : "-nine"); break;
	}
	return 0;
}