#include <stdio.h>

int substr(char dst[], char src[], int start, int len) {
    int d = 0, s = 0;
    if (start >= 0 && len > 0) {
        for (s; s < start && src[s] != '\0'; s++)
            ;
        
        while (len > 0 && src[s] != '\0') {
            dst[d++] = src[s++];
            len--;
        }
    }
    dst[d] = '\0';
    return d;
}

int main() {
    char a[10] = "01234567", b[10];
    substr(b, a, 2, 3);
    puts(b);
    return 0;
}

/*
234
*/