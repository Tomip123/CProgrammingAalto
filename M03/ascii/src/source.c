#include "source.h"

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void ascii_chart(char min, char max)
{
    // output: 28 0x1c ?
    
    char c;
    int i = 1;
    for (c = min; c <= max; c++)
    {
        
        printf("%3d 0x%02x %c", c, c, isprint(c) ? c : '?');
        // print \n after every 4 characters
        if (i++ % 4 == 0) printf("\n");
        else printf("\t");
    }
}
