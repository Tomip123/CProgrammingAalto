#include "bit_sequence.h"
#include <stdio.h>
#include "bit_sequence.c"

/* Feel free to modify this function to test different things */

int main(void)
{
    /* op_bit_get_sequence tests */
    printf("\n*** Testing your op_bit_get_sequence function..\n");

    printf("Getting sequence... Should be 0x4e, was 0x%02X\n", op_bit_get_sequence(0x55aa55aa, 0x00133026));

    return 0;
}
