#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// 判断不可打印字符，是可打印函数的负值...挺好的想法，曲线救国。避免了特殊情况的处理
int is_not_printf(int ch) {
    return !isprint(ch);
}

// 初始化转移表，均为函数名，即函数指针。转移表就是一个函数指针数组
static int (*test_func[])(int) = {
    iscntrl,
    isspace,
    isdigit,
    islower,
    isupper,
    ispunct,
    is_not_printf
};

// 宏，计算转移表元素数量
#define N_CAREGORIES (sizeof(test_func) / sizeof(test_func[0]))

char *label[] = {
    "control",
    "whitespace",
    "digit",
    "lower case",
    "upper case",
    "punctuation",
    "non-printable"
};

int count[N_CAREGORIES];
int total;

int main() {
    int ch;
    int category;

    while ((ch = getchar()) != EOF) {
        total += 1;
        for (category = 0; category < N_CAREGORIES; category ++ ) {
            if (test_func[category](ch))
                count[category] += 1;
        }
    }

    if (total == 0) {
        printf("No characters in the input!\n");
    }
    else {
        for (category = 0; category < N_CAREGORIES; category ++ ) {
            printf("%3.0f%% %s characters\n", count[category] * 100.0 / total, label[category]);
        }
    }
    return 0;
}

/* 
 * 拿本代码做实验！！！
  5% control characters
 30% whitespace characters
  1% digit characters
 47% lower case characters
  5% upper case characters
 17% punctuation characters
  5% non-printable characters
*/ 