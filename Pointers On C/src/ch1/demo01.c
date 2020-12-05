#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int a = 144;
    printf("    %d\n", printf("%d", a));    // 想得到的骚操作之一   144    3

    printf("\033[1m\033[45;33m HELLO_WORLD \033[0m\n");     // 粉色底色，黄字的 HELLO_WORLD
    
    // 有关格式化，来源于 http://www.cplusplus.com/reference/cstdio/printf/?kw=printf
    printf ("Characters: %c %c \n", 'a', 65);
    printf ("Decimals: %d %ld\n", 1977, 650000L);
    printf ("Preceding with blanks: %10d \n", 1977);
    printf ("Preceding with zeros: %010d \n", 1977);
    printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
    printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
    printf ("Width trick: %*d \n", 5, 10);          // *有点秀，没怎么遇见过，限制宽度
    printf ("%s \n", "A string");

    char str1[15];
    for (int i = 0; i < 10; ++i)
        scanf("%c", &str1[i]);

    printf("%s\n", str1);

    char str2[15];
    strcpy(str2, str1);
    printf("%s\n", str2);

    char str3[30];
    strcat(str1, str2);         // 在 str1 后面追加 str2
    printf("%s\n", str1);

    return 0;
}