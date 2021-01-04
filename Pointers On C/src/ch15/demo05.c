/*
** This program reads two file names and then copies data from the input file
** to the output file one line at a time.
*/
#include <stdio.h>
#define BUFSIZE 256
/* I/O buffer size */
/*
** 
This function prompts for a filename, reads the name, and then tries to
** 
open the file. Any errors encountered are reported before the program
** 
terminates. Note that the gets function strips the trailing newline off
** 
of the file name so we don’t have to do it ourselves.
*/
FILE *openfile(char *prompt, char *mode) {
    char buf[BUFSIZE];
    FILE *file;
    printf("%s filename? ", prompt);

    if (gets(buf) == NULL) {
        fprintf(stderr, "Missing %s file name.\n", prompt);
        exit(0);
    }

    if ((file = fopen(buf, mode)) == NULL) {
        perror(buf);
        exit(0);
    }
   
    return file;
}
/*
** 
Main function.
*/
int main() {
    char buf[BUFSIZE];
    FILE *input;
    FILE *output;
    FILE *openfile();
    
    input = openfile("Input", "r");
    output = openfile("Output", "w");
    
    while (fgets(buf, BUFSIZE, input) != NULL)
        fputs(buf, output);
    
    fclose(input);
    fclose(output);
 
    return 0;
}

