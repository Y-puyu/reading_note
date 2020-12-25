#include <stdio.h>
#include <string.h>

/*
** Convert a numeric value to words.
*/
static char *digits[] = {
    "", "ONE ", "TWO ", "THREE ", "FOUR ", "FIVE ", "SIX ", "SEVEN ",
    "EIGHT ", "NINE ", "TEN ", "ELEVEN ", "TWELVE ", "THIRTEEN ",
    "FOURTEEN ", "FIFTEEN ", "SIXTEEN ", "SEVENTEEN ", "EIGHTEEN ",
    "NINETEEN "};

static char *tens[] = {
    "", "", "TWENTY ", "THIRTY ", "FORTY ", "FIFTY ", "SIXTY ", "SEVENTY ",
    "EIGHTY ", "NINETY "};

static char *magnitudes[] = {
    "", "THOUSAND ", "MILLION ", "BILLION "};
/*
** Convert the last 3–digit group of amount to words. Amount is the value
** to be converted, buffer is where to put the words, and magnitude is the
** name of the 3–digit group we’re working on.
*/

static void do_one_group(unsigned int amount, char *buffer, char **magnitude) {
    int value;

/*
** Get all the digits beyond the last three. If we have any value
** there, process those digits first. Note that they are in the next
** magnitude.
*/
    value = amount / 1000;
    if (value > 0)
        do_one_group(value, buffer, magnitude + 1);         // 处理低三位

/*
** Now process this group of digits. Any hundreds?          // 现在处理这组数字。有几百个吗？
*/
    amount %= 1000;                                         // 将数据缩小到 1000 以内
    value = amount / 100;                                   // 处理百位
    if (value > 0) {
        strcat(buffer, digits[value]);
        strcat(buffer, "HUNDRED ");
    }
    /*
** Now do the rest of the value. If less than 20, treat it as a single  // 现在执行其余的值。如果少于20个，就当作一个单身数字来得到青少年的名字。
** digit to get the teens names.
*/
    value = amount % 100;
    if (value >= 20) {
        /*
** Greater than 20. Do a tens name and leave the units to be           // 大于20。做一个十位数的名字，并留下单位下一页打印
** printed next.
*/
        strcat(buffer, tens[value / 10]);
        value %= 10;
    }
    if (value > 0)
        strcat(buffer, digits[value]);
    /*
** If we had any value in this group at all, print the magnitude.      // 如果我们在这个组中有任何值，打印出数值。
*/
    if (amount > 0)
        strcat(buffer, *magnitude);
}



void written_amount(unsigned int amount, char *buffer) {
    if (amount == 0)
        /*
** Special case for zero.
*/
        strcpy(buffer, "ZERO ");
    else
    {
        /*
** Store an empty string in the buffer, then begin.                 // 在缓冲区中存储一个空字符串，然后开始。
*/
        *buffer = '\0';
        do_one_group(amount, buffer, magnitudes);
    }
}

int main() {
    char buff[1024];
    do_one_group(16312, buff, magnitudes);
    printf("%s\n", buff);       // ?rSIXTEEN THOUSAND THREE HUNDRED TWELVE          npnp!
    return 0;
}