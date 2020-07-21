/* 输入借款金额，年利率，月还款额，计算出第一个月、第二个月、第三个月还款之后的余额*/
#include "stdio.h"
int main(void){
	float amount, rate, monthlyPayment, balance, monthlyRate;

	printf("Enter amount of loan: ");
	scanf("%f", &amount);
	printf("Enter interest rate: ");
	scanf("%f", &rate);
	printf("Enter monthly payment: ");
	scanf("%f", &monthlyPayment);

	monthlyRate = rate / 100.0f / 12.0f;
	balance = amount * (1 + monthlyRate) - monthlyPayment;
	printf("Balance remaining after first payment: %.2f\n", balance);
	balance = balance * (1 + monthlyRate) - monthlyPayment;
	printf("Balance remaining after second payment: %.2f\n", balance);
	balance = balance * (1 + monthlyRate) - monthlyPayment;
	printf("Balance remaining after third payment: %.2f\n", balance);
}