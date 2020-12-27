#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define BUFFER 1024

char *readString() {
    char *buff = NULL;
    int buffSize = 0;
    int ch, len = 0;
    char *str = buff;

    while ((ch = getchar()) != '\0') {
        if (ch == '\n' || ch == EOF) {
            ch = '\0';
        }
        if (len >= buffSize) {
            buffSize += BUFFER;
            buff = realloc(buff, buffSize);
            if (buff == NULL) {
                return NULL;
            }
            str = buff + len;
        }
        *str++ = ch;
        len++;
    }
    str = (char *)malloc((len + 1) * sizeof(char));
    if (str == NULL) {
        return NULL;
    }
    strcpy(str, buff);
    return str;
}