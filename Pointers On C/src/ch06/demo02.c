#include <stdio.h>
#include <string.h>

char *find_char(char const *str, char const *chars) {
    char *t;
    if (str != NULL && chars != NULL) {
        while (*str != '\0') {
            t = chars;
            while (*t != '\0') {
                if (*str == *t)
                    return str;
                ++t;
            }
            ++str;
        }
    }
    return NULL;
}

int main() {
    char *a = "ABCDEF", *b = "CDE", *c = "FGH";
    char *d = find_char(a, b), *e = find_char(a, c);
    // 注意：并没有空指针判
    printf("%c %c\n", *d, *e);  // C F
    printf("%c %c\n", *strpbrk(a, b), *strpbrk(a, c)); // C F
    return 0;
}