#include "stdio.h"
int main(void){
	int i,j,k;

	i=5;
	j=3;
	printf("%d %d\n", i / j, i % j);//输出1 2

	i=2;
	j=3;
	printf("%d\n", (i + 10) % j); //输出0

	i=7;j=8;k=9;
	printf("%d\n", (i + 10) % k / j); //输出1

	i=1;j=2;k=3;
	printf("%d\n", (i + 5) % (j + 2) / k);//输出0

	i=7;j=3;
	printf("%d %d\n", (-i)/j, -(i/j));//输出-2 -2
	printf("%d %d\n", (-i)%j, -(i%j));//输出-1 -1


	i=7;j=8;
	i *= j + 1;
	printf("%d %d\n", i, j);//输出63 8

	i = j = k = 1;
	i += j += k;
	printf("%d %d %d\n", i, j, k);//输出3 2 1

	i = 1; j = 2; k = 3;
	i -= j -= k;
	printf("%d %d %d\n", i, j, k);//输出0 -1 3

	i = 2; j = 1; k = 0;
	i *= j *= k;
	printf("%d %d %d\n", i, j, k);//0 0 0

	i = 6;
	j = i += i;
	printf("%d %d\n", i, j);//12 12

	i = 5;
	j = (i -= 2) + 1;
	printf("%d %d\n", i, j);//3 4

	i = 7;
	j = 6 + (i = 2.5);
	printf("%d %d\n", i, j);//2 8

	i = 2; j = 8;
	j = (i = 6) + (j = 3);
	printf("%d %d\n", i, j);//6 9

	i = 1;
	printf("%d\n", i++ - 1);//0
	printf("%d\n", i);//2

	i = 10; j = 5;
	printf("%d\n", i++ - ++j);//4
	printf("%d %d\n", i, j);//11 6

	i = 7; j = 8;
	printf("%d\n", i++ - --j);//0
	printf("%d %d\n", i, j);//8 7

	i = 3; j = 4; k = 5;
	printf("%d \n", i++ - j++ + --k);//3
	printf("%d %d %d\n", i, j, k);//4 5 4

	i = 5;
	j = ++i * 3 - 2;
	printf("%d %d\n", i, j);//6 16

	i = 5;
	j = 3 - 2 * i++;
	printf("%d %d\n", i, j);//6 -7
	
	i = 7;
	j = 3 * i-- + 2;
	printf("%d %d\n", i, j);//6 23
	
	i = 7;
	j = 3 + --i * 2;
	printf("%d %d\n", i, j);//6 15

	i=1;
	printf("%d\n", ++i);//2
	i=1;
	printf("%d\n", i++);//1
	i=1;
	printf("%d\n", i+=1);//2
	return 0;
}