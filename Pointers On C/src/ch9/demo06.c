#include <string.h>

char *my_strcpy_end(char *dst, const char *src) {
    strcpy(dst, src);
    return dst + strlen(src);
}

// 答案给出的高效方法
char *my_strcpy_end_1(register char *dst, register const char *src) {
    while ((*dst ++ = *src ++) != '\0')
        ;
    return dst - 1;
}