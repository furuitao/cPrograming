/*
 * 2. 编写一个程序，要求用户输入24小时制的时间，然后显示12小时制的格式：
 * 
 * Enter a 24-hour time: 21:11
 * Equivalent 12-hour time: 9:11 PM
 *
 */
 #include "stdio.h"
 int main(void){
 	int h, m;

 	printf("Enter a 24-hour time: ");
 	scanf("%d:%d", &h, &m);

 	printf("Equivalent 12-hour time: ");
 	if(h > 12){
 		printf("%d", h % 12);
 	}else{
 		printf("%d", h);
 	}
 	
 	printf(":%.2d", m);

 	if(h >= 12){
 		printf(" PM\n");
 	}else{
 		printf(" AM\n");
 	}
 	return 0;
 }