/* dd/mm/yyyy转换为yyyymmdd输出 */
#include "stdio.h"
int main(void){
	int y,m,d;

	printf("Enter a date(dd/mm/yyyy): ");
	scanf("%d/%d/%d", &d, &m, &y);
	printf("You entered the date %.4d%.2d%.2d\n", y, m, d);
	return 0;
}