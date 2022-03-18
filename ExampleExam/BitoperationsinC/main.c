#include <stdlib.h>
#include <stdio.h>

/*
Implement the following function that
goes through n bytes starting from address buffer, and sets bit number 
bit in each of the bytes. The most significant bit is numbered 7, and 
the least significant bit is numbered 0.
*/
void set_bit(unsigned char *buffer, unsigned int n, int bit)
{
    unsigned int i;
    for (i = 0; i < n; i++)
    {
        buffer[i] |= 1 << bit;
    }
}

// implement also the main function that tests the functionality of 
// the function you implemented above by 
// at least three different parameter combinations
int main(void)
{
    unsigned char buffer[3] = {0x00, 0x00, 0x00};
    set_bit(buffer, 3, 0);
    printf("%x %x %x\n", buffer[0], buffer[1], buffer[2]);
    set_bit(buffer, 3, 1);
    printf("%x %x %x\n", buffer[0], buffer[1], buffer[2]);
    set_bit(buffer, 3, 2);
    printf("%x %x %x\n", buffer[0], buffer[1], buffer[2]);
    set_bit(buffer, 3, 3);
    printf("%x %x %x\n", buffer[0], buffer[1], buffer[2]);
    set_bit(buffer, 3, 4);
    printf("%x %x %x\n", buffer[0], buffer[1], buffer[2]);
    set_bit(buffer, 3, 5);
    printf("%x %x %x\n", buffer[0], buffer[1], buffer[2]);
    set_bit(buffer, 3, 6);
    printf("%x %x %x\n", buffer[0], buffer[1], buffer[2]);
    set_bit(buffer, 3, 7);
    printf("%x %x %x\n", buffer[0], buffer[1], buffer[2]);
    return 0;
}