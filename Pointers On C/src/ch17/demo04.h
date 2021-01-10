/*
** Interface for a module that manages 10 stacks.
*/
#include <stdlib.h>
#define STACK_TYPE int
    /* Type of value on the stack */
    /*
** push
** 
Pushes a new value on the stack. The first argument selects which
** 
stack, and the second argument is the value to push.
*/
void push(size_t stack, STACK_TYPE value);
/*
** pop
** 
Pops a value off of the selected stack, discarding it.
*/
void pop(size_t stack);
/*
** top
** 
Returns the topmost value on the selected stack without changing the
** 
stack.
*/
STACK_TYPE top(size_t stack);
/*
** is_empty
** 
Returns TRUE if the selected stack is empty, else FALSE
*/
int is_empty(size_t stack);
/*
** is_full
** 
Returns TRUE if the selected stack is full, else FALSE
*/
int is_full(size_t stack);