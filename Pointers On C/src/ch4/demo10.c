#include <stdio.h>

int main() {
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);

    double temp;
    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }
    if (a < c) {
        temp = a;
        a = c;
        c = temp;
    }
    if (b < c) {
        temp = b;
        b = c;
        c = temp;
    }
    
    if (c <= 0 || b + c < a)
        printf("不是三角形.\n");
    else if (a == b && b == c)
        printf("等边.\n");
    else if (a == b || b == c)
        printf("等腰.\n");
    else
        printf("不等边\n");
    return 0;
}