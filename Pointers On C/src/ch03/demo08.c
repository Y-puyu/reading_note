#include <stdio.h>

int max(int x, int y) {
    return (x > y ? x : y);
}

int main() {
    int res = 0;
    extern int X;       // 先声明
    extern int Y;       
    res = max(X, Y);    // 就可以使用    
    printf("%d\n", res);    // 20
    return 0;
}

int X = 10;             // 最后定义
int Y = 20;