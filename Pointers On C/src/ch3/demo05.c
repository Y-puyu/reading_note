#include <stdio.h>

int main() {
    int a = 1;

    int *b = &a;
    printf("%d\n", *b);     // 1
    a = 2;
    printf("%d\n", *b);     // 2
    
    int const *c = &a;
    printf("%d\n", *c);     // 2
    a = 3;
    printf("%d\n", *c);     // 3
    int aa = 10;
    c = &aa;
    printf("%d\n", *c);     // 10
    // *c = 15;     // 报错，c指向的值不能修改
    
    int *const d = &a;
    printf("%d\n", *d);     // 3
    int dd = 20;
    // d = &dd;    // 报错，d中保存的地址不能被修改
    *d = 20;                // *d其实指向的就是a的值，在此就将a的值修改为20了
    printf("%d\n", *d);     // 20

    int const *const e = &a;
    printf("%d\n", *e);     // 20

    return 0;
}