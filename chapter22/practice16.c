#include <stdio.h>

int main(void){
    char *pattern = "%*[^#]#%[,0-9]";
    char *str = "aaaabbb#234,333,abcd";
    char data[20];
    sscanf(str, pattern, data);
    printf("%s\n", data);

    return 0;
}