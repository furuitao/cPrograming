/*
 * 使用指针计算数组中的平均值和累加值
 */
#include "stdio.h"
void avg_sum(double a[], int n, double *avg, double *sum);

int main(void){
	double a[10] = {9,30.4,55,3,280,44,233};
	double avg, sum;
	avg_sum(a, 7, &avg, &sum);
	printf("avg = %.2f, sum = %.2f\n", avg, sum);
}

void avg_sum(double a[], int n, double *avg, double *sum){
	int i;
	*sum = 0.0;
	for (int i = 0; i < n; ++i){
		*sum += a[i];
	}
	*avg = *sum / n;
}