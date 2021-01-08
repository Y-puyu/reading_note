#include <stdio.h>
#include <stdlib.h>
int main() {
    char buffer[512];
 
    while (fgets(buffer, 512, stdin) != NULL) {
        char *bp;
        int members;
        long sum;
        long age;

        sum = 0;
        members = 0;
        bp = buffer;
        while ((age = strtol(bp, &bp, 10)) > 0) {
            members += 1;
            sum += age;
        }
        if (members == 0) continue;
        
         printf("%5.2f: %s", (double)sum / members, buffer);
    }
}