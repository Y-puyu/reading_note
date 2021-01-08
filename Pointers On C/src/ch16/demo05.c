/*
** Read a month, day, and year from the command line and determine the day of
** the week for that date.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char *month[] = {"January", "February", "March", "April", "May", "June",
                "July", "August", "September", "October", "November", "December"};
char *day[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
              "Friday", "Saturday"};
int main(int ac, char **av) {
    struct tm tm;
    if (ac != 4) {
        fputs("Usage: day_of_seek month day year\n", stderr);
        exit(EXIT_FAILURE);
    }
    /*
** Store the arguments in the struct tm variable.
*/
    tm.tm_sec = 0;
    tm.tm_min = 0;
    tm.tm_hour = 12;
    tm.tm_mday = atoi(av[2]);
    tm.tm_mon = atoi(av[1]) - 1;
    tm.tm_year = atoi(av[3])- 1900;
    tm.tm_isdst = 0;
    /*
** Normalize it, then print the answer.
*/
    mktime(&tm);
    printf("%s %d, %d is a %s\n", month[tm.tm_mon], tm.tm_mday,
           tm.tm_year + 1900, day[tm.tm_wday]);
    return EXIT_SUCCESS;
}