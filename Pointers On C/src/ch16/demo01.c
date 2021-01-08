#include <stdio.h>
#include <stdlib.h>

int main() {
    for (int i = 0; i < 100; i ++ ) 
        printf("%d ", rand() % 2);
    return 0;
}

#if 0
1 1 1 0 0 0 0 0 1 1 0 1 0 0 1 1 1 1 0 0 1 1 1 1
0 1 1 0 0 1 1 0 0 1 0 1 1 1 1 1 1 0 1 0 1 1 0 1 
0 1 1 1 0 0 0 0 0 0 0 1 0 0 1 0 1 1 1 0 0 1 0 1 
1 1 1 0 1 0 1 1 1 0 1 1 1 1 1 0 1 0 0 1 1 0 0 0 
0 1 0 0
#endif