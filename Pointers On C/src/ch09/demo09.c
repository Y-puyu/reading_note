#include <stdio.h>
#include <string.h>

int count_chars(char *str, const char *chars) {
    int count = 0;
    while ((str = strpbrk(str, chars)) != NULL) {
        count += 1;
        str++;
    }
    return count;
}