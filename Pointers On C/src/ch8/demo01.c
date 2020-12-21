#include <stdio.h>

int main() {
    int a[10] = {1,2,7,3,4,5,6};
    int i = 1, j = 2;
    int *c = a;
    printf("%d %d\n", a[i + j], i + j[a]);
    printf("%d\n", c[3]);
}