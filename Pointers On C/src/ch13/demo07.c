#if 0

/*
** Parse the command line arguments for processing by the caller’s functions.
*/
#define TRUE 1
#define FALSE 0
#define NULL 0
#define NUL ’\0’
enum
{
    NONE,
    FLAG,
    ARG
};
/*
** Determine whether the argument is a flag or one that requires a value.
*/
argtype(register int ch, register int control)
{
    while (*control != NUL)
        if (ch == *control++)
            return *control == ’+’ ? ARG : FLAG;
    return NONE;
}
/*
** Process the arguments.
*/
char **
do_args(int ac, reg char **av, char *control,
        void (*do_arg)(int, char *), void (*illegal_arg)(int))
{
    register char *argp;
    register int ch;
    register int skip_arg;
    while ((argp = *++av) != NULL && *argp == ’–’ )
    {
        skip_arg = FALSE;
        while (!skip_arg && (ch = *++argp) != NUL)
        {
            switch (argtype(ch, control))
            {
            case FLAG:
                (*do_arg)(ch, NULL);
                break;
            case ARG:
                if (*++argp != NUL || (argp = *++av) != NULL)
                {
                    (*do_arg)(ch, argp);
                    skip_arg = TRUE;
                    break;
                }
                (*illegal_arg)(ch);
                return av;
            case NONE:
                (*illegal_arg)(ch);
                break;
            }
        }
    }
    return av;
}

#endif