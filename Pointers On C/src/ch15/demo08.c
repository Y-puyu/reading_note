#include <stdio.h>

int main() {
    int a = 1234;
    char arr[12];
    sprintf(arr, "%d", a);
    a = 12345;
    sprintf(arr, "%d", a);
   for (int i = 0; i < 10; i ++ ) printf("%c ", arr[i]); 
    double b = 123.456;
    sprintf(arr, "%f", b);
    puts(arr);
    for (int i = 0; i < 10; i ++ ) printf("%c ", arr[i]);
    return 0;
}