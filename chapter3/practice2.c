#include "stdio.h"
int main(void){
	int number,y,m,d;
	float price;

	printf("Enter item number: ");
	scanf("%d", &number);
	printf("Enter unit price: ");
	scanf("%7f", &price);
	printf("Enter purchase date(mm/dd/yyyy): ");
	scanf("%d/%d/%d", &m, &d, &y);

	printf("Item\tUnit\tPurchase\n\tPrice\tDate\n%d\t$%7.2f\t%d/%d/%d\n", number, price, m, d, y);
	return 0;
}