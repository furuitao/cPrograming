#include "stdio.h"
#define PI 3.14f

int main(void){
	int r;
	printf("Enter Ball radius: ");
	scanf("%d", &r);

	float volume = 4.0f / 3.0f * PI * r * r * r;
	printf("Ball radius: %d\n", r);
	printf("Ball volume: %f\n", volume);
	return 0;
}