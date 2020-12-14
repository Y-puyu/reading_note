#include <stdio.h>

/*
int max(static int a, static int b) {   // 报错，参数类型无效
    return (a > b ? a : b);
}
*/

int max(int a, int b) {  
    return (a > b ? a : b);
}

int main() {
    int a = 10, b = 20;
    int res = max(a, b);
    printf("%d\n", res);    // 20
    return 0;
}