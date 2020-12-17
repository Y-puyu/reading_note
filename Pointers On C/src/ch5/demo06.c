#include <stdio.h>

void set(char bit[], int n) {
    bit[n] |= 1 << n;
}

void clear(char bit[], int n) {
    bit[n] &= ~(1 << n);
}

void assign(char bit[], int n, int value) {
    if (!value)
        set(bit, n);
    else
        clear(bit, n);
}

int test(char bit[], int n) {
    if (bit[n] & 1)
        return 1;
    return 0;
}

int main() {
    char bit[33] = "10010111111111111111111111111010";   // 2550136832

}