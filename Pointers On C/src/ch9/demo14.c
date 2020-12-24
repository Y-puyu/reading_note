#include <ctype.h>
#include <string.h>

void decrypt(char *data, const char *key) {
    int ch;
    static char word[] = "abcdefghijklmnopqrstuvwxyz";
    
    for (; (ch = *data) != '\0'; data ++ ) {
        if (islower(ch))
            *data = word[strchr(key, ch) - key];
        else if (isupper(ch))
            *data = toupper(word[strchr(key, tolower(ch)) - key]);
    }
}