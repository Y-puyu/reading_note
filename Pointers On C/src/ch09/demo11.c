#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    const char token[] = " \n\r\f\t\v";
    int count = 0;

    char buff[101];
    while (gets(buff)) {
        char *word;
        for (word = strtok(buff, token); word != NULL; word = strtok(NULL, token)) 
            if (strcmp(word, "the") == 0)
                count++;
    }
    return count;
}