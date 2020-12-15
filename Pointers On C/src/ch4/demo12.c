#include <stdio.h>
#include <string.h>

const int N = 129;

int main() {
    int flag = 0;
    char a[N], b[N];
    if (gets(b) != NULL) {
        while (gets(a) != NULL) {
            if (strcmp(a, b) != 0) {    // 如果不匹配，则更新一下字符数组中的元素
                flag = 0;
                strcpy(b, a);    // 把a中字符拷贝到b中
            }
            else if (!flag) {   // 如果匹配成功，并且这个flag是0的话。在此判断flag是为了排除后面还有相同的字符串。
                // 只有失配后，flag=0，再匹配成功时就直接打印了。此时后续如果继续匹配成功则不能打印，flag此时为1
                flag = 1;
                puts(a);
            }
        }
    }
    return 0;
}