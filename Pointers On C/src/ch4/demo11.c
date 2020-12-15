#include <stdio.h>

void copy_n(char dst[], char src[], int n) {
    int dst_index, src_index = 0;
    for (dst_index = 0; dst_index < n; dst_index ++) {
        dst[dst_index] = src[src_index];
        if (src[src_index] != 0)
            src_index++;
    }
}

int main() {
    char a[10] = "012345678", b[10];
    copy_n(b, a, 5);
    puts(a);
    puts(b);
}

/*
012345678901234
01234
*/
