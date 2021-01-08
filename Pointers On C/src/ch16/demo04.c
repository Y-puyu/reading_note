#include <time.h>
#include <stdlib.h>
#include <stdio.h>
int main() {
    time_t now;
    struct tm *t;
    int hour;
    int minute;

    now = time(NULL);
    t = localtime(&now);
    hour = t->tm_hour;
    minute = t->tm_min;

    if (minute >= 30)
        hour += 1;
    hour %= 12;
    if (hour == 0)
        hour = 12;
    minute += 2;
    minute /= 5;
    if (minute == 0)
        minute = 12;
    printf("The big hand is on the %d, and the little hand is on the %d.\n",
           minute, hour);
    return EXIT_SUCCESS;
}