#include <stdio.h>

// static 变量不能在别的文件中声明后直接使用，仅在本文件中有效
// static int X = 10;   
// static int Y = 20;

int X = 10;
int Y = 20;

int max();

int main() {
    int result;
    result = max();
    printf("%d\n",result);
    return 0;
}

// gcc demo10.c demo09.c -o demo10.exe
// 20