// 可变参数函数

#include <stdio.h>
#include <stdarg.h>

float average(int n, ...) {
    va_list var_arg;
    float sum = 0;

    // 准备访问可变参
    va_start(var_arg, n);

    // 添加取自可变参数列表的值
    for (int i = 0; i < n; i ++ ) {
        sum += va_arg(var_arg, int);
    }

    va_end(var_arg);

    return sum / n;
}

int main() {
    printf("%f \n", average(3, 1, 2, 3));   // 2.000000
    printf("%f \n", average(2, 1, 2, 3));   // 1.500000,可以中途停止
    printf("%f \n", average(3, 1, 2.5, 3.5));   // 0.333333,如果类型不匹配，整形直接将float视为0

    // printf 作为一个可变参函数，其格式字符串指明了参数的数量和类型
}