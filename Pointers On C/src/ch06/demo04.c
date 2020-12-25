#include <stdio.h>

void reverse_string1(char *s) {
    int n = 0;
    char *t = s;
    while (*t++ != '\0')
        ++n;
    for (int i = 0, j = n - 1; i < j; ) {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
        ++i, --j;
    }
}

void reverse_string2(char *s) {
    char *t = s;
    /* 会越界指向
    while (*t++ != '\0')
        ;
    t--;
    t--;    
    */
    while (*t != '\0') t ++;
    t--;

    // for 
    while (s < t) {
        char c = *s;
        *s++ = *t;
        *t-- = c;
    }
}

int main() {
    char s[] = "ABCDEFG";
    reverse_string1(s);
    printf("%s\n", s);
    reverse_string2(s);
    printf("%s\n", s);

    return 0;
}