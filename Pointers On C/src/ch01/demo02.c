#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int ch, line = 0, flag = 1;
    
    // c标准没有bool这个类型...
    // getline是C++标准库函数，不是C标准库的
    // #define EOF (-1)
    while ((ch = getchar()) != EOF) {
        if (flag) {
            flag = 0;
            line += 1;
            printf("%d ", line);
        }
        putchar(ch);
        if (ch == '\n')
            flag = 1;


    }
    return 0;
}