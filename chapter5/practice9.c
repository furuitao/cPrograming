/*
 * 9. 编写一个程序，提示用户输入两个日期，然后显示哪一个日期更早：
 * 
 * Enter first date (mm/dd/yy): 3/6/08
 * Enter second date (mm/dd/yy): 5/17/07
 * 5/17/07 is earlier than 3/6/08
 *
 */
#include "stdio.h"
#include "stdbool.h"
int main(void){
	int y1,m1,d1,y2,m2,d2;
	bool first;

	printf("Enter first date (mm/dd/yy): ");
	scanf("%d/%d/%d", &m1, &d1, &y1);

	printf("Enter second date (mm/dd/yy): ");
	scanf("%d/%d/%d", &m2, &d2, &y2);

	if(y1 < y2){
		first = true;
	}else if(y1 > y2){
		first = false;
	}else{
		if(m1 < m2){
			first = true;
		}else if(m1 > m2){
			first = false;
		}else {
			if(d1 < d2){
				first = true;
			}else{
				first = false;
			}
		}
	}
	printf("%d/%d/%.2d", first ? m1 : m2, first ? d1 : d2, first ? y1 : y2);
	printf(" is earlier than ");
	printf("%d/%d/%.2d", !first ? m1 : m2, !first ? d1 : d2, !first ? y1 : y2);

	printf("\n");
	return 0;
}