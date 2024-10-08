#include "bits.h"
#include <stdio.h>
#include <stdlib.h>

/* DESCRIPTION:
 * ------------
 * The function clears a bit with index i (makes the bit active (1)) in the argument
 * data.
 *
 * You do not need to handle any invalid parameters.
 *
 * PARAMETERS:
 * ------------
 * uint32_t data: an array of binary data.
 * int i: the index of the bit.
 *
 * RETURNS:
 * ------------
 * modified data.
 *
 */
uint32_t op_bit_set(uint32_t data, int i)
{
    uint32_t mask = 1 << i;
    data = data | mask;
    return data;
}


/* DESCRIPTION:
 * ------------
 * The function clears a bit with index i (makes the bit inactive (0)) in the argument
 * data.
 *
 * You do not need to handle any invalid parameters.
 *
 * PARAMETERS:
 * ------------
 * uint32_t data: a 32-bit data.
 * int i: the index of the bit.
 *
 * RETURNS:
 * ------------
 * modified.
 *
 */

uint32_t op_bit_clear(uint32_t data, int i)
{
    uint32_t mask = ~(1 << i);
    data = data & mask;
    return data;
}

/* DESCRIPTION:
 * ------------
 * The function toggles a bit with index i in the argument
 * data.
 *
 * You do not need to handle any invalid parameters.
 *
 * PARAMETERS:
 * ------------
 * uint32_t data: a 32-bit data.
 * int i: the index of the bit which to set as inactive (0).
 *
 * RETURNS:
 * ------------
 * modified data.
 *
 */

uint32_t op_bit_toggle(uint32_t data, int i)
{
    uint32_t mask = 1 << i;
    data = data ^ mask;
    return data;
}

/* DESCRIPTION:
 * ------------
 * The functions returns 1 or 0 depending on whether the bit with index i in
 * the binary data is set or not.
 *
 * You do not need to handle any invalid parameters.
 *
 * PARAMETERS:
 * ------------
 * uint32_t data: a 32-bit data.
 * int i: the index of the bit which value to return.
 *
 * RETURNS:
 * ------------
 * 0: if the bit was not set.
 * 1: if the bit was set.
 */

int op_bit_get(uint32_t data, int i)
{
    uint32_t mask = 1 << i;
    return (data & mask) >> i;
}

/* DESCRIPTION:
 * ------------
 * The function prints the binary representation of the parameter unsigned char
 * to the standard output as 1s and 0s. Note that one unsigned char is 8 bits.
 * There is no newline at the end of the print.
 *
 * For example:
 *
 * unsigned char b = 0xF8;
 * print_byte(b);
 *
 * Would print out:
 *
 * 11111000
 *
 * PARAMETERS:
 * ------------
 * unsigned char b: the binary sequence.
 *
 * RETURNS:
 * ------------
 * Nothing.
 *
 */

void op_print_byte(unsigned char b)
{
    // declare variables
    int i;
    
    // loop through the bits in the unsigned char
    for (i = 0; i < 8; i++)
    {
        // if the bit is set, print 1
        if (b & 0x80)
        {
            printf("1");
        }
        // otherwise, print 0
        else
        {
            printf("0");
        }
        // shift the unsigned char to the right
        b <<= 1;
    }
}
