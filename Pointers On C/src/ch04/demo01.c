#include <stdio.h>

int main() {
    int flag = 0;
    // 空语句写法
    if (flag)
        ;
    else
        puts("hello");

    // 等价写法
    if (!flag)
        puts("hello");

    return 0;
}