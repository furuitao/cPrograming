#include "stdio.h"
int main(void){
	int i,j,k;

	i = 2; j = 3;
	k = i * j == 6;
	printf("%d\n", k);//1

	i = 5; j = 10; k = 1;
	printf("%d\n", k > i < j);//1

	i = 3; j = 2; k = 1;
	printf("%d\n", i < j == j < k);//1

	i = 3; j = 4; k = 5;
	printf("%d\n", i % j + i < k);//0

	i = 10; j = 5;
	printf("%d\n", !i < j);//1

	i = 2; j = 1;
	printf("%d\n", !!i + !j);//1

	i = 5; j = 0; k = -5;
	printf("%d\n", i && j || k);//1

	i = 1; j = 2; k = 3;
	printf("%d\n", i < j || k);//1

	i = 3; j = 4; k = 5;
	printf("%d\n", i < j || ++j < k);//1
	printf("%d %d %d\n", i, j, k);//3 4 5

	i = 7; j = 8; k = 9;
	printf("%d\n", i - 7 && j++ < k);//0
	printf("%d %d %d\n", i, j, k);//7 8 9

	i = 7; j = 8; k = 9;
	printf("%d\n", (i =  j) || (j = k));//1
	printf("%d %d %d\n", i, j, k);// 8 8 9 

	i = 1; j = 1; k = 1;
	printf("%d\n", ++i || ++j && ++k);//1
	printf("%d %d %d\n", i, j, k);//2 1 1

	/*
	 * 表达式：(i>=j) - (i<=j)
     * i<j = -1
     * i==j = 0
     * i>j = 1
	 */
	i=1,j=2;
    printf("i<j = %d\n", (i>=j) - (i<=j));
	i=2,j=2;
    printf("i==j = %d\n", (i>=j) - (i<=j));
	i=2,j=1;
    printf("i>j = %d\n", (i>=j) - (i<=j));

    int n;
    n = 0;
    if (n >= 1 <= 10)//1
  		printf ("n is between 1 and 10\n");//正常输出
  	n = 5;
  	if (n == 1 - 10)//0
 		 printf ("n is between 1 and 10\n");//不输出

	i = 1;
	switch (i % 3) {
	  case 0: printf("zero");
	  case 1: printf("one");
	  case 2: printf("two");
	}//onetwo
	printf("\n");

	return 0;
}