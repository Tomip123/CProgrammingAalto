#include "source.h"
#include <stdio.h>

void printcounts(int min, int max, const unsigned int *counts)
{
    for (int i = min; i <= max; i++)
    {
        printf("%c: %u  ---  ", i, counts[i]);
        if ((i - min + 1) % 6 == 0)
            printf("\n");
    }
}

void printarray(const char *array)
{
    printf("{ ");
    while (*array)
    {
        printf("'%c',", *array);
        array++;
    }
    printf("0 }");
}

int main(void)
{
    unsigned int counts[256] = {0};

    char sample[] = {'a', 'b', 'r', 'a', 'c', 'a', 'd', 'a', 'b', 'r', 'a', 0};

    printarray(sample);
    countchars(sample, counts);
    printf("\n");
    printcounts('a', 'e', counts);

    return 0;
}
