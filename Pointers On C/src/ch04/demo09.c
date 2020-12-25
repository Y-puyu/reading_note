#include <stdio.h>

int main() {
    int n = 100;
    for (int i = 2; i <= n; ++i) {
        int flag = 0;
        for (int j = 2; j <= i / j; ++j)
            if (i % j == 0) {
                flag = 1;
                break;
            }
        if (!flag)
            printf("%d\n", i);
    }
    return 0;
}