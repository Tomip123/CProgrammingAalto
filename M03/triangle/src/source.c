#include <stdio.h>
#include <math.h>
#include "source.h"

void draw_triangle(unsigned int size)
{
    unsigned int i, j;
    // ....#
    // ...##
    // ..###
    // .####
    // #####

    for (i = 0; i < size; i++) {
        for (j = 0; j < size - i - 1; j++) {
            printf(".");
        }
        for (j = 0; j < i + 1; j++) {
            printf("#");
        }
        printf("\n");
    }
}
