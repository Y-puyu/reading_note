/*
** Determine whether or not an integer value is a palindrome.
*/
/*
** 
Prototype for the string palindrome function from chapter 9.
*/
extern int palindrome(char *string);
int numeric_palindrome(int value) {
    char string[50];
    /*
** Convert the number to a string and then check the string!
*/
    sprintf(string, "%d", value);
    return palindrome( string );
}