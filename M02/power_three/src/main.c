#include <stdio.h>

int square(int base)
{
    int res = base * base;
    return res;
}

int powerthree(int base)
{
    int res = base * base * base;
    return res;
}

int main(void)
{
    int val = square(3);  // val becomes 9
    int val2 = square(val * 2);  // val2 becomes 18 * 18
    int val3 = square(square(val));  // val3 becomes (9*9) * (9*9)
    int val4 = powerthree(13); // val4 becomes 13 * 13 * 13

    printf("val2: %d  val3: %d  val4: %d\n", val2, val3, val4);
    return 0;
}