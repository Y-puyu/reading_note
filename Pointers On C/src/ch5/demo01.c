#include <stdio.h>

int main() {
    int a = 1, b = 2;

    printf("%d\n", sizeof(a = a + b));  // 4
    printf("%d %d\n", a, b);  // 1 2

    int	i = 10;
	i = i-- - --i * ( i = -3 ) * i++ + ++i;
	printf( "i = %d\n", i );    // i = 36

    return 0;

}