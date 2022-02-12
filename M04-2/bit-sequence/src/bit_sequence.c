#include "bit_sequence.h"
#include <stdio.h>
#include <stdlib.h>

/* DESCRIPTION:
 * ------------
 * The function extracts a sequence of bits from the argument data. The indexes
 * of the bits that will be extracted are the set bits in mask.
 *
 * The set bits in mask are copied to an unsigned char variable.
 *
 * For example,
 *
 * data = 0101 0101 1010 1010 0101 0101 1010 1010 = 0x55aa55aa
 * mask = 0000 0000 0001 0011 0011 0000 0010 0110 = 0x00133026
 *                     ^   ^^   ^^        ^   ^^
 * retVal =            0   10   01        1   01  = 0x4d
 *
 *
 * PARAMETERS:
 * ------------
 * uint32_t data: a 32 bit integer that will be operated on
 *
 * uint32_t mask: the bit packed data that indicates the bits to be copied to result
 *
 * RETURNS:
 * ------------
 * The extracted sequence stored in a single unsigned char.
 *
 */

uint8_t op_bit_get_sequence(uint32_t data, uint32_t mask)
{
    uint8_t retVal = 0;
    uint32_t i = 0;
    uint32_t j = 0;
    uint8_t mask_bits[32];

    for (i = 0; i < 32; i++) {
        mask_bits[i] = 0;
    }

    for (i = 0; i < 32; i++) {
        if ((mask >> i) & 0x01) {
            mask_bits[i] = 1;
        }
    }

    for (i = 0; i < 32; i++) {
        if (mask_bits[i] == 1) {
            if ((data >> i) & 0x01) {
                retVal |= 0x01 << j;
            }
            j++;
        }
    }

    return retVal;
}



