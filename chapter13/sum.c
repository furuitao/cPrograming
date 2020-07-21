#include "stdio.h"
#include "stdlib.h"
int main(int argc, char const *argv[])
{
	int sum = 0;
	while(argc-- > 1){
		sum += atoi(argv[argc]);
	}
	printf("%d\n", sum);
	return 0;
}