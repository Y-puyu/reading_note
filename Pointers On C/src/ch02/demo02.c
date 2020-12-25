// 转义字符练习

#include <stdio.h>
#include <string.h>

int main() {
    char *s1 = "123456";
    printf("%s   %d %d\n", s1, sizeof s1, strlen(s1));
    char *s2 = "123\123456";    // 三位八进制
    printf("%s   %d %d\n", s2, sizeof s2, strlen(s2));
    char *s3 = "123\x66 3456";   // 两位十六进制，貌似在这必须得加个空格才能正常显示。且在vs2019下，它是占四个数字...
    printf("%s   %d %d\n", s3, sizeof s3, strlen(s3));
    char *s4 = "123\t456";
    printf("%s   %d %d\n", s4, sizeof s4, strlen(s4));

    char* a = "\u771a";
    printf("c = %s   %d   %d\n", a, sizeof a, strlen(a)); 

/*
char * 是字符指针，sizeof 在 64 位机器上就是 8 字节。也能发现其它
123456   8 6
123S456   8 7
123f 3456   8 9
123     456   8 7
c = 眚   8   2

且曾经遇到过 unicode 编码让求字节数的。这个貌似是两个字节，不太清楚。
具体 Unicode 编码可参考：http://blog.sina.com.cn/s/blog_4b4409c30100vw9t.html
*/

    return 0;
}