#include <stdio.h>
#include "bit_sequence.h"
#include "bit_sequence.c


/* Feel free to modify this function to test different things */

int main(void) {

    uint32_t a = 01010101101010100101010110101010;
    uint32_t b = 00000000000100110011000000100110;

    /* op_bit_get_sequence tests */
    printf("\n*** Testing your op_bit_get_sequence function..\n");

    printf("Getting sequence... Should be 0x68, was 0x%02X\n", op_bit_get_sequence(a, b));

    return 0;
}
