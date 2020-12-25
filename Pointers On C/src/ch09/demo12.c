#include <stdio.h>
#include <string.h>
#include <ctype.h>

int prepara_key(char *key) {
    register char *p, *dup;
    int ch;

    if (*key == '\0')
        return 0;

    for (p = key; (ch = *p) != '\0'; p ++) {
        if (!islower(ch)) {     // 如果不是小写字母
            if (!isupper(ch))   // 如果不是大写字母
                return 0;

            *p = tolower(ch);
        }
    }

    // 去重
    for (p = key; (ch = *p) != '\0'; ) {
        dup = ++p;
        while ((dup = strchr(dup, ch)) != NULL)
            strcpy(dup, dup + 1);           // UB?
    }

    for (ch = 'a'; ch <= 'z'; ch ++ ) {
        if (strchr(key, ch) == NULL) {
            *p++ = ch;
            *p = '\0';          // 细节啊！
        }
    }
}