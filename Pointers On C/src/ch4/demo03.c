#include <stdio.h>

int main() {
    int x, y, a, b;
    scanf("%d%d%d%d", &x, &y, &a, &b);
    
    if (x < y || a >= b)
        puts("WRONG");
    else
        puts("RIGHT");

    return 0;
}