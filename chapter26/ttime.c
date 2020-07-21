#include <stdio.h>
#include <time.h>

int main(void){
    clock_t s = clock();

    printf("Processer time used %g sec.\n", (clock() - s) / (double)CLOCKS_PER_SEC);
    printf("%lu, CLOCKS_PER_SEC=%d\n", clock(), CLOCKS_PER_SEC);

    return 0;
}