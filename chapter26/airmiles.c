#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct city_info{
    char *city;
    int miles;
};

int search_compare(const void *key_ptr, const void *element_ptr);
int sort_compare(const void *ptr1, const void *ptr2);

int main(void){
    char cityname[81];
    struct city_info *ptr;
    struct city_info mileage[] = 
    {
     {"Berlin",         3965}, {"Buenos Aires", 5297},
     {"Cairo",          5602}, {"Calcutta",     7918},
     {"Cape Town",      7764}, {"Caracas",      2132},
     {"San Francisco",  2571}, {"Shanghai",     7371},// 错误的位置，需要通过排序矫正
     {"Chicago",         713}, {"Hong Kong",    8054},
     {"Honolulu",       4964}, {"Istanbul",     4975},
     {"Lisbon",         3364}, {"London",       3458},
     {"Los Angeles",    2451}, {"Manila",       8498},
     {"Mexico City",    2094}, {"Montreal",      320},
     {"Moscow",         4665}, {"Paris",        3624},
     {"Rio de Janeiro", 4817}, {"Rome",         4281},
     {"Stockholm",      3924}, {"Sydney",       9933},
     {"Tokyo",          6740}, {"Warsaw",       4344},
     {"Washington",     205}
    };
    printf("Enter cityname: ");
    scanf("%80[^\n]", cityname);
    qsort(mileage, sizeof(mileage)/sizeof(mileage[0]), sizeof(mileage[0]), sort_compare);// 执行排序
    // 采用二分法查找，所以需要先排序
    ptr = bsearch(cityname, mileage, sizeof(mileage)/sizeof(mileage[0]), sizeof(mileage[0]), search_compare);

    if(ptr != NULL){
        printf("%s is %d miles from New York City.\n", cityname, ptr -> miles);
    }else{
        printf("%s wasn't found.\n", cityname);
    }
    return 0;
}

int search_compare(const void *key_ptr, const void *element_ptr){
    return strcmp((char *)key_ptr, ((struct city_info *)element_ptr) -> city);
}

int sort_compare(const void *ptr1, const void *ptr2){
    return strcmp(((struct city_info *)ptr1) -> city, ((struct city_info *)ptr2) -> city);
}