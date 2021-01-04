/*
** Compute the average age of family members. Each line of input is for one
** family; it contains the ages of all family members.
*/
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 512
    /* size of input buffer */
    int main() {
    char buffer[BUFFER_SIZE];
    /*
** Get the input one line at a time.
*/
    while (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
        int age[10];
        int members;
        int sum;
        int i;
        /*
** Decode the ages, remembering how many there were.
*/
        members = sscanf(buffer, "%d %d %d %d %d %d %d %d %d %d",
                         age, age + 1, age + 2, age + 3, age + 4, age + 5, age + 6,
                         age + 7, age + 8, age + 9);
        if (members == 0)
            continue;
        /*
** Compute the average and print the results.
*/
        sum = 0;
        for (i = 0; i < members; i += 1)
            sum += age[i];
        printf("%5.2f: %s", (double)sum / members, buffer);
    }
}