#pragma once 

#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MALLOC(n, type) ((type*)malloc((n) * sizeof(type)))
#define TEST(format, str1) printf("The value of" format "\n", str1);

#define N 100
#define N 150       // 可以在一个文件内重复定义，且以最后的定义为准

// #undef N         // 取消对 N 的定义

int a[N];

#define M 100

int b[M];


#ifndef M
#endif

#if 0

#if DEBUG
    printf("x=%d, y=%d\n", x, y);
#elif OP1
    printf("OP1\n");
#elif OP2
    printf("OP2\n");
#else
    printf("FALSE\n");
#endif 

#endif 


int main() {
    printf("%s -- %d -- %s -- %s -- %d\n", __FILE__, __LINE__, __DATE__, __TIME__, __STDC__); // demo01.c -- 4 -- Dec 29 2020 -- 12:24:38 -- 1

    char *s = "abc"
              "def";        
    puts(s);        // abcdef  常量字符串自动拼接

    printf("%d\n", sizeof(a) / sizeof(a[0]));   // 150
    printf("%d\n", sizeof(b) / sizeof(b[0]));   // gcc -DM=100 demo01.c  ./a.exe 100  在外部定义宏 M 的值

    #line 666 "11111111---111"
    printf("%s -- %d -- %s -- %s -- %d\n", __FILE__, __LINE__, __DATE__, __TIME__, __STDC__); // 11111111---111 -- 666 -- Dec 29 2020 -- 13:24:36 -- 1

    return 0;
}