#if 0

/*
** Insert a word into a concordance list. The arguments are a pointer to the
** location that points to the first node in the list, and a string containing
** the word to be inserted. The function returns TRUE if the string begins with
** a letter and was inserted into the list, else FALSE.
*/
#include <ctype.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
/*
** Declaration for the secondary node that holds an individual word.
*/
typedef struct WORD
{
    char *word;
    struct WORD *next;
} Word;
/*
** Declaration for the primary node that heads a list of words.
*/
typedef struct LIST
{
    char letter;
    struct LIST *next;
    Word *word_list;
} List;
int concordance_insert(List **listp, char *the_word)
{
    int first_char;
    List *current_list;
    Word *current_word;
    Word **wordp;
    int comparison;
    Word *new_word;
    /*
** Get the first character of the word and make sure it is valid.
*/
    first_char = *the_word;
    if (!islower(first_char))
        return FALSE;
    /*
** First, find the word list that begins with the right letter. If it
** does not exist, create a new one and add it.
*/
    while ((current_list = *listp) != NULL && current_list–> letter < first_char)
        listp = &current_list–> next;
    /*
** If current_list is NULL or points to a node with a letter larger
** than what we want, we’ve got to create a new word list and insert it
** here in the primary list.
*/
    if (current_list == NULL || current_list–> letter > first_char)
    {
        List *new_list;
        new_list = (List *)malloc(sizeof(List));
        if (new_list == NULL)
            return FALSE;
        new_list–> letter = first_char;
        new_list–> word_list = NULL;
        new_list–> next = current_list;
        *listp = new_list;
        current_list = new_list;
    }

    /*
** current_list now points to the node that heads the proper word list.
** Search down through it looking for our word.
*/
    wordp = &current_list–> word_list;
    while ((current_word = *wordp) != NULL)
    {
        comparison = strcmp(current_word–> word, the_word);
        if (comparison >= 0)
            break;
        wordp = &current_word–> next;
    }
    /*
** If current_word not NULL and comparison is 0, the word already is in
** the list.
*/
    if (current_word != NULL && comparison == 0)
        return FALSE;
    /*
** Create a new node for the word.
*/
    new_word = (Word *)malloc(sizeof(Word));
    if (new_word == NULL)
        return FALSE;
    new_word–> word = malloc(strlen(the_word) + 1);
    if (new_word–> word == NULL)
        return;
    strcpy(new_word–> word, the_word);
    /*
** Link the new node into the list.
*/
    new_word–> next = current_word;
    *wordp = new_word;
    return TRUE;
}

#endif 