#include <stdio.h>

int main() {
    int year;
    scanf("%d", &year);

    int leap_year = 0;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        leap_year = 1;
    else
        leap_year = 0;

    printf("%d\n", leap_year);
    return 0;
}