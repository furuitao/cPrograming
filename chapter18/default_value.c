#include <stdio.h>

int i;
float f;
double d;
char *p;


int main(void){
	printf("%d\n", i);
	printf("%f\n", f);
	printf("%lf\n", d);
	printf("%p\n", p);

	static int i1;
	static float f1;
	static double d1;
	static char *p1;

	printf("%d\n", i1);
	printf("%f\n", f1);
	printf("%lf\n", d1);
	printf("%p\n", p1);
}