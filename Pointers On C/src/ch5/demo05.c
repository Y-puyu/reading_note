#include <stdio.h>

int main() {
    int a = 25;
    unsigned int b = 0;

    for (int i = 0, j = 31; i <= 31; ++i, --j) {
        if (a & 1 << i)
            b |= 1 << j;
    }
    printf("%u\n", b);  // 2550136832
    return 0;
}