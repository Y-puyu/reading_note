#include <stdio.h>

long long foo(int n, int x) {
    if (n <= 0)
        return 1;
    if (n == 1)
        return 2 * x;
    return 2 * x * foo(n - 1, x) - 2 * (n - 1) * foo(n - 2, x);
}


int main() {
    printf("%d \n", foo(3, 2));
}