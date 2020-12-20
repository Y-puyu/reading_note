#include <stdio.h>
#include <string.h>

int s2i(char *s) {
    int res = 0;
    while (*s != '\0') {
        res = res * 10 + *s - '0';
        *s++;
    }
    return res;
}

int main() {
    char *s = "1234";
    printf("%d %d\n", atoi(s), s2i(s));
}