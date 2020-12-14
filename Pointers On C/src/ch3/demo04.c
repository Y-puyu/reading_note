#include <stdio.h>

typedef int *a; // 将a作为指向int类型指针的新名字

int main() {
    a b;
    *b = 1;
    printf("%d", *b);   // 1
    return 0;
}