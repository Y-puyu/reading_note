#include <stdio.h>
#include <string.h>

char *my_strnchr(const char *str, int ch, int which) {
    char *last = NULL;
    // which 也可能出现小于 0 的情况
    for (; --which >= 0 && (str = strchr(str, ch)) != NULL; str += 1) 
        last = str;
    return last;
}