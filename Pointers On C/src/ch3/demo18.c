#include <stdio.h>

int main() {
    const char *a = "123456789";
    // *(a + 5) = 'a'; // 报错
    puts(a);
}