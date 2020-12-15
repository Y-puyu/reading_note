#include <stdio.h>

void deblank(char a[]) {
    for (int i = 0, j = 0; a[i] != '\0'; ) {
        int flag = 0;
        while (a[i] != '\0' && a[i] == ' ') flag = 1, i++;
        if (flag)
            a[j++] = ' ';
        a[j++] = a[i++];
    }
}

int main() {
    char a[50] = "  asas  asas  da   ";
    puts(a);
    deblank(a);
    puts(a);
}

#if 0
// 答案代码
void deblank(char *string)
{
    char *dest;
    char *src;
    int ch;
    /*
** Set source and destination pointers to beginning of the string, then
** move to 2nd character in string.
*/
    src = string;
    dest = string++;
    /*
** Examine each character from the source string.
*/
    while ((ch = *src++) != NUL)
    {
        if (is_white(ch))
        {
            /*
** We found white space. If we’re at the beginning of
** the string OR the previous char in the dest is not
** white space, store a blank.
*/
            if (src == string || !is_white(dest[–1]))
                *dest++ = ’ ’;
        }
        else
        {
            /*
** Not white space: just store it.
*/
            *dest++ = ch;
        }
    }
    *dest = NUL;
}
int is_white(int ch)
{
    return ch == ’ ’ || ch == ’\t’ || ch == ’\v’ || ch == ’\f’ || ch == ’\n’ || ch == ’\r’;
}
#endif