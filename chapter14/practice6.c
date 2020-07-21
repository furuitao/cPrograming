/*
 * 6. (a) 编写宏DISP(f,x)，使其扩展为printf函数的调用，显示函数f在参数为x时的值。例如：
 * DISP(sqrt, 3.0);
 * 应该扩展为
 * printf("sqrt(%g) = %g\n", 3.0, sqrt(3.0));
 * (b) 编写宏DISP2(f,x,y)，类似DISP但应用于有两个参数的函数。
 */
#include "stdio.h"
#include "math.h"
#define DISP(f,x) printf(#f"(%g) = %g\n", x, f(x))
#define DISP2(f,x,y) printf(#f"(%g,%g) = %g\n", x, y, f((x), (y)))

int main(void){
	DISP(sqrt, 3.0);
	DISP2(pow, 3.0, 2.0);
	return 0;
}
