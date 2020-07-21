#include <stdio.h>

#define MK_COLOR(r,g,b) ((((r) & 0xff) << 16) | (((g) & 0xff) << 8) | ((b) & 0xff))
#define GET_RED(c) (((c) & 0xff0000) >> 16)
#define GET_GREEN(c) (((c) & 0xff00) >> 8)
#define GET_BLUE(c) ((c) & 0xff)

int main(void){
    
    unsigned long l = MK_COLOR(234, 123, 88);
    
    printf("%lx\n", l);
    printf("RED=%d, %x\n", (int)GET_RED(l), (int)GET_RED(l));
    printf("GREEN=%d, %x\n", (int)GET_GREEN(l), (int)GET_GREEN(l));
    printf("BLUE=%d, %x\n", (int)GET_BLUE(l), (int)GET_BLUE(l));
}