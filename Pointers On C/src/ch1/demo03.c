#include <stdio.h>
#include <stdlib.h>

int main() {
    int a;
    char sum = -1;
    char c = 0377;      // signed char 255 = -1 unsigned char 255 = 255
    unsigned char d = 0377;
    a = c;
    printf("%d\n", a);  // -1
    a = d;
    printf("%d\n", a);  // 255

    while ((a = getchar()) != EOF) {
        putchar(a);
        sum += a;
    }
    printf("%d\n", sum);
    return 0;
}