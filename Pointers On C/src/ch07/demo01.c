#include <stdio.h>

int find_max(int a, int b) {
    return a > b ? a : b;
}

// K&R C 函数定义方式
int find_max1(a, b) 
int a;
int b;
{
    return a > b ? a : b;
}

int add(int a) {
    a += 1;
}

float find_max3(int a, float b) {
    return a > b ? a : b;
}

int main() {
    int a = 1, b = 2;
    printf("%d\n", find_max(a, b));
    printf("%d\n", find_max1(a, b));

    printf("%d\n", 1 + add(5));      // 无返回值，不报错，结果为 1

    printf("%lf\n", find_max2(1, 3.14));  // 78641712。浮点数在内存中的方式被按照int来读。然而并没有想通这个合理的解释

    printf("%lf\n", find_max3(1, 3.14));  // 3

    float c = f();
    printf("%d %f\n", c, c);
    return 0;
}

// 未进行声明，直接调用。且不匹配的情况下，编译器会自动将不匹配的实参或者返回值转换为正确的类型
int find_max2(int a, double b) {
    return a > b ? a : b;
}

/*
float f() {                // conflicting types for 直接报错，不知道切换到c89版本能否成功
    return 3.14;
}
*/