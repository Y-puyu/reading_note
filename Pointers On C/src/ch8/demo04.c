#include <stdio.h>
#include <float.h>

static double income_list[] = {
    0, 23350, 56550, 117950, 256500, DBL_MAX};
static double base_tax[] = {
    0, 3502.5, 12798.5, 31832.5, 81710.5};
static float percentage[] = {
    .15, .28, .31, .36, .396};

double single_tax(double income) {
    int i = 1;
    for (i; income >= income_list[i]; i++)
        ;
    i--;
    return base_tax[i] + percentage[i] * (income - income_list[i]);
}