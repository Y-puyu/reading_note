/*
** A stack implemented with a dynamically allocated array. The array size is
** given when create is called, which must happen before any other stack
** operations are attempted.
*/
#include "demo04.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/*
** 
The maximum number of stacks handled by the module. This can be changed
** 
only by recompiling the module.
*/
#define N_STACKS 10

/*
** 
This structure holds all the information for one stack: the array that
** 
holds the values, its size, and a pointer to the topmost value.
*/
typedef struct
{
    STACK_TYPE
    *stack;
    size_t
        size;
    int
        top_element;
} StackInfo;
/*
** 
Here are the actual stacks.
*/
StackInfo
    stacks[N_STACKS];
/*
** 
create_stack
*/
void create_stack(size_t stack, size_t size)
{
    assert(stack < N_STACKS);
    assert(stacks[stack].size == 0);
    stacks[stack].size = size;
    stacks[stack].stack =
        (STACK_TYPE *)malloc(size * sizeof(STACK_TYPE));
    assert(stacks[stack].stack != NULL);
    stacks[stack].top_element = -1;
}
/*
** 
destroy_stack
*/
void destroy_stack(size_t stack)
{
    assert(stack < N_STACKS);
    assert(stacks[stack].size > 0);
    stacks[stack].size = 0;
    free(stacks[stack].stack);
    stacks[stack].stack = NULL;
}
/*
** 
push
*/
void push(size_t stack, STACK_TYPE value)
{
    assert(!is_full(stack));
    stacks[stack].top_element += 1;
    stacks[stack].stack[stacks[stack].top_element] = value;
}
/*
** 
pop
*/
void pop(size_t stack)
{
    assert(!is_empty(stack));
    stacks[stack].top_element -= 1;
}
/*
** 
top
*/
STACK_TYPE top(size_t stack)
{
    assert(!is_empty(stack));
    return stacks[stack].stack[stacks[stack].top_element];
}
/*
** 
is_empty
*/
int is_empty(size_t stack)
{
    assert(stack < N_STACKS);
    assert(stacks[stack].size > 0);
    return stacks[stack].top_element == -1;
}
/*
** 
is_full
*/
int is_full(size_t stack)
{
    assert(stack < N_STACKS);
    assert(stacks[stack].size > 0);
    return stacks[stack].top_element == stacks[stack].size - 1;
}