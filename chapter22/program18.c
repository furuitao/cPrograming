/*
 * 18. 编写程序从文本文件中读取整数，文本文件的名字由命令行参数给出。文件的每一行可以包含任意数量的整数（也可以没有），中间用一个或多个空格隔开。程序显示文件中最大的数、最小的数以及中值（整数有序情况下最接近中间的那个数）。
 *     如果文件包含偶数个整数，中间会有两个整数，程序显示它们的均值（向下取整）。可以假定文件包含的整数个数不超过10000。提示：把整数存储在数组中并对其排序。
 * 
 */
#include <stdio.h>
#include <stdlib.h>

int read_array(const char *filename, int arr[]);
int compare_int(const void *, const void*);

void print_arry(int arry[], int len){
    for(int i=0; i<len; i++){
        printf("%d ", arry[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    if(argc != 2){
        printf("请输入文件名\n");
        return 1;
    }
    int arry[10000];
    // 读取数据
    int len = read_array(argv[1], arry);
    print_arry(arry, len);
    // 排序
    qsort(arry, len, sizeof(int), compare_int);
    print_arry(arry, len);
    // 求中值
    int mid = arry[len/2];
    if(len % 2 == 0){
        mid = (arry[len/2] + arry[len/2-1])/2;
    }
    // 打印结果
    printf("最小值：%d\n", arry[0]);
    printf("最大值：%d\n", arry[len-1]);
    printf("  中值：%d\n", mid);
    return 0;
}

int read_array(const char *filename, int arr[]){
    FILE *fp = fopen(filename, "r");
    int len = 0;
    int n;
    if(fp != NULL){
        while(fscanf(fp, " %d", &n) == 1){
            arr[len++] = n;
        }
        fclose(fp);
    }
    return len;
}

int compare_int(const void *i1, const void *i2){
    return *(int *)i1 - *(int *)i2;
}
