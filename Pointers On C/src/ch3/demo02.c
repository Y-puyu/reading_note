#include <stdio.h>

int main() {
    char a = 'a';
    char b = 'bbb';     // 不好打印
    printf("%c   %c", a, b);

    int c = 2147483647;
    unsigned long d = 2148473649UL;
    printf("%d   %u", c, d);

    char e = L'X';
    printf("%c", e);

    return 0;
}