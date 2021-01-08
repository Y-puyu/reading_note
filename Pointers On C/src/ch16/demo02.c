#include <stdio.h>

int main() {
    int a = 1 / 0;
    double b = 1.0 / 0.0;
    printf("%d %d\n", a, b);    
    // 80097088 232589248
    // 4779840 81262528
    return 0;
}