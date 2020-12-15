#include <stdio.h>

int main() {
    while (hungry())
        eat_hamburger();

    do {
        eat_hamburger();
    } while (hungry());

    return 0;
}