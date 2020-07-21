#include "stdio.h"
#define MAX 24 * 60 * 60
void split_time(long total_sec, int *hr, int *min, int *sec);

int main(void){
	long l;
	int hr, min, sec;
	printf("输入1 ~ %d的时间：", MAX - 1);
	scanf("%ld", &l);
	split_time(l, &hr, &min, &sec);
	printf("hr=%d, min=%d, sec=%d\n", hr, min, sec);
}

void split_time(long total_sec, int *hr, int *min, int *sec){
	total_sec %= MAX;// 防止过大的值
	*sec = total_sec % 60;
	total_sec /= 60;
	*min = total_sec % 60;
	total_sec /= 60;
	*hr = total_sec;
}