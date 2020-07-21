/*
 * 7. 编写程序，提示用户输入一个数并显示该数，使用字符模拟七段显示器的效果
 */
#include "stdio.h"
#define MAX_DIGITS 20
#define WORD 4
#define L 3
#define W WORD * MAX_DIGITS
/* 
 * 存储每一个数字的显示位             
 * 	    0                   0
 *    5   1                    1
 *      6         比如 3：   6  
 *    4   2                    2
 *      3                   3
 *
 *  _   _   _   _   _       _   _   _   _   _                                      
 * | |  _| | | |_| |_| |_| |_|  _| |_  |_| |_                                      
 * |_| |_  |_| |_| |_|   |  _| |_   _| |_| |_|   
 */
int segments[10][7] = {
	{1,1,1,1,1,1,0},
	{[1]=1,[2]=1},
	{1,1,0,1,1,0,1},
	{1,1,1,1,0,0,1},
	{0,1,1,0,0,1,1},
	{1,0,1,1,0,1,1},
	{1,0,1,1,1,1,1},
	{1,1,1},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1}
};
/**
 * 每个数字占3行4列，总共MAX_DIGITS个数字
 */
char digits[L][W];

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void){
	char ch;
	int p = 0;
	printf("Enter a number: ");
	clear_digits_array();
	while(p < MAX_DIGITS && (ch = getchar()) != '\n'){
		if(ch >= '0' && ch <= '9'){
			process_digit(ch - '0', p++);
		}
	}
	print_digits_array();
	return 0;
}

void clear_digits_array(void){
	for(int i=0; i<L; i++){
		for(int j=0; j<W; j++){
			digits[i][j] = ' ';
		}
	}
}

void process_digit(int digit, int position){
	// printf("%d, %d\n", digit, position);
	int s = WORD * position;
	if(segments[digit][0]) digits[0][s + 1] = '_';
	if(segments[digit][1]) digits[1][s + 2] = '|';
	if(segments[digit][2]) digits[2][s + 2] = '|';
	if(segments[digit][3]) digits[2][s + 1] = '_';
	if(segments[digit][4]) digits[2][s] = '|';
	if(segments[digit][5]) digits[1][s] = '|';
	if(segments[digit][6]) digits[1][s + 1] = '_';
}

void print_digits_array(void){
	for(int i=0; i<L; i++){
		for(int j=0; j<W; j++){
			printf("%c", digits[i][j]);
		}
		printf("\n");
	}
}