#include <stdio.h>
#include <string.h>
#include <stddef.h>

size_t my_strlen(const char *string, int size) {
    size_t i = 0;
    for (i; i < size; i ++ ) 
        if (*string ++ == '\0')
            break;
    return i;
}

int main() {
    char a[10] = "1234567";
    char b[5] = "567";
    strncat(a, b, 3);
    puts(a);
}