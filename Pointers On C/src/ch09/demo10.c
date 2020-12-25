#include <stdio.h>
#include <string.h>
#include <ctype.h>

int palindrome(char *string) {
    for (char *end = string + strlen(string) - 1; ; ) {
        if (!isalpha(*string))
            string++;
        if (!isalpha(*end))
            end--;
        if (end <= string)
            return 1;
        if (tolower(*string) != tolower(*end))
            return 0;
        string++;
        end--;
    }
}