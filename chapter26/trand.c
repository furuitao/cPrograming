#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void testSeed(void){
    int seed;
    printf("This program displays the first five values of rand.\n");

    for(;;){
        for(int i=0; i<5; i++){
            printf("%d ", rand());
        }
        printf("\n");

        printf("Enter new seed values (0 to terminates): ");
        scanf("%d", &seed);
        if(seed == 0){
            break;
        }
        srand(seed);
    }
}

int randInt(void){
    int arr[4] = {7,11,15,19};
    srand(clock());
    return arr[rand()%4];
}

double randDouble(void){
    srand(clock());
    int r = rand();
    double d = (r % 10) / 10.0;
    return d;
}

void print_rand(void){
    char arr[1001];
    for (int i = 0; i < 1000; ++i)
    {
        arr[i] = '0' + (rand() & 1);
    }
    arr[1000] = '\0';
    printf("%s\n", arr);
}

int main(void){
    printf("随机数最大值：%d\n", RAND_MAX);

    testSeed();
    for(int i=0; i<10; i++){
        printf("%d ", randInt());
    }
    printf("\n");
    for (int i = 0; i < 10; ++i){
        printf("%.1lf ", randDouble());
    }
    printf("\n");
    print_rand();
    return 0;
}