#include "stdio.h"
#include "stdbool.h"
#define N 10
int sum_array(const int a[], int n);
int sum_array_pointer(const int *a, int n);
bool search(const int a[], int n, int key);
void store_zeros(int a[], int n);
void print_arry(int a[], int n);
void find_two_largest(const int *a, int n, int *largest, int *second_largest);


int main(void){
	int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	printf("%d\n", sum_array(a, N));
	printf("%d\n", sum_array_pointer(a, N));
	printf("数组是否包含11: %d\n", search(a, N, 11));
	printf("数组是否包含5: %d\n", search(a, N, 5));


	int largest, second_largest;
	find_two_largest(a, N, &largest, &second_largest);
	printf("largest = %d, second_largest = %d\n", largest, second_largest);

	print_arry(a, N);
	store_zeros(a, N);
	print_arry(a, N);
	return 0;

}

int sum_array(const int a[], int n){
  int i, sum;
  sum = 0;
  for (i = 0; i < n; i++)
    sum += a[i];
  return sum;
}

int sum_array_pointer(const int *p, int n){
  int i, sum;
  sum = 0;
  while(n-- > 0){
  	sum += *(p++);
  }
  return sum;
}

bool search(const int a[], int n, int key){
	for(int i=0; i<n; i++){
		if(*(a++) == key){
			return true;
		}
	}
	return false;
}

void store_zeros(int a[], int n){
	while(n-- > 0){
		*(a++) = 0;
	}
}

void print_arry(int a[], int n){
	printf("%p\n", a);
	while(n-- > 0){
		printf("%d ", *(a++));
	}
	printf("\n");
	printf("%p\n", a);
}

void find_two_largest(const int *a, int n, int *largest, int *second_largest){
	*largest = *a;
	*second_largest = *a;
	while(n-- > 1){
		a++;
		if(*a > *largest){
			*second_largest = *largest;
			*largest = *a;
		}else if(*a > *second_largest){
			*second_largest = *a;
		}
	}
}
