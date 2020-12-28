#include <stdio.h>

int main() {
    char *a[10] = {"1234", "5678", "9ab"};
    char **ptr = a;
    printf("%s %s %s\n", *a, *a, *ptr);
    ptr += 1;
    printf("%s %s %s\n", *a, *a, *ptr);
    ptr = &a[1];
    printf("%s %s %s\n", *a, *a, *ptr);
}