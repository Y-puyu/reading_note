#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *calloc(void *dst, size_t n, size_t size) {
    char *memory = (char *)malloc(n * size);
    if (memory != NULL) {
        char *ptr = memory;
        while (n --) {
            *ptr++ = '\0';
        }
    }
    return memory;
}