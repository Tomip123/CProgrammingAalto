#include <stdio.h>
#include "source.h"

int main(void)
{
    printf("%02x\n", sixBits(0xDF));
    printf("%02x\n", sixBits(0x8D));
    printf("%02x\n", sixBits(0x28));
    return 0;
}
