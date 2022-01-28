#include <stdio.h>
#include "source.h"
#include "source.c"

int main(void)
{
    printf("%02x\n", sixBits(0xf0));
    printf("%02x\n", sixBits(0x8D));
    printf("%02x\n", sixBits(0x28));
    return 0;
}
