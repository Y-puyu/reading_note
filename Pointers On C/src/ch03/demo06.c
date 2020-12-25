#include <stdio.h>

int cur = 0;

int f() {
    int a = 1;
    printf("%d   %p\n", a, a);
    for (int i = 0; i < 5; ++i) {
        int a = 10;             // 就近原则，覆盖掉外面的变量a
        printf("%d   %p\n", a, a);
        ++cur;
    }
    for (int i = 0; i < 5; ++i) {
        int a = 10;             // 就近原则，覆盖掉外面的变量a
        printf("%d   %p\n", a, a);  // 地址和上面的for循环内部的a相同
        ++cur;
    }
    printf("%d   %p\n", a, a);

}

// int fun(int){}
// c++ 可以这样。c语言报错
// 存在正文时不允许未命名的原型参数
int fun(int x) {   
    // 形参x在该版本作用域已经拓展到整个函数。故同一个作用域下不允许出现同名变量
    // int x = 10;     // 一个变量只能声明一次，redeclared as different kind of symbol
    return x;
}

int main() {
    f();
    ++cur;
    printf("%d\n", cur);    // 11

    puts("");
    puts("");
    puts("");

    printf("%d\n", fun(10));
    return 0;
}