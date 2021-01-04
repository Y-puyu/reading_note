/*
** This program computes a checksum for each of the specified input files. The
** result is printed either to the standard output, or to a file.
*/
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
    /*
** 
Output option flag
*/
    char
        file_output = FALSE;
/*
** 
Function prototypes
*/
char
    **
    do_args(char **);
unsigned short process(FILE *);
void print(unsigned short, char *);
/*
** 
Main function. Parse arguments and process each file specified.
*/
main(int ac, char **av)
{
    FILE
        *f;
    /* stream to read from */
    unsigned short sum;
    /* checksum value */
    /*
** Process option arguments. do_args returns a pointer to the first
** file name in the argument list.
*/
    av = do_args(av);
    /*
** Process the input files.
*/
    if (*av == NULL)
    {
        /*
** No files were given, so read the standard input.
*/
        if (file_output)
        {
            fprintf(stderr, "–f illegal with standard input\n");
            exit(EXIT_FAILURE);
        }
        sum = process(stdin);
        print(sum, NULL);
    }
    else
        /*
** For each file given: open it, process its contents, and print
** the answer.
*/
        for (; *av != NULL; ++av)
        {
            f = fopen(*av, "r");
            if (f == NULL)
                perror(*av);
            else
            {
                sum = process(f);
                fclose(f);
                print(sum, *av);
            }
        }
    return EXIT_SUCCESS;
}
/*
** 
Process a file by reading its contents, character by character, and
** 
calling the appropriate summing function.
*/
unsigned short
process(FILE *f)
{
    unsigned short sum;
    /* current checksum value */
    int
        ch;
    /* current char from the file */
    sum = 0;
    while ((ch = getc(f)) != EOF)
        sum += ch;
    return sum;
}
/*
** 
Print the checksum. This either goes to the standard output or to a
** 
file whose name is derived from the input file name.
*/
void print(unsigned short sum, char *in_name)
{
    char
        *out_name;
    /* name of output file */
    FILE
        *f;
    /* stream for opening output file */
    if (!file_output)
        printf("%u\n", sum);
    else
    {
        /*
** Allocate space to hold output file name. It needs to be 5
** bytes longer than input name to hold ".cks" and the
** terminating NUL byte.
*/
        out_name = malloc(strlen(in_name) + 5);
        if (out_name == NULL)
        {
            fprintf(stderr, "malloc: out of memory\n");
            exit(EXIT_FAILURE);
        }
        strcpy(out_name, in_name);
        strcat(out_name, ".cks");
        f = fopen(out_name, "w");
        if (f == NULL)
            perror(out_name);
        else
        {
            fprintf(f, "%u\n", sum);
            fclose(f);
        }
        free(out_name);
    }
}
/*
** 
Process option arguments. Return a pointer to the first nonoption
** 
argument, which is the beginning of the list of file names.
*/
char **
do_args(char **av)
{
    /*
** Look at each command line argument, one by one.
*/
    while (*++av != NULL && **av == '–' )
    {
        /*
** Look at each character in each argument, one by one.
*/
        while (*++*av != '\0' )
        {
            /*
** Record each option that was given.
*/
            switch (**av)
            {
            case 'f':
                file_output = TRUE;
                break;
            default:
                fprintf(stderr, "Illegal option: %c\n", **av);
                break;
            }
        }
    }
    /*
** Value to be returned is the pointer to the place in the argument list
** just after the options ended.
*/
    return av;
}