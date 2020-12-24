#include <ctype.h>

void encrypt(char *data, const char *key) {
    register int ch;
    for (; (ch = *data) != '\0'; data ++) {
        if (islower(ch))
            *data = key[ch - 'a'];
        else if (isupper(ch))
            *data = toupper(key[ch - 'A']);
    }
}