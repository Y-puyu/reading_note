#include <stdio.h>

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    int *p1 = &a[0], *p2 = &a[4];
    printf("%d %d\n", p1 - p2, p2 - p1);    // -4 4
    printf("%d %d\n", p1 - p2, p2 - 10);    // -4 6421944

    int b[5] = {1, 2, 3, 4, 5};
    int *p3 = &b[1], *p4 = &b[6];
    printf("%d %d\n", p1 - p3, p3 - p1);    // -9 9
    printf("%d %d\n", p3 - p4, p4 - p3);    // -5 5
    printf("%d %d\n", *p3 - *p4, *p4 - *p3);    // -47 47


    for (int *p5 = &b[0]; p5 != &b[5]; ) {
        *p5++ = 0;
    }
    for (int i = 0; i < 5; ++i)
        printf("%d ", b[i]);
    puts("");
    return 0;
}