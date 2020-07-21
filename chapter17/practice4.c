/*
假设希望p指向一个rectangle结构，此结构的左上角位于(10, 25)的位置上，而右下角位于(20, 15)的位置上。请编写一系列语句用来分配这样一个结构，并且像说明的那样进行初始化。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct point { int x, y; };
struct rectangle { struct point upper_left, lower_right; };
struct rectangle *p;

int main(void){
	p = malloc(sizeof(struct rectangle));
	p -> upper_left.x = 10;
	p -> upper_left.y = 25;
	p -> lower_right.x = 20;
	p -> lower_right.y = 15;

	printf("(%d,%d),(%d,%d)\n", (*p).upper_left.x, (*p).upper_left.y, p -> lower_right.x, p -> lower_right.y);
}