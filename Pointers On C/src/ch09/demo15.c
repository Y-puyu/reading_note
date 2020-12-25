#include <stdio.h>

void dollars(char *dst, const char *src) {
    int len;
    if (dst == NULL || src == NULL)
        return;
    
    *dst++ = '$';
    len = strlen(src);

    if (len >= 3) {
        for (int i = len - 2; i > 0 ; ) {
            *dst++ = *src++;
            if (-- i > 0 && i % 3 == 0)
                *dst++ = ',';
        }
    }
    else
        *dst++ = '0';
    *dst++ = '.';
    *dst++ = len < 2 ? '0' : *src++;
    *dst++ = len < 1 ? '0' : *src;
    *dst = 0;
}