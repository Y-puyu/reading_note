#include <stdio.h>
#include <stdarg.h>

int max_list(int first, ...) {
    va_list var_arg;
    int max = 0;
    if (first >= 0) {
        int this = 0;
        max = first;
        va_start(var_arg, first);
        while ((this = va_arg(var_arg, int)) >= 0)
            if (this > max) 
                max = this;
        va_end(var_arg);
    }
    return max;
}

int main() {
    printf("%d\n", max_list(1, 2, 3, 4, 5, 6, -1));
}