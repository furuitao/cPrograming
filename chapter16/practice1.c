#include <stdio.h>
struct { int x,  y; } x;
struct { int x,  y; } y;

int main(void){
	printf("%d,%d\n", x.x, x.y);
	printf("%d,%d\n", y.x, y.y);
}