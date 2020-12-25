#include <string.h>
#include <stddef.h>

size_t my_strlen(const char *string, int size) {
    size_t i = 0;
    for (i; i < size; i ++ ) 
        if (*string ++ == '\0')
            break;
    return i;
}

char *my_strcat(char *dst, char const *src, int size) {
    int length;
    size -= 1;
    length = size - (int)my_strlen(dst, size);
    if (length > 0) {
        strncat(dst, src, length);
        dst[size] = '\0';
    }
    return dst;
}