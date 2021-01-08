#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#define TRUE 1
#define FALSE 0
#define TRIALS 10000
    int
    main(int ac, char **av)
{
    int
        n_students = 30;
    int
        *birthdays;
    int
        test;
    int
        match;
    int
        total_matches = 0;
    /*
** See how many students in the class (default 30).
*/
    if (ac > 1)
    {
        n_students = atoi(av[1]);
        assert(n_students > 0);
    }
    /*
** Seed the random number generator.
*/
    srand((unsigned int)time(0));
    /*
** Allocate an array for the students’ birthdays.
*/
    birthdays = (int *)malloc(n_students * sizeof(int));
    assert(birthdays != NULL);
    /*
** Run the tests a bunch of times!
*/
    for (test = 0; test < TRIALS; test += 1)
    {
        int
            i;
        /*
** Generate the birthdays and check for matches.
*/
        match = FALSE;
        for (i = 0; i < n_students && !match; i += 1)
        {
            int
                j;
            /*** Generate the next birthday.
*/
            birthdays[i] = rand() % 365;
            /*
** See if it matches any of the existing
** ones; quit as soon as we find a match.
*/
            for (j = 0; !match && j < i; j += 1)
                if (birthdays[i] == birthdays[j])
                    match = TRUE;
        }
        /*
** Count the results.
*/
        if (match)
            total_matches += 1;
    }
    printf("The odds of any two people in a group of %d\n"
           "having the same birthday are %g\n",
           n_students,
           (double)total_matches / TRIALS);
    free(birthdays);
}