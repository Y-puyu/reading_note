#include <stdio.h>

int a() {
    auto x = 10;
}

int b() {
    static int c = 15;
}

int main() {
    // extern int x;
    // printf("%d\n", x);
    
    // printf("%d\n", c);

    return 0;
}