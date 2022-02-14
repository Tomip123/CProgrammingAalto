#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "source.c"
#include "source.h"

int main(void)
{
    char *str = malloc(7);
    strcpy(str, "Aatami");

    str = mystrcat(str, "Beetami");
    printf("%s\n", str);
    free(str);

    return 0;
}
