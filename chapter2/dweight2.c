#include <stdio.h>
int main(void){
	int height,width,length,volume,weight;

	printf("Enter height of box:");
	scanf("%d", &height);
	printf("Enter width of box:");
	scanf("%d", &width);
	printf("Enter length of box:");
	scanf("%d", &length);
	volume = length * width * height;
	weight = (volume + 165) / 166;
	printf("Dimensions: %dx%dx%d\n", length, width, height);
	printf("Volume (cubic inches): %d\n", volume);
	printf("Dimensional weight (pounds): %d\n", weight);
	return 0;
}