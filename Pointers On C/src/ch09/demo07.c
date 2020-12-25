#include <stdio.h>
#include <string.h>

char *my_strrchr(const char *str, int ch) {
    char *last = NULL;
    for (; (str = strchr(str, ch)) != NULL; str += 1)
        last = str;
    return last;
}