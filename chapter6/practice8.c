/*
 * 8. 编写程序显示单月的日历。用户指定这个月的天数和该月起始日是星期几：
 * Enter number of days in month: 31
 * Enter starting day of the week (1=Sun, 7=Sat): 3
 *
 */
#include "stdio.h"
int main(void){
	int days, sdw;

	printf("Enter number of days in month: ");
	scanf("%d", &days);
	printf("Enter starting day of the week (1=Sun, 7=Sat):");
	scanf("%d", &sdw);
	
	for(int i=1,j=1; j<=days; i++){
		if(i >= sdw){
			printf("%8d", j++);
		}else{
			printf("\t");
		}
		if(i % 7 == 0){
			printf("\n");
		}
	}
	printf("\n");

	return 0;
}