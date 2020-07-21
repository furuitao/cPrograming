#include <stdio.h>

int count_ones(unsigned char ch);
int count_ones1(unsigned char ch);
unsigned int reverse_bits(unsigned int n);

int main(void){
    char ch = 0b00001111;
    printf("%d\n", count_ones(ch));
    printf("%d\n", count_ones1(ch));

    printf("%d reverse %x\n", 3, reverse_bits(3));
}

int count_ones(unsigned char ch){
    int count = 0;
    unsigned int c = (unsigned int) ch;
    while(c != 0){
        if(c & 1){
            count ++;
        }
        c >>= 1;
    }
    return count;
}

int count_ones1(unsigned char ch){
    struct s{
        unsigned int a:1;
        unsigned int b:1;
        unsigned int c:1;
        unsigned int d:1;
        unsigned int e:1;
        unsigned int f:1;
        unsigned int g:1;
        unsigned int h:1;
    };
    struct s *c = (struct s *) &ch;
    return c->a + c->b + c->c + c->d + c->e + c->f + c->g + c->h;
}

unsigned int reverse_bits(unsigned int n){
    int r = 0;
    r |= (n & 1);
    for(int i=1; i<32; i++){
        n >>= 1;
        r <<= 1;
        r |= (n & 1);
    }
    return r;
}