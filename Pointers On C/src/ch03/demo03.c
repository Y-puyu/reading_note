#include <stdio.h>
#include <string.h>

int main() {
    enum Day
    {
        a,
        b,
        c = 10,
        d,
        e
    }day;
    
    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);
    printf("%d\n", d);

    puts("");

    printf("%d\n", sizeof day); // 4

    enum {aa, bb, cc, dd, ee} A, B, C;


    return 0;
}

/*
0
1
10
11
*/