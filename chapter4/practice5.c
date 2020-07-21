#include "stdio.h"
int main(void){
	int i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11;
	int total;

	printf("Enter the first 11 digits of a UPC: ");
	scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",&i1,&i2,&i3,&i4,&i5,&i6,&i7,&i8,&i9,&i10,&i11);
	total = (i1 + i3 + i5 + i7 + i9 + i11) * 3 + (i2 + i4 + i6 + i8 + i10);
	printf("Check digit: %d\n", 9 - (total - 1) % 10 );
	printf("Check digit: %d\n", (10 - total % 10) % 10 );
}