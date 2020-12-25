#include <stdio.h>

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