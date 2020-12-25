#include <stdio.h>

int main() {
    int ch;

    // while ((ch = getchar()) != EOF)
    //   putchar(tolower(ch));

    while ((ch = getchar()) != EOF) {
        if (ch >= 'A' && ch <= 'Z')
            ch += 'a' - 'A';
        putchar(ch);
    }

    return 0;
}