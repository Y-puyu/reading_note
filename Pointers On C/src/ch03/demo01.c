#include <stdio.h>
#include <limits.h>

int main() {
    printf("%d\n", INT_MAX);
    printf("%d\n", INT_MIN);
    puts("");
    printf("%d\n", SCHAR_MAX);
    printf("%d\n", SCHAR_MIN);
    printf("%d\n", UCHAR_MAX);
    puts("");
    printf("%d\n", LONG_MAX);
    printf("%d\n", LONG_MIN);

    return 0;
}

/*
2147483647
-2147483648

127
-128
255

2147483647
-2147483648
*/