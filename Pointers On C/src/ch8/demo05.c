#include <stdio.h>

int identity_matrix(int a[][10]) {
    int i = 0;
    for (int i = 0; i < 10; ++i) 
        if (!a[i][i])
            return 0;
    return 1;
}

int main() {
    int a[10][10];
    if (identity_matrix(a))
        puts("YES");
    else
        puts("NO");
    return 0;
}