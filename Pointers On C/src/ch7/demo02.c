#include <stdio.h>

void b2a(int n) {
    if (n == 0)
        return;
    b2a(n / 10);
    printf("%d ", n % 10);  // 4 2 6 7
}

int main() {
    b2a(4267);
    return 0;
}