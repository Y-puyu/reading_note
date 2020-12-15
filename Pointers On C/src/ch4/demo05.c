#include <stdio.h>

int main() {
    int which_word;
    scanf("%d", &which_word);

    switch (which_word) {
    case 1:
        puts("who");
        break;
    case 2:
        puts("what");
        break;
    case 3:
        puts("when");
        break;
    case 4:
        puts("where");
        break;
    case 5:
        puts("why");
        break;
    default:
        puts("don't know");
        break;
    }
    return 0;
}