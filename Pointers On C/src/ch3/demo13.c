#include <stdio.h>

int main() {
    register int a = 10;
    int *p = &a;
    printf("%d", &a);
}