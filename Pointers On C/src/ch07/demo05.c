#include <stdio.h>

int cnt = 0;

long long fib(int n) {
    ++cnt;
    if (n <= 2)
        return 1;
    return fib(n - 1) + fib(n - 2);
}


int main() {
    printf("%d %d\n", cnt, fib(5)); // 9 5
    printf("%d %d\n", fib(5), cnt); // 9 0  printf函数压栈顺序，从右向左


    printf("%d %d\n", cnt, fib(100)); // 风扇飞起
}