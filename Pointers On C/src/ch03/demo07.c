#include <stdio.h>

int main() {
    int a = 0;
    int b = 9;
    goto end;
    printf("a = %d\n", a);  // 将被忽略掉
    end:
    printf("b = %d\n", b);  // 仅打印9
    return 0;
}