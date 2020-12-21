#include <stdio.h>

void foo(int a[5], int b[5]) {
    printf("%d %p\n", *a, a);
    printf("%d %p\n", *b, b);
    
}

int main() {
    int a[10] = {1, 2, 3, 4, 5, 6};
    printf("%d %p\n", *a, a);
    foo(a, &a[5]);
}