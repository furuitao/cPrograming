#include "stdio.h"
int count(void);
int main(){
	for(int i=0; i<10; i++){
		count();
	}

	return 0;
}

int count(void){
	static int i = 2; // 只会初始化一次，后续多次调用该方法，将使用同一个变量
	printf("%d\n", i++);
	return i;
}
