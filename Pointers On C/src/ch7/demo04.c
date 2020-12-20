#include <stdio.h>

int find_max(int a[10]) {
    int res = a[0];
    for (int i = 0; i < 10; ++i) {
        if (res < a[i])
            res = a[i];
    }
    return res;
}

int main() {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%d\n", find_max(a));    // 10
}