/*
** Store a value in an arbitrary field in an integer.
*/
#include <limits.h>

#define INT_BITS (CHAR_BIT * sizeof(int))

int store_bit_field(int original_value, int value_to_store, unsigned starting_bit, unsigned ending_bit) {
    unsigned mask;
    /*
** Validate the bit parameters. If an error is found, do nothing. This
** is not great error handling.
*/
    if (starting_bit < INT_BITS && ending_bit < INT_BITS && starting_bit >= ending_bit) {
        /*
** Construct the mask, which is unsigned to ensure that we get a
** logical, not arithmetic shift.
*/
        mask = (unsigned)-1;
        mask >>= INT_BITS - (starting_bit - ending_bit + 1);
        mask <<= ending_bit;
        /*
** Clear the field in the original value.
*/
        original_value &= ~mask;
        /*
** Shift the value to store to the right position
*/
        value_to_store <<= ending_bit;
        /*
** Mask excess bits off of the value, and store it.
*/
        original_value |= value_to_store & mask;
    }
    return original_value;
}

