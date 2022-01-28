#include <stdio.h>
#include "source.h"
#include "source.c"

int main(void) {

    printf("%02x\n", mergeBits(58, 114));
    printf("%02x\n", mergeBits(19, 115));
    printf("%02x\n", mergeBits(0x6, 0xD));
    return 0;
}
