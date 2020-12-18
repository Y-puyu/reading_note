#include <stdio.h>

char *match(char *str, char *dst) {
    while (*dst != '\0') 
        if (*str++ != *dst++)
            return NULL;

    return str;         // 返回末尾位置
}


int del_substr(char *str, char const *substr) {
    char *next;
    while (*str != '\0') {
        next = match(str, substr);  
        if (next != NULL)
            break;
        str++;
    }
    if (*str == '\0')
        return 0;
    while (*str++ = *next++)
        ;
    return 1;
}

int main() {
    char str[] = "ABCDEFG";     // 千万别写成 char *str = "ABCDEFG"，这将会是字符串常量，则无法修改
    char substr[] = "CDE";
    int t = del_substr(str, substr);
    printf("%s %s\n", str, substr); // ABFG CDE
    return 0;
}