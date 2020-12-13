#include <stdio.h>
#include <stdlib.h>

int main() {
    int t = 0;
    char c;

    while ((c = getchar()) != EOF) {   // 回车 Ctrl+z 回车等于EOF。linux下直接Ctrl+d
        if (c == '{')
            t += 1;
        if (c == '}')
            if (t == 0)
                puts("error");
            else
                t -= 1;
    }
    if (t > 0)
        puts("error1");
    return 0;
}