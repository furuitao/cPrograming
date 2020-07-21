/*
 * Enter a message: Don't get mad, get even.
 * Reversal is: .neve teg ,dam teg t'noD
 * 
 */
#include "stdio.h"
#define N 50
int main(void){
	char arry[N], ch;
	int i=0;

	printf("Enter a message: ");
	while(i++ < N && (ch = getchar()) != '\n'){
		arry[i] = ch;
	}
	printf("Reversal is: ");
	while(i-- > 0){
		printf("%c", *(arry + i));
	}
	printf("\n");

	return 0;
}