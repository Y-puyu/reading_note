/* 
11.
** GENERIC implementation of a stack with a static array. The array size is
** given as one of the arguments when the stack is instantiated.
*/
#include <assert.h>
/*
** Interface
**
** 
This macro declares the prototypes and data types needed for a stack of
** 
one specific type. It should be invoked ONCE (per source file) for each
** 
different stack type used in that source file. The suffix is appended
** 
to each of the function names; it must be chosen by the user so as to
** 
give unique names for each different type used.
*/
#define GENERIC_STACK_INTERFACE(STACK_TYPE, SUFFIX)                                     \
            typedef struct {                                                            \
                STACK_TYPE *stack;                                                      \
                int top_element;                                                        \
                int stack_size;                                                         \
            } STACK##SUFFIX;                                                            \
            void push##SUFFIX(STACK##SUFFIX *stack, STACK_TYPE value);                  \
            void pop##SUFFIX(STACK##SUFFIX *stack);                                     \
            STACK_TYPE top##SUFFIX(STACK##SUFFIX *stack);                               \
            int is_empty##SUFFIX(STACK##SUFFIX *stack);                                 \
            int is_full##SUFFIX(STACK##SUFFIX *stack);
/*
** Implementation
**
** 
This macro defines the functions to manipulate a stack of a specific
** 
type. It should be invoked ONCE (per entire program) for each different
** 
stack type used in the program. The suffix must be the same one used in
** 
the interface declaration.
*/
#define GENERIC_STACK_IMPLEMENTATION(STACK_TYPE, SUFFIX)                        \
        void push##SUFFIX(STACK##SUFFIX *stack, STACK_TYPE value) {             \
            assert(!is_full##SUFFIX(stack));                                    \
            stack-> top_element += 1;                                           \
            stack-> stack[stack-> top_element] = value;                         \
        }                                                                       \
        void pop##SUFFIX(STACK##SUFFIX *stack) {                                \
            assert(!is_empty##SUFFIX(stack));                                   \
            stack-> top_element -= 1;                                           \
        }                                                                       \
        STACK_TYPE top##SUFFIX(STACK##SUFFIX *stack) {                          \
            assert(!is_empty##SUFFIX(stack));                                   \
            return stack-> stack[stack-> top_element];                          \
        }                                                                       \
        int is_empty##SUFFIX(STACK##SUFFIX *stack) {                            \
            return stack-> top_element == -1;                                   \
        }                                                                       \
        int is_full##SUFFIX(STACK##SUFFIX *stack) {                             \
            return stack-> top_element == stack-> stack_size - 1;               \
        }                                                                           
/*
** Stacks
**
** 
This macro creates the data needed for a single stack. It is invoked
** 
once per stack. NAME is the name by which you refer to the stack in
** 
subsequent function calls, and STACK_SIZE is the size you want the stack
** 
to be. STACK_TYPE is the type of data stored on the stack, and the
** 
SUFFIX must be the same one given in the interface declaration for this
** 
STACK_TYPE.
*/
#define GENERIC_STACK(NAME, STACK_SIZE, STACK_TYPE, SUFFIX)                    \
        static STACK_TYPE NAME##stack[STACK_SIZE];                             \
        STACK##SUFFIX NAME = {NAME##stack, -1, STACK_SIZE};