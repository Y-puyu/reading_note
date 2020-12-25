#include <stdio.h>

const double eps = 1e-6;

int main() {
    double x;
    scanf("%lf", &x);

    if (x < 0)
        puts("error");

    double new = 1, last;
    do {
        last = new;
        new = (last + x / last) / 2;
        printf("%.4lf\n", new);
    } while (last - new <= eps);

    return 0;
}