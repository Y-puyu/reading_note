#include <stdio.h>

void matrix_multiply(int *a, int *b, int *r, int x, int y, int z) {
    int *m1p, *m2p;
    for (int i = 0; i < x; i ++ ) {     // 遍历 a 的行
        for (int j = 0; j < z; j ++) {  // 遍历 b 的列
            m1p = a + i * y;            // 选择 a 矩阵的第 i 行元素。跳过前 i*y 个元素
            m2p = b + j;                // 选择 b 矩阵的第 j 列元素。跳过前 j 个元素即可
            *r = 0;                     // 当前位置清空
            for (int k = 0; k < y; k ++) {  // y 次乘积之和为当前位置元素值大小，
                *r += *m1p * *m2p;
                m1p++;                  // 每次加 1 个到下一列
                m2p += z;               // 每次跳过 z 个到下一行
            }
            r++;                        // 且为行主序遍历，每次 r ++ 即可
        }
    }
}


int main() {
    int a[3][2] = {{2, -6}, {3, 5}, {1, -1}};
    int b[2][4] = {{4, -2, -4, -5}, {-7, -3, 6, 7}};
    int x = 3, y = 2, z = 4;
    int r[x][z];
    matrix_multiply(a, b, r, x, y, z);

    for (int i = 0; i < x; i ++) {
        for (int j = 0; j < z; j ++) {
            printf("%d ", r[i][j]);
        }
        puts("");
    }
    return 0;
}

/*
50 14 -44 -52
-23 -21 18 20
11 1 -10 -12
*/