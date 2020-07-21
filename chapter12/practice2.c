/*
 * 2. (a) 编写程序读一条消息，然后检查这条消息是否是回文（消息中的字母从左往右看和从右往左看是一样的）：
 * 
 * Enter a message: He lived as a devil, eh?
 * Palindrome
 * Enter a message: Madam, I am Adam.
 * Not a palindrome
 * 忽略所有不是字母的字符。用整型变量来跟踪数组中的位置。
 * (b) 修改上述程序，使用指针代替整数来跟踪数组中的位置。
 * 
 */
#include "stdio.h"
#include "stdbool.h"
#include "ctype.h"
#define N 100

bool palindrome(char a[], int n);
bool palindrome_pointer(char a[], int n);
int ctoi(char ch);

int main(void){
	char a[N], ch;
	int n = 0;
	printf("Enter a message: ");
	while((ch = getchar()) != '\n'){
		if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
			a[n++] = ch;
		}
	}

	if(palindrome(a, n)){
		printf("Palindrome\n");
	}else{
		printf("Not a palindrome\n");
	}
	
	if(palindrome_pointer(a, n)){
		printf("Palindrome\n");
	}else{
		printf("Not a palindrome\n");
	}
}


bool palindrome(char a[], int n){
	int i = 0,j = n - 1;
	while(i < j){
		// printf("%c,%c\n", ctoi(a[i]), ctoi(a[j]));
		if(ctoi(a[i]) != ctoi(a[j])) {
			return false;
		}
		i++;
		j--;
	}
	return true;
}

bool palindrome_pointer(char a[], int n){
	int i = 0,j = n - 1;
	while(i < j){
		if(ctoi(*(a + i)) != ctoi(*(a + j))) {
			return false;
		}
		i++;
		j--;
	}
	return true;
}

int ctoi(char ch){
	return tolower(ch);
}

