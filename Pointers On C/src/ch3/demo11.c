#include <stdio.h>

int main() {
    int a = 10;
    auto int b = 20;
    auto c = 30;    // 自动变量，只能为整形
    auto d = 2.1;
    
    // 若d变量格式化为 %f 则输出0，缺省变量类型默认为int
    printf("%d %d %d %d", a, b, c, d); // 10 20 30 2
    return 0;
}