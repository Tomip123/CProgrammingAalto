#include "source.h"

#include <stdlib.h>
#include <string.h>

char *mystrcat(char *dest, const char *src)
{
    unsigned int dest_len = strlen(dest);
    unsigned int src_len = strlen(src);
    char *new_dest = realloc(dest, (dest_len + src_len + 1) * sizeof(char));
    strcpy(new_dest + dest_len, src);
    return new_dest;
}


