#include <stdio.h>
#include "increment.c"      // 这样也可以
#include "negate.c"        // " "是在整个系统下寻找./m该文件

int main( void )
{
    printf( "%d %d\n", increment(10), negate(10));
    printf( "%d %d\n", increment(0), negate(0));
    printf( "%d %d\n", increment(-10), negate(-10));
    return 0;
}