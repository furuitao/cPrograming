#include <stdio.h>

int main(void){
    printf("标志作用于%%d转换的效果：\n\n");
    printf("  %%8d:|%8d|%8d|\n", 123, -123);
    printf(" %%-8d:|%-8d|%-8d|\n", 123, -123);
    printf(" %%+8d:|%+8d|%+8d|\n", 123, -123);
    printf(" %% 8d:|% 8d|% 8d|\n", 123, -123);
    printf(" %%08d:|%08d|%08d|\n", 123, -123);
    printf("%%-+8d:|%-+8d|%-+8d|\n", 123, -123);
    printf("%%- 8d:|%- 8d|%- 8d|\n", 123, -123);
    printf("%%+08d:|%+08d|%+08d|\n", 123, -123);
    printf("%% 08d:|% 08d|% 08d|\n", 123, -123);

    printf("\n\n标志#作用于o、x、X、g和G转换的效果:\n\n");
    printf(" %%8o:|%8o|\n", 123);
    printf("%%#8o:|%#8o|\n", 123);
    printf(" %%8x:|%8x|\n", 123);
    printf("%%#8x:|%#8x|\n", 123);
    printf(" %%8X:|%8X|\n", 123);
    printf("%%#8X:|%#8X|\n", 123);
    printf(" %%8g:|%8g|\n", 123.0);
    printf("%%#8g:|%#8g|\n", 123.0);
    printf(" %%8G:|%8G|\n", 123.0);
    printf("%%#8G:|%#8G|\n", 123.0);

    printf("\n\n 最小字段宽度和精度作用于转换%%s的效果\n\n");
    printf("   %%6s|%6s|%6s|\n", "bogus", "buzzword");
    printf("  %%-6s|%-6s|%-6s|\n", "bogus", "buzzword");
    printf("  %%.4s|%.4s|%.4s|\n", "bogus", "buzzword");
    printf(" %%6.4s|%6.4s|%6.4s|\n", "bogus", "buzzword");
    printf("%%-6.4s|%-6.4s|%-6.4s|\n", "bogus", "buzzword");
    
    printf("\n\n %%g转换的示例\n\n");
    printf("%.4g\n", 123456.);
    printf("%.4g\n", 12345.6);
    printf("%.4g\n", 1234.56);
    printf("%.4g\n", 123.456);
    printf("%.4g\n", 12.3456);
    printf("%.4g\n", 1.23456);
    printf("%.4g\n", 0.123456);
    printf("%.4g\n", 0.0123456);
    printf("%.4g\n", 0.00123456);
    printf("%.4g\n", 0.000123456);
    printf("%.4g\n", 0.0000123456);
    printf("%.4g\n", 0.00000123456);
    printf("%.4g\n", 0.000000123456);

    printf("\n\n使用*录入宽度变量\n\n");
    int i = 12345;
    printf("|%6.4d|\n", i);
    printf("|%*.4d|\n", 6, i);
    printf("|%6.*d|\n", 4, i);
    printf("|%*.*d|\n", 6, 4, i);

}