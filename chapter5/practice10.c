/*
 * 10. 利用switch语句编写一个程序，把用数字表示的成绩转化为字母表示的等级。
 * A为90～100，B为80～89，C为70～79，D为60～69，F为0～59
 *
 * Enter numerical grade: 84
 * Letter grade: B
 *
 */
#include "stdio.h"
int main(void){
	int grade;

	printf("Enter numerical grade: ");
	scanf("%d", &grade);

	printf("Letter grade: ");
	if(grade >= 0 && grade <= 100){
		switch(grade / 10){
			case 0: case 1: case 2: case 3: case 4: case 5:
				printf("F\n"); break;
			case 6:
				printf("D\n"); break;
			case 7:
				printf("C\n"); break;
			case 8:
				printf("B\n"); break;
			case 9: case 10:
				printf("A\n"); break;
		}
	}else{
		printf("Error numerical grade: %d. Please enter 0 ~ 100.\n", grade);
	}

	return 0;
}