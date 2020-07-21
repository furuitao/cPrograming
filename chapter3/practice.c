#include "stdio.h"
int main(void){
	printf("|%12.5e|\n", 30.253);
	printf("|%-6.2g|\n", .0000009979);


	float x = 5.6f;
	printf("|%-8.1e|\n", x);
	printf("|%10.6e|\n", x);
	printf("|%-8.3f|\n", x);
	printf("|%-6.f|\n", x);

	float i,j;
	int d;
	scanf("%f%d%f", &i, &d, &j);
	printf("%f|%d|%f\n", i, d, j);
	return 0;
}