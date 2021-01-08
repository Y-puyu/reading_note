#include <stdio.h>
#include <stdlib.h>

int main() {
    char *buff = "   1213  212 12.21  212 2211   ";
    double a;
    while ((a = strtod(buff, &buff)) > 0) {
        printf("%lf ", a);
    }
    return 0;
}