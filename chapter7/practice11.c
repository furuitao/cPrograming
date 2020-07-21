/**
 * 11. 编写一个程序，根据用户输入的英文名和姓先显示姓氏，其后跟一个逗号，然后显示名的首字母，最后加一个点：
 * 
 * Enter a first and last name: Lloyd Fosdick
 * Fosdick, L.
 * 
 */
#include "stdio.h"
int main(void){
	char first;
	char c;

	printf("Enter a first and last name: ");
	scanf(" %c", &first);// 读取首字母

	while(getchar() != ' ');// 读取剩余的名中的字母

	while((c = getchar()) != '\n'){
		if(c != ' '){
			putchar(c);	
		}
	}

	printf(", %c.\n", first);

	return 0;
}