#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1005

int main() {
    char input[N];
    int len;
    char res[N];
    int res_len = -1;

    int cnt = 0;        // 简单测 5 个样例
    while (gets(input) != NULL && cnt != 5) {
        len = strlen(input);
        if (len > res_len) {
            res_len = len;
            strcpy(res, input);
        }

        ++cnt;
    }

    if (res_len >= 0)
        puts(res);

    return 0;
}