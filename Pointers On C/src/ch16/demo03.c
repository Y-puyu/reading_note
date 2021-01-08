/*
** For a given input age, compute the smallest radix in the range 2 – 36 for
** which the age appears as a number less than or equal to 29.
*/
#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av) {
    int age;
    int radix;
    div_t result;
    if (ac != 2) {
        fputs("Usage: age_radix your–age\n", stderr);
        exit(EXIT_FAILURE);
    }
    /*
** Get the age argument.
*/
    age = atoi(av[1]);
    /*
** Find the smallest radix that does the job.
*/
    for (radix = 2; radix <= 36; radix += 1) {
        result = div(age, radix);
        if (result.quot <= 2 && result.rem <= 9)
            break;
    }
    /*
** Print the results.
*/
    if (radix <= 36) {
        printf("Use radix %d when telling your age; "
               "%d in base %d is %d%d\n",
               radix, age, radix, result.quot, result.rem);
        return EXIT_SUCCESS;
    }
    else {
        printf("Sorry, even in base 36 your age "
               "is greater than 29!\n");
    }
    return 0;
}