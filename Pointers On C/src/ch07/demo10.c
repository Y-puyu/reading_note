#include <stdio.h>
#include <stdarg.h>

void printf(char *format, ...) {
    va_list arg;
    char c;
    char *str;

    va_start(arg, format);

    while ((c = *format++) != '\0') {
        if (c != '%') {
            putchar(c);
            continue;
        }
        switch (*format != '\0' ? *format ++ : '\0')
        {
        case 'd': 
            print_integer(va_arg(arg, int));
            break;
        case 'f':
            print_float(va_arg(arg, float));
            break;
        case 'c':
            putchar(va_arg(arg, int));
            break;
        case 's':
            str = va_arg(arg, char *);
            while (*str != '\0' )
                putchar(*str++);
            break;
        }
    }
}


int main() {
    
}